# Part of the MUST Project, under BSD-3-Clause License
# See https://hpc.rwth-aachen.de/must/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

# @file CMakeLists.cmake
#       CMake file for the modules/ShmemBase directory.
#
# @author Yussur Mustafa Oraji
# @date 27.09.2023

if (ENABLE_OPENSHMEM)
    # Configure file...
    CONFIGURE_FILE(BaseShmemHandling.h.in "${CMAKE_CURRENT_BINARY_DIR}/BaseShmemHandling.h")
    # ...and install
    MUST_INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/BaseShmemHandling.h" DESTINATION include)
endif()
