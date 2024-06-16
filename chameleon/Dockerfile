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
    zstd \
    libzstd-dev \
    clang-16 \
    libomp-16-dev \
    clang-format-16 \
    llvm-16 \
    llvm-16-dev \
    patch \
    && apt-get -yq clean

# TeXLive for plots
RUN apt-get -y -qq --no-install-recommends install \
    dvipng \
    texlive-latex-extra \
    texlive-fonts-recommended \
    cm-super \
    && apt-get -yq clean

# NetCDF for CFD-Proxy
RUN apt-get -y -qq --no-install-recommends install \
    netcdf-bin \
    libnetcdf-dev \
    && apt-get -yq clean


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

# Install OpenMPI
RUN     wget https://download.open-mpi.org/release/open-mpi/v4.1/openmpi-4.1.6.tar.gz && \
        tar -xf openmpi-4.1.6.tar.gz && \
        cd openmpi-4.1.6 && \
        ./configure --prefix=/usr --with-ofi --enable-oshmem=no --enable-mpi1-compatibility && \
        make -j$(nproc) install

ENV OMPI_CC=clang
ENV OMPI_CXX=clang++
# Allow to run OpenMPI as root in container
ENV OMPI_ALLOW_RUN_AS_ROOT=1
ENV OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1


# Install OpenSHMEM
COPY chameleon/sandia_shmem.patch /sandia_shmem.patch
RUN     wget https://github.com/Sandia-OpenSHMEM/SOS/archive/refs/tags/v1.5.2.tar.gz -O SOS-1.5.2.tar.gz && \
        tar -xf SOS-1.5.2.tar.gz && \
        cd SOS-1.5.2 && \
        patch -p1 < /sandia_shmem.patch && \
        ./autogen.sh && \
        CC=mpicc CXX=mpicxx FC=mpifort ./configure --prefix=/usr --with-ofi=/usr --enable-pmi-mpi --disable-cxx --enable-fortran --enable-error-checking --enable-visibility=no --enable-profiling=yes && \
        make -j$(nproc) install


# Install GPI (GASPI)
RUN    wget https://github.com/cc-hpc-itwm/GPI-2/archive/refs/tags/v1.5.1.tar.gz -O GPI-2-1.5.1.tar.gz && \
       tar -xf GPI-2-1.5.1.tar.gz && \
       cd GPI-2-1.5.1 && \
       ./autogen.sh && \
       OMPI_CC=clang OMPI_CXX=clang++ CC=mpicc CXX=mpicxx ./configure --prefix=/usr --with-mpi --with-infiniband=no --with-ethernet --with-pbs=no --disable-debug-lib && \
       make -j$(nproc) install

ENV LD_LIBRARY_PATH="/usr/lib64:$LD_LIBRARY_PATH"
ENV LIBRARY_PATH="/usr/lib64:$LIBRARY_PATH"
ENV CMAKE_LIBRARY_PATH="/usr/lib64:$CMAKE_LIBRARY_PATH"

# Install MUST-RMA
COPY MUST-RMA ./MUST-RMA
RUN cd MUST-RMA && \
    mkdir -p build && \
    cd build && \
    CC=clang CXX=clang++ OMPI_CC=clang OMPI_CXX=clang++ OMPI_FC=flang cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DUSE_BACKWARD=ON \
        -DENABLE_FORTRAN=ON \
        -DENABLE_TYPEART=OFF \
        -DCMAKE_INSTALL_PREFIX=/opt/must-rma .. && \
    make -j$(nproc) install && \
    make -j$(nproc) install-prebuilds

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

# clean up externals folder
WORKDIR /
RUN rm -r /externals

# Install Python dependencies and ensure to activate virtualenv (by setting PATH variable)
ENV VIRTUAL_ENV=/opt/venv
RUN python3 -m venv $VIRTUAL_ENV
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

# Install JUBE
RUN pip3 install http://apps.fz-juelich.de/jsc/jube/download.php?version=latest
ENV JUBE_INCLUDE_PATH=/opt/venv/share/jube/platform/slurm

# Install Python dependencies for plots
COPY overhead_evaluation/plots/requirements.txt /requirements.txt
RUN pip3 install -r /requirements.txt

RUN useradd -ms /bin/bash user
WORKDIR /home/user