# RMASanitizer: Runtime Detection of Data Races in RMA Applications - Artifact Description

This is the artifact description for the paper "RMASanitizer: Generalized Runtime Detection of Data Races in RMA Applications" submitted to the ICPP'24 conference.

Authors: Simon Schwitanski, Yussur Mustafa Oraji, Cornelius Pätzold, Joachim Jenke, Felix Tomski, Matthias S. Müller, IT Center, RWTH Aachen University


## Main Contributions
The paper contributes a generalized race detection tool for Remote Memory Access Programs. In the paper, we make the following contributions:

- We provide a generalized RMA race detection model compatible with state-of-the-art RMA programming models.
- We present RMASanitizer, an on-the-fly race detector that works with MPI RMA, OpenSHMEM, and GASPI.
- We evaluate the classification quality of RMASanitizer and present overhead studies on different RMA proxy apps.

## Role of the Artifact
- The artifact provides the source code of RMASanitizer itself to review and understand the software architecture of RMASanitizer described in the paper.
- The artifact provides all raw data that was gathered during the experiments to generate the classification quality benchmark (Table 3 of the paper) and overhead study results (Figure 9 of the paper).
- The artifact provides all resources to reproduce the results of the classification quality benchmark (Table 3 of the paper) in the paper as well as the overhead study results (Figure 9 of the paper).


## Repository Structure

- [RMASanitizer](RMASanitizer/): Source code of RMASanitizer (for a detailed explanation, see below)
- [classification_quality](classification_quality/): Results of RMASanitizer, MUST-RMA and PARCOACH-{dynamic,static} on RMARaceBench
  - The exact version of RMARaceBench used is also included in this repo.
- [evaluation_results](evaluation_results/): Results of RMASanitizer and MUST-RMA on the different proxy apps considered in the paper
- [MUST-RMA](MUST-RMA/): Source code of MUST-RMA

## Software Architecture of RMASanitizer
RMASanitizer has been integrated as a tool within the MPI correctness checking framework MUST. It utilizes ThreadSanitizer for the RMA race detection.
The software components mentioned in Section 5 / in Figure 8 of the paper can be found in the following directories:

- Static analysis (run prior to any runtime analysis): [RMASanitizer/externals/RMAOptimizerPlugin](RMASanitizer/externals/RMAOptimizerPlugin/)
  - Contains the LLVM compiler passes for selective memory access instrumentations
- Generalized consistency analysis: [RMASanitizer/modules/OneSidedChecks](RMASanitizer/modules/OneSidedChecks)
  - RMASanitize: Implements the generalized race detection model (consistency analysis)
  - RMAWrapper: Wrappers for MPI RMA, SHMEM, and GASPI that map the concrete calls to the abstract events
  - RaceChecks/TSan: Interface to ThreadSanitizer to annotate concurrent regions and detect races, including race validation
- Generalized vector clock analyis: [RMASanitizer/externals/GTI/modules/gti-internal/VectorClock.cpp](RMASanitizer/externals/GTI/modules/gti-internal/VectorClock.cpp)
  - The wrappers for MPI RMA, SHMEM, and GASPI are available at [RMASanitizer/modules/VectorClockWrapper](RMASanitizer/modules/VectorClockWrapper)
- ThreadSanitizer runtime: [RMASanitizer/externals/RMAOptimizerPlugin/external/compiler-rt/compiler-rt](RMASanitizer/externals/RMAOptimizerPlugin/external/compiler-rt/compiler-rt)
  - RMASanitizer uses a slightly modified ThreadSanitizer runtime that is linked into the application.
- Race report generation: [RMASanitizer/modules/TSan/Messages/TSanMessages.cpp](RMASanitizer/modules/TSan/Messages/TSanMessages.cpp)
  - If ThreadSanitizer detects a race, then the report is parsed here and validated before a race report is generated.
- RMASanitizer relies on call interception via PnMPI (extended to work with SHMEM and GASPI): [RMASanitizer/externals/GTI/externals/PnMPI](RMASanitizer/externals/GTI/externals/PnMPI)
  - The actual mapping of MPI RMA, SHMEM, GASPI calls is specified via XMLs that are translated to source code upon installation of RMASanitizer.
    - MPI RMA: [RMASanitizer/specifications/mpi_3_specification_rma.xml](RMASanitizer/specifications/mpi_3_specification_rma.xml)
    - SHMEM: [RMASanitizer/specifications/shmem_specification.xml](RMASanitizer/specifications/shmem_specification.xml)
    - GASPI: [RMASanitizer/specifications/gaspi_specification.xml](RMASanitizer/specifications/gaspi_specification.xml)
    - There are more XML specifications that define the interaction between the different analysis modules. For details, we refer to the [RMASanitizer/specifications](RMASanitizer/specifications) directory to get an overview.
