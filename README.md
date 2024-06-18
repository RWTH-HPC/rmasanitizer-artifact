# RMASanitizer: Generalized Runtime Detection of Data Races in RMA Applications - Computational Artifact

This is the computational artifact for the paper "RMASanitizer: Generalized Runtime Detection of Data Races in RMA Applications" submitted to the ICPP'24 conference.

Authors: Simon Schwitanski, Yussur Mustafa Oraji, Cornelius Pätzold, Joachim Jenke, Felix Tomski, Matthias S. Müller, Chair for High Performance Computing, IT Center, RWTH Aachen University

## Repository Structure

- [RMASanitizer](RMASanitizer/): Source code of RMASanitizer (for a detailed explanation, see below)
- [MUST-RMA](MUST-RMA/): Source code of MUST-RMA
- [classification_quality](classification_quality/): Results of RMASanitizer, MUST-RMA and PARCOACH-{dynamic,static} on RMARaceBench (Table 3, Section 6.1)
  - The exact version of RMARaceBench used is also included in this repo.
- [overhead_evaluation](overhead_evaluation/): Results of RMASanitizer and MUST-RMA on the different proxy apps considered in the paper (Figure 9, Section 6.2)
- [overhead_evaluation/plots](overhead_evaluation/plots): Resulting plots (Figure 9, Section 6.2)
- [classification_quality.sh](classification_quality.sh): Script to reproduce classification quality results (Table 3, Section 6.1)
- [overhead_submit.sh](overhead_submit.sh) / [overhead_result.sh](overhead_results.sh): Scripts to reproduce the overhead results (Figure 9, Section 6.2)

## Reproducing Results

The results of this artifact can be reproduced on an HPC cluster or using ChameleonCloud.

### Optional: Starting a ChameleonCloud Node

For simplified execution of the experiments, we provide a ChameleonCloud script that sets up a machine suitable for running all evaluations.
The script can be executed with

```
./reserve_chameleon_node.sh
```

It will start up a properly configured node (compute_zen3) using the infrastructure of CHI@TACC with `openstack`. The image used for the nodes is `ubuntu2204-rmasan` (CHI@TACC).

If `openstack` is not installed on the executing system, a corresponding Docker image can be built and executed with

```
./start_openstack_image.sh
```

After reserving the node, the script automatically connects via SSH to the machine.
On the machine, the following script available on the machine itself downloads the artifact to the node:

```
./bootstrap.sh
```

### Classification Quality Results

To reproduce the results, run

```
./classification_quality.sh
```

The results will be available in the folder `cq-results-YYMMDD-HHMMSS` for further investigation. The files in the `summaries` folder can be used to compare the reproduced results with the reference results (see `classification_quality`).
The script will also print out the summarized results to the command line.

### Overhead Study

To reproduce the results of the small-scale experiment, run

```
./overhead_evaluation_chameleon.sh
```

The results will be available in the folder `perf-results-YYMMDD-HHMMSS`. 
In particular, the resulting plotted PNG file is contained within the folder.
For reference, the paper results (large-scale experiment) can be found at [overhead_evaluation/plots/results_largescale.png](overhead_evaluation/plots/results_largescale.png) and the Chameleon cloud results (small-scale experiment) can be found at [overhead_evaluation/plots/results_smallscale.png](overhead_evaluation/plots/results_smallscale.png).

Qualitatively, the results of the small-scale experiment are similar to that of the large-scale experiment in the paper: RMASanitizer has a significant smaller slowdown than MUST-RMA. With an increasing number of processes, the slowdown of RMASanitizer (and also MUST-RMA) increases.

### Optional: Copy results back

To access the result files from outside container, the script

```
./copy_results_to_objectstorage.sh
```

copies the result to the ChameleonCloud object storage.
The files can then be viewed with the ChameleonCloud object storage file viewer.

## Input Sizes

We provide input sizes for a large-scale experiment (`M`) (as done in the paper) and for a small-scale experiment (`S`). The input sizes can also be set in the `overhead_submit.sh` script.

The input sizes of the large-scale experiment are:

- PRK_Stencil: 1000 iterations, 48*10^6 elements per processor, weak scaling
- NPB BT-RMA: Class D (408 x 408 x 408), strong scaling
- LULESH: 20^3, 8000 elements per processor, weak scaling
- miniMD: 400 timesteps, LJ, 260000 atoms per processor, weak scaling
- PRK_Stencil_shmem: 1000 iterations, 48*10^6 elements per processor, weak scaling
- NPB BT-SHMEM: Class D (408 x 408 x 408), strong scaling
- CFD-Proxy: 1000 iterations, F6 airplane mesh, strong scaling

The input sizes of the small-scale experiment are:

- PRK_Stencil: 100 iterations, 32*10^6 elements per processor, weak scaling
- NPB BT-RMA: Class C (162 x 162 x 162), strong scaling
- LULESH: 12^3, 1728 elements per processor, weak scaling
- miniMD: 40 timesteps, LJ, 260000 atoms per processor, weak scaling
- PRK_Stencil_shmem: 100 iterations, 32*10^6 elements per processor, weak scaling
- NPB BT-SHMEM: Class C (162 x 162 x 162), strong scaling
- CFD-Proxy: 1000 iterations, F6 airplane mesh, strong scaling

## JUBE Commands

### Large-Scale Experiment (Paper)

The following JUBE commands are used for each benchmark (input size: `M`):

```
# Run benchmark with MUST-RMA
jube run overhead_evaluation/jube/<benchmark>/<benchmark>.xml -o MUST-RMA/ --tag M ignorelist pnmpi memusage rebuild_source must-rma 

# Run benchmark with RMASanitizer
jube run overhead_evaluation/jube/<benchmark>/<benchmark>.xml -o RMASanitizer/ --tag M ignorelist pnmpi memusage rebuild_source tsan-opt
```

### Small-Scale Experiment (Chameleon)

The following JUBE commands are used for each benchmark (input size: `S`):

```
# Run benchmark with MUST-RMA
jube run overhead_evaluation/jube/<benchmark>/<benchmark>.xml -o MUST-RMA/ --tag S ignorelist memusage rebuild_source must-rma chameleon

# Run benchmark with RMASanitizer
jube run overhead_evaluation/jube/<benchmark>/<benchmark>.xml -o RMASanitizer/ --tag S ignorelist memusage rebuild_source must-rma chameleon
```

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
