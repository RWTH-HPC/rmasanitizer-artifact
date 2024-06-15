#!/usr/bin/env zsh

set -e

if [ $# -ne 2 ]
then
  echo "Expected two arguments: <BUILD-DIR> <INSTALL-DIR>"
  exit 1
fi

scriptdir="$(realpath $(dirname $0))"
builddir="$(realpath $1)"
installdir="$(realpath $2)"

echo "Script dir: $scriptdir"
echo "Building in: $builddir"
echo "Installing to: $installdir"

mkdir -p $builddir

# Build and install base classic flang project
cd $builddir
git clone --recursive --depth=1 --branch release_16x https://github.com/flang-compiler/classic-flang-llvm-project/
cd "${builddir}/classic-flang-llvm-project"
mkdir build && cd build
cmake ../llvm -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="${installdir}/classic-flang" -DLLVM_ENABLE_PROJECTS="clang;compiler-rt;openmp;libc" -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi;libunwind" -DLLVM_ENABLE_LIBEDIT=OFF -DGCC_INSTALL_PREFIX="$EBROOTGCCCORE" -DLLVM_ENABLE_CLASSIC_FLANG=ON -DFLANG_BUILD_NEW_DRIVER=OFF -DLLVM_FORCE_ENABLE_STATS=1
cmake --build . -j6 --target install

# Build and install libpgmath (requirement for flang frontend)
cd "${builddir}"
git clone --recursive https://github.com/flang-compiler/flang
cd "${builddir}/flang/runtime/libpgmath"
mkdir -p build && cd ./build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="${installdir}/classic-flang" -DGCC_INSTALL_PREFIX="$EBROOTGCCCORE" -DCMAKE_C_COMPILER="${installdir}/classic-flang/bin/clang" -DCMAKE_CXX_COMPILER="${installdir}/classic-flang/bin/clang++" -DCMAKE_Fortran_COMPILER="${installdir}/classic-flang/bin/flang" -DCMAKE_Fortran_COMPILER_ID=Flang
cmake --build . -j6 --target install

# Build and install flang frontend
cd "${builddir}/flang"
git apply "${scriptdir}/fix_flang_compile.patch"
mkdir -p build && cd ./build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="${installdir}/classic-flang" -DGCC_INSTALL_PREFIX="$EBROOTGCCCORE" -DCMAKE_C_COMPILER="${installdir}/classic-flang/bin/clang" -DCMAKE_CXX_COMPILER="${installdir}/classic-flang/bin/clang++" -DCMAKE_Fortran_COMPILER="${installdir}/classic-flang/bin/flang" -DCMAKE_Fortran_COMPILER_ID=Flang -DLLVM_FORCE_ENABLE_STATS=1
cmake --build . -j6 --target install

export PATH=${installdir}/classic-flang/bin:$PATH
export LD_LIBRARY_PATH=${installdir}/classic-flang/lib:$LD_LIBRARY_PATH
export LIBRARY_PATH=${installdir}/classic-flang/lib:$LIBRARY_PATH