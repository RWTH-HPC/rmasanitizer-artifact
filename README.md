# RMASanitizer: Runtime Detection of Data Races in RMA Applications - Computational Artifact

This is the computational artifact for the paper "RMASanitizer: Generalized Runtime Detection of Data Races in RMA Applications" submitted to the ICPP'24 conference.

Authors: Simon Schwitanski, Yussur Mustafa Oraji, Cornelius Pätzold, Joachim Jenke, Felix Tomski, Matthias S. Müller, IT Center, RWTH Aachen University

## Repository Structure

- [RMASanitizer](RMASanitizer/): Source code of RMASanitizer (for a detailed explanation, see below)
- [classification_quality](classification_quality/): Results of RMASanitizer, MUST-RMA and PARCOACH-{dynamic,static} on RMARaceBench
  - The exact version of RMARaceBench used is also included in this repo.
- [evaluation_results](evaluation_results/): Results of RMASanitizer and MUST-RMA on the different proxy apps considered in the paper
- [classification_quality.sh](classification_quality.sh): Script to reproduce classification quality results (Table 3, Section 6.1)
- [overhead_submit.sh](overhead_results.sh): Scripts to reproduce the overhead results (Figure 9, Section 6.2)

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
For details, we refer to the artifact description.
To reproduce the results, run

```
./classification_quality.sh
```

## Overhead Study
For details, we refer to the artifact description.
To reproduce the results, run

```
./overhead_submit.sh
```

After everything finished, run

```
./overhead_results.sh
```