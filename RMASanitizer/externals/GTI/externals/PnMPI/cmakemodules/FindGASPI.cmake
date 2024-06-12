# Find GASPI installation
#  GASPI_FOUND - System has GASPI
#  GASPI_INCLUDE_DIRS - Include directories for GASPI.h, PGASPI.h, ...
#  GASPI_LIBRARIES - Paths to GASPI library files


FIND_LIBRARY(GASPI_LIBRARY NAMES GPI2) 

MESSAGE (STATUS "Found GASPI library: " ${GASPI_LIBRARY})

get_filename_component(_GASPI_LIBRARY_DIR "${GASPI_LIBRARY}" DIRECTORY)

FIND_PATH(GASPI_INCLUDE_DIR NAMES GASPI.h HINTS "${_GASPI_LIBRARY_DIR}/../include")
 
INCLUDE(FindPackageHandleStandardArgs)

find_package_handle_standard_args(GASPI DEFAULT_MSG
                                  GASPI_LIBRARY GASPI_INCLUDE_DIR)

mark_as_advanced(GASPI_INCLUDE_DIR GASPI_LIBRARY)

SET(GASPI_LIBRARIES ${GASPI_LIBRARY})
SET(GASPI_INCLUDE_DIRS ${GASPI_INCLUDE_DIR})
