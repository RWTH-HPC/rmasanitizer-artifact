#!/usr/bin/env zsh

set -e

if [ $# -ne 2 ]
then
  echo "Expected two arguments: <BUILD-DIR> <INSTALL-DIR>"
  exit 1
fi

scriptdir="$(dirname $0)"
builddir="$(realpath $1)"
installdir="$(realpath $2)"

echo "Building in: $builddir"
echo "Installing to: $installdir"

mkdir -p $builddir

# Load prerequisites
module purge
module load intel/2023a Clang/16.0.6

# Flang is ready, and already needed for next step
module unload Clang
module use /work/rwth1269/modules
module load Classic-Flang

# Build and install intelmpi bindings
cd "${installdir}" # Source = Install Folder here
mkdir -p impi-bindings
tar xvf ${I_MPI_ROOT}/binding/intel-mpi-binding-kit.tar.gz -C impi-bindings
cd impi-bindings/f90
make MPI_INST=$I_MPI_ROOT F90=flang NAME=f90-flang
