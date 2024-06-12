# Find OpenSHMEM installation
#  OpenSHMEM_FOUND - System has OpenSHMEM
#  OpenSHMEM_INCLUDE_DIRS - Include directories for shmem.h, pshmem.h, ...
#  OpenSHMEM_LIBRARIES - Paths to OpenSHMEM library files


FIND_LIBRARY(OpenSHMEM_LIBRARY NAMES oshmem sma) 

MESSAGE (STATUS "Found OpenSHMEM library: " ${OpenSHMEM_LIBRARY})

get_filename_component(_OpenSHMEM_LIBRARY_DIR "${OpenSHMEM_LIBRARY}" DIRECTORY)

FIND_PATH(OpenSHMEM_INCLUDE_DIR NAMES shmem.h HINTS "${_OpenSHMEM_LIBRARY_DIR}/../include")
 
INCLUDE(FindPackageHandleStandardArgs)

find_package_handle_standard_args(OpenSHMEM DEFAULT_MSG
                                  OpenSHMEM_LIBRARY OpenSHMEM_INCLUDE_DIR)

mark_as_advanced(OpenSHMEM_INCLUDE_DIR OpenSHMEM_LIBRARY)

SET(OpenSHMEM_LIBRARIES ${OpenSHMEM_LIBRARY})
SET(OpenSHMEM_INCLUDE_DIRS ${OpenSHMEM_INCLUDE_DIR})
