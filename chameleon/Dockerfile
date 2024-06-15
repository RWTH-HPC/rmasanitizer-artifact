FROM debian:12

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Berlin

RUN apt-get update \
    && apt-get -y -qq --no-install-recommends install \
    cmake \
    curl \
    binutils-dev \
    make \
    automake \
    autotools-dev \
    nano \
    autoconf \
    libtool \
    zlib1g \
    zlib1g-dev \
    libatomic1 \
    libfabric-dev \
    libxml2-dev \
    python3 \
    python3-pip \
    python3-venv \
    gfortran \
    gcc \
    g++ \
    git \
    graphviz \
    libgtest-dev \
    ninja-build \
    vim \
    openssh-client \
    gdb \
    wget \
    googletest \
    && apt-get -yq clean


RUN apt-get -y -qq --no-install-recommends install \
    zstd \
    libzstd-dev \
    clang-16 \
    libomp-16-dev \
    clang-format-16 \
    llvm-16 \
    llvm-16-dev

ENV CC=clang-16
ENV CXX=clang++-16

# Install Clang + Flang 16
COPY chameleon/classic_flang_setup /classic_flang_setup

RUN sh /classic_flang_setup/fortran_setup.sh /build /opt/clang

ENV PATH="/opt/clang/classic-flang/bin:$PATH"
ENV LD_LIBRARY_PATH="/opt/clang/classic-flang/lib:$LD_LIBRARY_PATH"
ENV LD_LIBRARY_PATH="/opt/clang/classic-flang/lib/x86_64-unknown-linux-gnu:$LD_LIBRARY_PATH"
ENV LIBRARY_PATH="/opt/clang/classic-flang/lib:$LIBRARY_PATH"
ENV LIBRARY_PATH="/opt/clang/classic-flang/lib/x86_64-unknown-linux-gnu:$LIBRARY_PATH"
ENV CPATH="/opt/clang/classic-flang/include:$CPATH"
ENV CMAKE_PREFIX_PATH="/opt/clang/classic-flang:$CMAKE_PREFIX_PATH"
ENV CC=clang
ENV CXX=clang++
ENV FC=flang


WORKDIR /externals

# RUN apt-get -y -qq --no-install-recommends install libibverbs1 librdmacm1 librdmacm-dev \
#     libibmad5 libibumad3 librdmacm1 ibverbs-providers rdmacm-utils \
#     infiniband-diags libfabric1 ibverbs-utils

# # Install OpenMPI
# RUN apt-get update \
#     && apt-get -y -qq --no-install-recommends install \
#     openmpi-bin \
#     libopenmpi-dev \
#     && apt-get -yq clean

# # Delete shmem headers from OpenMPI installation that could conflict with OpenSHMEM
# RUN rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmem.h && \
#     rm /usr/lib/x86_64-linux-gnu/openmpi/include/pshmem.h && \
#     rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmem.fh && \
#     rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmemx.h && \
#     rm /usr/lib/x86_64-linux-gnu/openmpi/include/pshmemx.h && \
#     rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmem-compat.h && \
#     rm /lib/x86_64-linux-gnu/liboshmem.so*


# Install OpenMPI
RUN     wget https://download.open-mpi.org/release/open-mpi/v4.1/openmpi-4.1.6.tar.gz && \
        tar -xf openmpi-4.1.6.tar.gz && \
        cd openmpi-4.1.6 && \
        ./configure --prefix=/usr --with-ofi --enable-oshmem=no --enable-mpi1-compatibility && \
        make -j$(nproc) install

ENV OMPI_CC=clang
ENV OMPI_CXX=clang++

ENV PATH="/opt/openmpi/bin:$PATH"
ENV LD_LIBRARY_PATH="/opt/openmpi/lib:$LD_LIBRARY_PATH"
ENV LIBRARY_PATH="/opt/openmpi/lib:$LIBRARY_PATH"
ENV CPATH="/opt/openmpi/include:$CPATH"
ENV CMAKE_PREFIX_PATH="/opt/openmpi:$CMAKE_PREFIX_PATH"

RUN apt-get install patch
COPY chameleon/sandia_shmem.patch /sandia_shmem.patch
# Install OpenSHMEM
RUN     wget https://github.com/Sandia-OpenSHMEM/SOS/archive/refs/tags/v1.5.2.tar.gz -O SOS-1.5.2.tar.gz && \
        tar -xf SOS-1.5.2.tar.gz && \
        cd SOS-1.5.2 && \
        patch -p1 < /sandia_shmem.patch && \
        ./autogen.sh && \
        CC=mpicc CXX=mpicxx FC=mpifort ./configure --prefix=/usr --with-ofi=/usr --enable-pmi-mpi --disable-cxx --enable-fortran --enable-error-checking --enable-visibility=no --enable-profiling=yes && \
        make -j$(nproc) install


ENV PATH="/opt/sos/bin:$PATH"
ENV LD_LIBRARY_PATH="/opt/sos/lib:$LD_LIBRARY_PATH"
ENV LIBRARY_PATH="/opt/sos/lib:$LIBRARY_PATH"
ENV CPATH="/opt/sos/include:$CPATH"
ENV CMAKE_PREFIX_PATH="/opt/sos:$CMAKE_PREFIX_PATH"

# RUN apt-get install libibverbs-dev