- Tool communication via tool threads is implemented in GTI: [RMASanitizer/externals/GTI](RMASanitizer/externals/GTI/)




## Classification Quality Results

We ran each tool on the entire RMARaceBench suite. 
For easier comparison, the RMASanitizer runs are separated from those of the other three tools.

The results are presented in the following structure:
- [classification_quality/results-other-tools](classification_quality/results-other-tools/): Entire output folder from RMARaceBench for all tools except RMASanitizer.
- [classification_quality/results-rmasanitizer-mpirma](classification_quality/results-rmasanitizer-mpirma/): Entire output folder from RMARaceBench for RMASanitizer on MPI RMA test cases.
- [classification_quality/results-rmasanitizer-shmem](classification_quality/results-rmasanitizer-shmem/): Entire output folder from RMARaceBench for RMASanitizer on OpenSHMEM test cases.
- [classification_quality/results-rmasanitizer-gaspi](classification_quality/results-rmasanitizer-gaspi/): Entire output folder from RMARaceBench for RMASanitizer on GASPI test cases.

Each output folder also includes the parsed output from the RMARaceBench evaluation script, `results_parsed`.
Those result values were copied into Table 3.

### Software Requirements / Versions
- OpenMPI 4.1.6 for MPI RMA
- Sandia SHMEM 1.5.2 for OpenSHMEM
- GPI-2 1.5.1 for GASPI
- Clang 16 as compiler
- RMASanitizer / MUST-RMA / PARCOACH as provided by this repository
- All required software is shipped with the Docker container of RMARaceBench.


## Overhead Study Results
The performance evaluation uses the JUBE benchmarking environment for reproducible benchmark setups.

The raw performance results are available in the folder [evaluation_results](evaluation_results/) for RMASanitizer and MUST-RMA in subfolders for each benchmark. In particular, each subfolder has a folder `result` that contains the measured results in a CSV file (`result_csv.dat`) and in a human-readable (`result.dat`) format.

The following benchmarks were executed (they are shipped with this artifact):
- PRK Stencil: weak (MPI RMA), 1000 iters, $48 \cdot 10^6$ elements per proc
- PRK Stencil: weak (SHMEM), 1000 iters, $48 \cdot 10^6$ elements per proc
- NPB BT (ported): strong (MPI RMA), Class D (162 x 162 x 162)
- NPB BT (ported): strong (SHMEM), Class D (162 x 162 x 162)
- LULESH (ported): weak (MPI RMA), $20^3$ problem size, 8000 elems per proc
- miniMD (ported): weak (MPI RMA), 400 timesteps, LJ, 260000 atoms per proc
- CFD-Proxy: strong (GASPI), 1000 iters, F6 airplane mesh


### Plotting the Results



### Hardware Properties
The benchmarks were executed on the CLAIX-23 cluster of RWTH Aachen University where each node has the following hardware properties:
- 2x Intel Xeon 8468 Sapphire Rapids with disabled SMT 
- 256 GB of main memory
- InfiniBand interconnect

### Software Requirements / Versions
- JUBE 2.6.1 for experiment workflow
- OpenMPI 4.1.6 for MPI RMA
- Sandia SHMEM 1.5.2 for OpenSHMEM
- GPI-2 1.5.1 for GASPI
- Clang 16 as compiler
- RMASanitizer and MUST-RMA

## Reproducibility of Experiments
In the following, we document the steps to reproduce the results on classification quality and the overhead study.

For the classification quality experiment, we expect to set up and run everything within 60 to 90 minutes.

For the overhead study, in case of all software requirements are installed, the execution of the overhead study requires running a few JUBE commands and finally parsing the output to a Python script. While running all the commands will only take a few minutes, the execution of the jobs using Slurm will take a few hours.

## Classification Quality

To reproduce these classification quality results, an installation of Docker or Podman is required.

*Note:* In *very* recent Linux kernel versions > 6.0, the Address space layout randomization (ASLR) bit count must be below or equal 28. This can be done temporarily (until system reboot) on typical Linux systemd-based systems using `sysctl vm.mmap_rnd_bits=28`. This command needs root permissions. This is a requirement of the ThreadSanitizer version shipped MUST-RMA and RMASanitizer.

Finally, follow these steps:
- Create the Docker Container using the Dockerfile in this repository: `docker build . -t rmaracebench`
- Run the container in an interactive session: `docker run -it rmaracebench`, where the container hash was output in the previous step.
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


## Overhead Study
