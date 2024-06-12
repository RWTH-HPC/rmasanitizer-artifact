# Part of the MUST Project, under BSD-3-Clause License
# See https://hpc.rwth-aachen.de/must/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

# @file CMakeLists.cmake
#       CMake file for the modules/GASPIBase directory.
#
# @author Yussur Mustafa Oraji
# @date 04.09.2023

if (ENABLE_GASPI)
    # Configure file...
    CONFIGURE_FILE(BaseGASPIHandling.h.in "${CMAKE_CURRENT_BINARY_DIR}/BaseGASPIHandling.h")
    # ...and install
    MUST_INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/BaseGASPIHandling.h" DESTINATION include)
endif()
