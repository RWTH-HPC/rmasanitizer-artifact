# Copyright (c) 2008, Lawrence Livermore National Security, LLC. 
# Written by Martin Schulz, schulzm@llnl.gov, LLNL-CODE-402774,
# All rights reserved - please read information in "LICENCSE"

cmake_minimum_required(VERSION 3.13.4...3.27.4)
project(wrap)

# @authors Todd Gamblin, Tobias Hilbrich, Martin Schulz
# @date 2011-05-01

# Install wrap.py into the project binary directory
install(PROGRAMS wrap.py DESTINATION bin)
install(PROGRAMS osh_wrap.py DESTINATION bin)

# Set the module search path to include local modules.
set(CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmakemodules"
  ${CMAKE_MODULE_PATH})

option(ENABLE_OPENSHMEM "Enable OpenSHMEM support" false)
option(ENABLE_GASPI "Enable GASPI support" false)

if (ENABLE_OPENSHMEM)
  find_package(OpenSHMEM REQUIRED)
endif ()
if (ENABLE_GASPI)
  find_package(GASPI REQUIRED)
endif ()

# Install WrapConfig into the project CMake config directory so that
# wrap.py can be used by subprojects.
set(WRAP ${CMAKE_INSTALL_PREFIX}/bin/wrap.py)
if (ENABLE_OPENSHMEM)
  set(shmem_WRAP ${CMAKE_INSTALL_PREFIX}/bin/osh_wrap.py)
endif ()
if (ENABLE_GASPI)
  set(gaspi_WRAP ${CMAKE_INSTALL_PREFIX}/bin/gaspi_wrap.py)
endif ()
set(GETSTATUSSIZE ${CMAKE_INSTALL_PREFIX}/src/wrap/getStatusSize.f)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/wrap-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/wrap-config.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/wrap-config.cmake DESTINATION
share/cmake/wrap)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/getStatusSize.f DESTINATION
src/wrap/)
