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
    clang-15 \
    clang-format-15 \
    llvm-15 \
    llvm-15-dev \
    ninja-build \
    vim \
    openssh-client \
    gdb \
    wget \
    googletest \
    && apt-get -yq clean

# Install OpenMPI
RUN apt-get update \
    && apt-get -y -qq --no-install-recommends install \
    openmpi-bin \
    libopenmpi-dev \
    && apt-get -yq clean

# Delete shmem headers from OpenMPI installation that could conflict with OpenSHMEM
RUN rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmem.h && \
    rm /usr/lib/x86_64-linux-gnu/openmpi/include/pshmem.h && \
    rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmem.fh && \
    rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmemx.h && \
    rm /usr/lib/x86_64-linux-gnu/openmpi/include/pshmemx.h && \
    rm /usr/lib/x86_64-linux-gnu/openmpi/include/shmem-compat.h && \
    rm /lib/x86_64-linux-gnu/liboshmem.so*

# Install PARCOACH
RUN   wget https://gitlab.inria.fr/parcoach/parcoach/-/archive/2.4.2/parcoach-2.4.2.tar.gz && \
      tar -xf parcoach-2.4.2.tar.gz && \
      cd parcoach-2.4.2 && \
      mkdir -p build && \
      cd build && \
      CC=clang-15 CXX=clang++-15 OMPI_CC=clang-15 OMPI_CXX=clang++-15 MPICH_CC=clang-15 MPICH_CXX=clang++-15 cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/parcoach -DPARCOACH_ENABLE_TESTS=OFF .. && \
      make -j$(nproc) install

RUN apt-get -y -qq --no-install-recommends install \
    zstd \
    libzstd-dev \
    clang-16 \
    libomp-16-dev \
    clang-format-16 \
    llvm-16 \
    llvm-16-dev

# ensure that LLVM 16 toolset is used
RUN ln -s /usr/bin/FileCheck-16 /usr/bin/FileCheck
RUN ln -s /usr/bin/clang-16 /usr/bin/clang
RUN ln -s /usr/bin/clang++-16 /usr/bin/clang++
RUN ln -s /usr/bin/clang-format-16 /usr/bin/clang-format
RUN ln -s $(which llvm-link-16) /usr/bin/llvm-link
RUN ln -s $(which opt-16) /usr/bin/opt
RUN ln -s $(which llc-16) /usr/bin/llc

# Install Python dependencies and ensure to activate virtualenv (by setting PATH variable)
COPY classification_quality/rmaracebench/requirements.txt .
ENV VIRTUAL_ENV=/opt/venv
RUN python3 -m venv $VIRTUAL_ENV
ENV PATH="$VIRTUAL_ENV/bin:$PATH"
RUN pip3 install --no-input --no-cache-dir --disable-pip-version-check -r /requirements.txt

WORKDIR /externals

# Install OpenSHMEM
RUN     wget https://github.com/Sandia-OpenSHMEM/SOS/archive/refs/tags/v1.5.2.tar.gz -O SOS-1.5.2.tar.gz && \
        tar -xf SOS-1.5.2.tar.gz && \
        cd SOS-1.5.2 && \
        ./autogen.sh && \
        OMPI_CC=clang OMPI_CXX=clang++ MPICH_CC=clang MPICH_CXX=clang++ CC=mpicc CXX=mpicxx ./configure --prefix=/usr --with-ofi=/usr --enable-pmi-mpi --disable-cxx --disable-fortran --enable-error-checking --enable-profiling=yes && \
        make -j$(nproc) install

# Install GPI (GASPI)
RUN    wget https://github.com/cc-hpc-itwm/GPI-2/archive/refs/tags/v1.5.1.tar.gz -O GPI-2-1.5.1.tar.gz && \
       tar -xf GPI-2-1.5.1.tar.gz && \
       cd GPI-2-1.5.1 && \
       ./autogen.sh && \
       OMPI_CC=clang OMPI_CXX=clang++ MPICH_CC=clang MPICH_CXX=clang++ CC=mpicc CXX=mpicxx ./configure --prefix=/usr --with-mpi --with-infiniband=no --with-ethernet --with-pbs=no && \
       make -j$(nproc) install

