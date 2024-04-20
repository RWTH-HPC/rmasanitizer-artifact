# RMASanitizer: Runtime Detection of Data Races in RMA Applications - Supplemental Material

This is supplemental material for the paper "RMASanitizer: Runtime Detection of Data Races in RMA Applications" submitted to the ICPP conference.

## Repository Structure

- [classification_quality](classification_quality/): Results of RMASanitizer, MUST-RMA and PARCOACH-{dynamic,static} on RMARaceBench
  - The exact version of RMARaceBench used is also included
- [evaluation_results](evaluation_results/): Results of RMASanitizer, MUST-RMA and PARCOACH-{dynamic,static} on the different performance benchmarks considered in the paper
- [RMASanitizer](RMASanitizer/): Source Code for RMASanitizer
- [MUST-RMA](MUST-RMA/): Source Code for MUST-RMA

Note: PARCOACH sources are fetched from git.

## Classification Quality

We ran each tool on the entire RMARaceBench suite. 
For easier comparison, the RMASanitizer runs are separated from those of the other three tools.

The results are presented in the following structure:
- [results-other-tools](classification_quality/results-other-tools/): Entire output folder from RMARaceBench for all tools except RMASanitizer.
- [results-rmasanitizer-mpirma](classification_quality/results-rmasanitizer-mpirma/): Entire output folder from RMARaceBench for RMASanitizer on MPI RMA test cases.
- [results-rmasanitizer-shmem](classification_quality/results-rmasanitizer-shmem/): Entire output folder from RMARaceBench for RMASanitizer on OpenSHMEM test cases.
- [results-rmasanitizer-gaspi](classification_quality/results-rmasanitizer-gaspi/): Entire output folder from RMARaceBench for RMASanitizer on GASPI test cases.

Each output folder also includes the parsed output from the RMARaceBench evaluation script, `results_parsed`.

### Reproduction

To reproduce these results, an installation of Docker or Podman is required.
Additionally, due to incompatibilities of the ThreadSanitizer version included in MUST-RMA and RMASanitizer, the Address space layout randomization (ASLR)
bit count must be below or equal 28.
This can be done temporarily (until system reboot) on typical Linux systemd-based systems using `sysctl vm.mmap_rnd_bits=28`. This command needs root permissions.

Finally, follow these steps:
- Create the Docker Container using the Dockerfile in this repository: `docker build .`
- Run the container in an interactive session: `docker run -it <container hash>`, where the container hash was output in the previous step.
- Optional: Once inside the container, you may regenerate the test files: `python generate.py`
  - The test files included are, however, already be on the latest version, and so no change should occur.

At this point, the RMARaceBench suite can be used to generate the results.
Confer with the included [README](classification_quality/rmaracebench/README.md) as well as the help text from the `run_test.py` script for additional information.

For the purposes of this artifact, the following commands were issued to generate the result folders:
- `python run_test.py tools --rma-model MPIRMA --tool 'MUST-RMA' 'PARCOACH-dynamic' 'PARCOACH-static'`
  - This generates the result folder for all tools but RMASanitizer for the MPI RMA model.
- `python parse_results.py <result folder>/results.csv`
  - This parses the result table into a human readable format. The output of this command is the contents of the `parsed_results` file in each results subfolder.

The results folder contents are copied, and the output of the `parse_results.py` script stored separately.
Then, these steps are repeated for the other runs (the parsing steps are equivalent):

- `python run_test.py tools --rma-model MPIRMA --tool 'RMASanitizer'`
- `python run_test.py tools --rma-model SHMEM --tool 'RMASanitizer'`
- `python run_test.py tools --rma-model GASPI --tool 'RMASanitizer'`

After following these steps, the results generated should match those given in this repository.
