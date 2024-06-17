#!/bin/bash

IMAGE=ubuntu2204-rmasan

set -e

# Need both blazar and openstackclient

echo "This script expects that application credentials have been created in the ChameleonCLoud infrastructure CHI@TACC."
echo "See: https://chameleoncloud.readthedocs.io/en/latest/technical/cli.html#creating-an-application-credential"
echo "It allocates an instance of type compute_zen3."
echo "Please confirm that you created the application credentials (unrestricted) and sourced the openrc file. [yN] "
read answer

if [ "$answer" == "${answer#[Yy]}" ]; then 
    exit 1
fi

if [ -z "$OS_APPLICATION_CREDENTIAL_ID" ]; then
  echo "No credentials in environment! Did you create and source the application credentials (unrestricted)?"
  echo "See: https://chameleoncloud.readthedocs.io/en/latest/technical/cli.html#creating-an-application-credential"
  exit 1
fi

# Timezone?

# Get reservation start and end times
unixtime="$(date '+%s%N')"
curtime="$(date +'%Y-%m-%d %H:%M')"
endtime="$(date +'%Y-%m-%d %H:%M' -d '+12 hour')"

# Reserve compute
echo "Creating reservation..."
compute_lease_name="rmasan_lease_$unixtime"
openstack reservation lease create \
  --reservation min=1,max=1,resource_type=physical:host,resource_properties='["=", "$node_type", "compute_zen3"]',before_end='' \
  --end-date "$endtime" \
  $compute_lease_name
reservation_id="$(openstack reservation lease show $compute_lease_name -f value -c reservations | grep '"id"' | awk '{ print $2 }' | sed -r 's/\"(.*)\".*/\1/')"

# Create keypair
echo "Creating keypair..."
keypair_name="rmasan_keypair_$unixtime"
openstack keypair create $keypair_name --private-key $keypair_name
chmod 0400 $keypair_name

echo "Wait a few seconds for hosts in reservation to become available..."
sleep 60

# Start compute instance
echo "Booting up an instance..."
instance_name="rmasan_instance_$unixtime"
openstack server create $instance_name --flavor baremetal --image $IMAGE --network sharednet1 --hint reservation=$reservation_id --key-name $keypair_name

# Reserve IP
echo "Reserving FIP..."
fip_lease_name="rmasan_fip_$unixtime"
fip_id="$(openstack floating ip create public --description $fip_lease_name -f value -c id)"
fip_addr="$(openstack floating ip show $fip_id -c floating_ip_address -f value)"

echo "Setup complete!"
echo "Lease Name: $compute_lease_name"
echo "Instance Name: $instance_name"
echo "FIP: $fip_addr"

echo "Waiting for instance to come online. This can take a good amount of time..."
while [ "$(openstack server show $instance_name -c status -f value)" != "ACTIVE" ]
do
  sleep 3
done
echo "Server is Online! Logging in... (NOTE: Will take a bit until FIP is available!)"

# Attach IP
echo "Attaching FIP..."
openstack server add floating ip $instance_name $fip_id

# Finally, log into instance
until ssh -o ConnectTimeout=10 -o ServerAliveInterval=30 -o StrictHostKeyChecking=no -i $keypair_name "cc@$fip_addr";
do
    echo "Retrying login (this is normal)"
    sleep 10
done

# Deinit: Remove everything
echo "Deleting acquired resources..."
openstack keypair delete $keypair_name
openstack floating ip delete $fip_id
openstack server delete $instance_name
openstack reservation lease delete $compute_lease_name
rm -f $keypair_name