# Install MUST
COPY MUST-RMA ./MUST-RMA
RUN rm -rf ./MUST-RMA/.git && echo "0.0.0" > ./MUST-RMA/.version
RUN rm -rf ./MUST-RMA/externals/GTI/.git && echo "0.0.0" > ./MUST-RMA/externals/GTI/.version
RUN rm -rf ./MUST-RMA/externals/GTI/externals/PnMPI/.git && echo "0.0.0" > ./MUST-RMA/externals/GTI/externals/PnMPI/.version
RUN cd MUST-RMA && \
    mkdir -p build && \
    cd build && \
    CC=clang CXX=clang++ OMPI_CC=clang OMPI_CXX=clang++ MPICH_CC=clang MPICH_CXX=clang++ cmake -DCMAKE_PREFIX_PATH='/usr/lib/llvm-16/;/usr/lib/;/usr/lib64/' -DCMAKE_BUILD_TYPE=Release -DUSE_BACKWARD=ON -DENABLE_FORTRAN=OFF -DENABLE_TYPEART=OFF -DCMAKE_INSTALL_PREFIX=/opt/must .. && \
    make -j$(nproc) install && \
    make -j$(nproc) -j32 install-prebuilds

# Install RMASanitizer
COPY RMASanitizer ./rmasanitizer
RUN rm -rf ./rmasanitizer/.git && echo "0.0.0" > ./rmasanitizer/.version
RUN rm -rf ./rmasanitizer/externals/GTI/.git && echo "0.0.0" > ./rmasanitizer/externals/GTI/.version
RUN rm -rf ./rmasanitizer/externals/GTI/externals/PnMPI/.git && echo "0.0.0" > ./rmasanitizer/externals/GTI/externals/PnMPI/.version
RUN cd ./rmasanitizer && \
    mkdir -p build && \
    cd build && \
    CC=clang CXX=clang++ OMPI_CC=clang OMPI_CXX=clang++ MPICH_CC=clang MPICH_CXX=clang++ cmake -DCMAKE_PREFIX_PATH='/usr/lib/llvm-16/;/usr/lib/;/usr/lib64/' -DCMAKE_BUILD_TYPE=Release -DENABLE_STACKTRACE=OFF -DUSE_BACKWARD=OFF -DENABLE_FORTRAN=OFF -DENABLE_OPENSHMEM=ON -DENABLE_GASPI=ON -DENABLE_TYPEART=OFF -DCMAKE_INSTALL_PREFIX=/opt/rmasanitizer .. && \
    make -j$(nproc) install

# Clean up externals
RUN rm -rf /externals

WORKDIR /

# Run script
COPY classification_quality/rmaracebench/MPIRMA /rmaracebench/MPIRMA
COPY classification_quality/rmaracebench/SHMEM /rmaracebench/SHMEM
COPY classification_quality/rmaracebench/GASPI /rmaracebench/GASPI
COPY classification_quality/rmaracebench/templates /rmaracebench/templates
COPY classification_quality/rmaracebench/util/run_test.py /rmaracebench/run_test.py
COPY classification_quality/rmaracebench/util/parse_results.py /rmaracebench/parse_results.py
COPY classification_quality/rmaracebench/util/generate.py /rmaracebench/generate.py

# Script to generate results for reproducibility
COPY classification_quality/generate_results.sh /rmaracebench/generate_results.sh
COPY classification_quality/parse_results.sh /rmaracebench/parse_results.sh

# Allow oversubscription for OpenMPI
ENV OMPI_MCA_rmaps_base_oversubscribe=1
# Allow to run OpenMPI as root in container
ENV OMPI_ALLOW_RUN_AS_ROOT=1
ENV OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1

# Run as non-privileged user
# RUN useradd -ms /bin/bash user
# RUN chown -R user:user /rmaracebench
# USER user

ENV OMPI_CC=clang
ENV OMPI_CXX=clang++
ENV MPICH_CC=clang
ENV MPICH_CXX=clang++
ENV PATH="/opt/parcoach/bin:$PATH"
ENV LD_LIBRARY_PATH="/usr/lib64:$LD_LIBRARY_PATH"

WORKDIR /rmaracebench