# Install GPI (GASPI)
RUN    wget https://github.com/cc-hpc-itwm/GPI-2/archive/refs/tags/v1.5.1.tar.gz -O GPI-2-1.5.1.tar.gz && \
       tar -xf GPI-2-1.5.1.tar.gz && \
       cd GPI-2-1.5.1 && \
       ./autogen.sh && \
       OMPI_CC=clang OMPI_CXX=clang++ CC=mpicc CXX=mpicxx ./configure --prefix=/usr --with-mpi --with-infiniband=no --with-ethernet --with-pbs=no --disable-debug-lib && \
       make -j$(nproc) install

ENV PATH="/opt/gpi/bin:$PATH"
ENV LD_LIBRARY_PATH="/opt/gpi/lib64:$LD_LIBRARY_PATH"
ENV LIBRARY_PATH="/opt/gpi/lib64:$LIBRARY_PATH"
ENV CPATH="/opt/gpi/include:$CPATH"
ENV CMAKE_PREFIX_PATH="/opt/gpi:$CMAKE_PREFIX_PATH"

ENV LD_LIBRARY_PATH="/usr/lib64:$LD_LIBRARY_PATH"
ENV LIBRARY_PATH="/usr/lib64:$LIBRARY_PATH"
ENV CMAKE_LIBRARY_PATH="/usr/lib64:$CMAKE_LIBRARY_PATH"

# Install MUST
COPY MUST-RMA ./MUST-RMA
# RUN rm -rf ./MUST-RMA/.git && echo "0.0.0" > ./MUST-RMA/.version
# RUN rm -rf ./MUST-RMA/externals/GTI/.git && echo "0.0.0" > ./MUST-RMA/externals/GTI/.version
# RUN rm -rf ./MUST-RMA/externals/GTI/externals/PnMPI/.git && echo "0.0.0" > ./MUST-RMA/externals/GTI/externals/PnMPI/.version
RUN cd MUST-RMA && \
    mkdir -p build && \
    cd build && \
    CC=clang CXX=clang++ OMPI_CC=clang OMPI_CXX=clang++ MPICH_CC=clang MPICH_CXX=clang++ cmake -DCMAKE_BUILD_TYPE=Release -DUSE_BACKWARD=ON -DENABLE_FORTRAN=OFF -DENABLE_TYPEART=OFF -DCMAKE_INSTALL_PREFIX=/opt/must-rma .. && \
    make -j$(nproc) install && \
    make -j$(nproc) -j32 install-prebuilds

# Install RMASanitizer
COPY RMASanitizer ./rmasanitizer

RUN cd ./rmasanitizer && \
    mkdir -p build && \
    cd build && \
    CC=clang CXX=clang++ OMPI_CC=clang OMPI_CXX=clang++ OMPI_FC=flang cmake \
    -DMPI_C_COMPILER=$(which mpicc) \
    -DMPI_CXX_COMPILER=$(which mpicxx)\
    -DCMAKE_Fortran_COMPILER=$(which mpifort) \
    -DCMAKE_INSTALL_PREFIX=/opt/rmasanitizer \
    -DENABLE_FORTRAN=ON \
    -DENABLE_TSAN=ON \
    -DENABLE_TYPEART=OFF \
    -DCMAKE_BUILD_TYPE=Release \
    -DENABLE_TESTS=0 \
    -DUSE_BACKWARD=OFF \
    -DENABLE_OPENSHMEM=ON \
    -DENABLE_GASPI=ON \
    -DENABLE_STACKTRACE=OFF .. && \
    make -j$(nproc) install

# # Clean up externals
# RUN rm -rf /externals

# WORKDIR /

# # Run script
# COPY classification_quality/rmaracebench/MPIRMA /rmaracebench/MPIRMA
# COPY classification_quality/rmaracebench/SHMEM /rmaracebench/SHMEM
# COPY classification_quality/rmaracebench/GASPI /rmaracebench/GASPI
# COPY classification_quality/rmaracebench/templates /rmaracebench/templates
# COPY classification_quality/rmaracebench/util/run_test.py /rmaracebench/run_test.py
# COPY classification_quality/rmaracebench/util/parse_results.py /rmaracebench/parse_results.py
# COPY classification_quality/rmaracebench/util/generate.py /rmaracebench/generate.py

# # Script to generate results for reproducibility
# COPY classification_quality/generate_results.sh /rmaracebench/generate_results.sh

# # Allow oversubscription for OpenMPI
# ENV OMPI_MCA_rmaps_base_oversubscribe=1

# # Run as non-privileged user
# RUN useradd -ms /bin/bash user
# RUN chown -R user:user /rmaracebench
# USER user

# ENV OMPI_CC=clang
# ENV OMPI_CXX=clang++
# ENV MPICH_CC=clang
# ENV MPICH_CXX=clang++
# ENV PATH="/opt/parcoach/bin:$PATH"
# ENV LD_LIBRARY_PATH="/usr/lib64:$LD_LIBRARY_PATH"

# WORKDIR /rmaracebench

# Install Python dependencies and ensure to activate virtualenv (by setting PATH variable)
ENV VIRTUAL_ENV=/opt/venv
RUN python3 -m venv $VIRTUAL_ENV
ENV PATH="$VIRTUAL_ENV/bin:$PATH"
RUN pip3 install http://apps.fz-juelich.de/jsc/jube/download.php?version=latest
ENV JUBE_INCLUDE_PATH=/opt/venv/share/jube/platform/slurm

ENV OMPI_ALLOW_RUN_AS_ROOT=1
ENV OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1


RUN apt-get -y -qq --no-install-recommends install \
    netcdf-bin \
    libnetcdf-dev