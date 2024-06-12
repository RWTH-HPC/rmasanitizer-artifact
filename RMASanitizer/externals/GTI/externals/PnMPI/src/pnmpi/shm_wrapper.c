/* This file is part of P^nMPI.
 *
 * Copyright (c)
 *  2008-2019 Lawrence Livermore National Laboratories, United States of America
 *  2011-2016 ZIH, Technische Universitaet Dresden, Federal Republic of Germany
 *  2013-2019 RWTH Aachen University, Federal Republic of Germany
 *
 *
 * P^nMPI is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation version 2.1 dated February 1999.
 *
 * P^nMPI is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with P^nMPI; if not, write to the
 *
 *   Free Software Foundation, Inc.
 *   51 Franklin St, Fifth Floor
 *   Boston, MA 02110, USA
 *
 *
 * Written by Martin Schulz, schulzm@llnl.gov.
 *
 * LLNL-CODE-402774
 */

#include <stdarg.h>

#include "core.h"
#include "pnmpi-config.h"
#include <shmem.h>
#include <pnmpi/debug_io.h>
#include <pnmpi/private/force_link.h>
#include <pnmpi/private/function_address.h>
#include <pnmpi/private/initialization.h>
#include <pnmpi/private/modules.h>
#include <pnmpi/private/mpi_interface.h>
#include <pnmpi/private/mpi_reentry.h>
#include <pnmpi/private/pmpi.h>
#include <pnmpi/private/pmpi_assert.h>
#include <pnmpi/private/return_address.h>
#include <pnmpi/private/tls.h>
#include <pnmpi/private/self_base_address.h>

/* Special wrappers not covered by the generator */
#ifdef EXPERIMENTAL_UNWIND
#define UNW_LOCAL_ONLY
#include <libunwind.h>
#endif


/* Map the old debug macros to the new debug functions and macros.
 *
 * WARNING:
 * - These macros are not portable to non-GCC compatible compilers, as
 *   ##__VA_ARGS__ is a GNU extension.
 * - These macros are for legacy support only. Use the functions and macros
 *   defined in debug_io.h for new code!
 */
#define WARNPRINT(format, ...) PNMPI_Warning(format "\n", ##__VA_ARGS__);
#define DBGPRINT3(format, ...) \
  PNMPI_Debug(PNMPI_DEBUG_CALL, format "\n", ##__VA_ARGS__);

/* Enable all debug levels, as checking the debug level to print is part of
 * pnmpi_debug now. */
#define DBGLEVEL


extern void *MPIR_ToPointer(int idx);


_EXTERN_C_ void Pshmem_init();
_EXTERN_C_ void internal_shmem_init() { 

{ 
  WRAP_MPI_CALL_PREFIX
  //DBGPRINT3("Entering Old {{fn_name}} at base level - Location = %px",&({{fn_name}}));
  WRAP_MPI_CALL_POSTFIX

  if (SHM_NOT_ACTIVATED(shmem_init_ID))
  { // in case we have no registered function of this type and we call PMPI directly, a subsequent call from the mpi library starts at level1
    int start_level = pnmpi_level;
    pnmpi_level = pnmpi_max_level;
    WRAP_MPI_CALL_PREFIX
    pshmem_init();
    WRAP_MPI_CALL_POSTFIX
    pnmpi_level = start_level;
    return;
  }
  else if (get_pnmpi_mpi_level() > 0)
  {
    WRAP_MPI_CALL_PREFIX
    return pshmem_init();
    WRAP_MPI_CALL_POSTFIX
  }
  else
    {
    /* Store the return address to the application, and the address of the
     * original MPI call, so modules may check the origin of this MPI call. */
    pnmpi_set_return_address();
    pnmpi_set_function_address(shmem_init);

    WRAP_MPI_CALL_PREFIX
    Internal_Xshmem_init();
    WRAP_MPI_CALL_POSTFIX

    /* Reset the return and function address to the default one. */
    pnmpi_reset_return_address();
    pnmpi_reset_function_address();

    return;
  }
}
}

void NQshmem_init()
{
  
  int start_level = pnmpi_level;

  if (SHM_IS_ACTIVATED(shmem_init_ID) && (get_pnmpi_mpi_level() == 0) && (pnmpi_initialization_complete > 0))
    {
       while ((pnmpi_level<pnmpi_max_level) && (modules.module[pnmpi_level]->stack_delimiter==0))
        {
          if (pnshmem_function_ptrs.pnshmem_int_shmem_init[pnmpi_level]!=NULL)
	    {
          WRAP_MPI_CALL_PREFIX
          //DBGPRINT3("Calling a wrapper in {{fn_name}} at level %i FROM %px",pnmpi_level,&(Internal_X{{fn_name}}));
          (pnshmem_function_ptrs.pnshmem_int_shmem_init)[pnmpi_level]();
          WRAP_MPI_CALL_POSTFIX
	      //DBGPRINT3("Done with wrapper in {{fn_name}} at level %i - reseting to %i",pnmpi_level,start_level);
	      pnmpi_level = start_level;
	      return;
            }
          ++pnmpi_level;
       }
    }

  //DBGPRINT3("Calling a original MPI in {{fn_name}}");
  WRAP_MPI_CALL_PREFIX
  pshmem_init();
  WRAP_MPI_CALL_POSTFIX
  //DBGPRINT3("Done with original MPI in {{fn_name}}");
  pnmpi_level = start_level;
  return;
}


/* ================== C Wrappers for shmem_init_thread ================== */
_EXTERN_C_ int Pshmem_init_thread(int requested, int *provided);
_EXTERN_C_ int internal_shmem_init_thread(int requested, int *provided) { 
    int _wrap_py_return_val = 0;

{
  int res;
  WRAP_MPI_CALL_PREFIX
  //DBGPRINT3("Entering Old {{fn_name}} at base level - Location = %px",&({{fn_name}}));
  WRAP_MPI_CALL_POSTFIX

  if (SHM_NOT_ACTIVATED(shmem_init_thread_ID))
  { // in case we have no registered function of this type and we call PMPI directly, a subsequent call from the mpi library starts at level1
    int start_level = pnmpi_level;
    pnmpi_level = pnmpi_max_level;
    WRAP_MPI_CALL_PREFIX
    res = pshmem_init_thread(requested, provided);
    WRAP_MPI_CALL_POSTFIX
    pnmpi_level = start_level;
    return res;
  }
  else if (get_pnmpi_mpi_level() > 0)
  {
    WRAP_MPI_CALL_PREFIX
    return pshmem_init_thread(requested, provided);
    WRAP_MPI_CALL_POSTFIX
  }
  else
    {
    /* Store the return address to the application, and the address of the
     * original MPI call, so modules may check the origin of this MPI call. */
    pnmpi_set_return_address();
    pnmpi_set_function_address(shmem_init_thread);

    WRAP_MPI_CALL_PREFIX
    res = Internal_Xshmem_init_thread(requested, provided);
    WRAP_MPI_CALL_POSTFIX

    /* Reset the return and function address to the default one. */
    pnmpi_reset_return_address();
    pnmpi_reset_function_address();

    return res;
  }
}
    return _wrap_py_return_val;
}

int NQshmem_init_thread(int requested, int *provided)
{
  int res;
  int start_level = pnmpi_level;

  if (SHM_IS_ACTIVATED(shmem_init_thread_ID) && (get_pnmpi_mpi_level() == 0) && (pnmpi_initialization_complete > 0))
    {
       while ((pnmpi_level<pnmpi_max_level) && (modules.module[pnmpi_level]->stack_delimiter==0))
        {
          if (pnshmem_function_ptrs.pnshmem_int_shmem_init_thread[pnmpi_level]!=NULL)
	    {
          WRAP_MPI_CALL_PREFIX
          //DBGPRINT3("Calling a wrapper in {{fn_name}} at level %i FROM %px",pnmpi_level,&(Internal_X{{fn_name}}));
          res = (pnshmem_function_ptrs.pnshmem_int_shmem_init_thread)[pnmpi_level](requested, provided);
          WRAP_MPI_CALL_POSTFIX
	      //DBGPRINT3("Done with wrapper in {{fn_name}} at level %i - reseting to %i",pnmpi_level,start_level);
	      pnmpi_level = start_level;
	      return res;
            }
          ++pnmpi_level;
       }
    }

  //DBGPRINT3("Calling a original MPI in {{fn_name}}");
  WRAP_MPI_CALL_PREFIX
  res = pshmem_init_thread(requested, provided);
  WRAP_MPI_CALL_POSTFIX
  //DBGPRINT3("Done with original MPI in {{fn_name}}");
  pnmpi_level = start_level;
  return res;
}


/* ================== C Wrappers for shmem_finalize ================== */
_EXTERN_C_ void Pshmem_finalize();
_EXTERN_C_ void internal_shmem_finalize() { 

{
  
  WRAP_MPI_CALL_PREFIX
  //DBGPRINT3("Entering Old {{fn_name}} at base level - Location = %px",&({{fn_name}}));
  WRAP_MPI_CALL_POSTFIX

  if (SHM_NOT_ACTIVATED(shmem_finalize_ID))
  { // in case we have no registered function of this type and we call PMPI directly, a subsequent call from the mpi library starts at level1
    int start_level = pnmpi_level;
    pnmpi_level = pnmpi_max_level;
    WRAP_MPI_CALL_PREFIX
    pshmem_finalize();
    WRAP_MPI_CALL_POSTFIX
    pnmpi_level = start_level;
    return;
  }
  else if (get_pnmpi_mpi_level() > 0)
  {
    WRAP_MPI_CALL_PREFIX
    return pshmem_finalize();
    WRAP_MPI_CALL_POSTFIX
  }
  else
    {
    /* Store the return address to the application, and the address of the
     * original MPI call, so modules may check the origin of this MPI call. */
    pnmpi_set_return_address();
    pnmpi_set_function_address(shmem_finalize);

    WRAP_MPI_CALL_PREFIX
    Internal_Xshmem_finalize();
    WRAP_MPI_CALL_POSTFIX

    /* Reset the return and function address to the default one. */
    pnmpi_reset_return_address();
    pnmpi_reset_function_address();

    return;
  }
}
}


void NQshmem_finalize()
{
  
  int start_level = pnmpi_level;

  if (SHM_IS_ACTIVATED(shmem_finalize_ID) && (get_pnmpi_mpi_level() == 0) && (pnmpi_initialization_complete > 0))
    {
       while ((pnmpi_level<pnmpi_max_level) && (modules.module[pnmpi_level]->stack_delimiter==0))
        {
          if (pnshmem_function_ptrs.pnshmem_int_shmem_finalize[pnmpi_level]!=NULL)
	    {
          WRAP_MPI_CALL_PREFIX
          //DBGPRINT3("Calling a wrapper in {{fn_name}} at level %i FROM %px",pnmpi_level,&(Internal_X{{fn_name}}));
          (pnshmem_function_ptrs.pnshmem_int_shmem_finalize)[pnmpi_level]();
          WRAP_MPI_CALL_POSTFIX
	      //DBGPRINT3("Done with wrapper in {{fn_name}} at level %i - reseting to %i",pnmpi_level,start_level);
	      pnmpi_level = start_level;
	      return;
            }
          ++pnmpi_level;
       }
    }

  //DBGPRINT3("Calling a original MPI in {{fn_name}}");
  WRAP_MPI_CALL_PREFIX
  pshmem_finalize();
  WRAP_MPI_CALL_POSTFIX
  //DBGPRINT3("Done with original MPI in {{fn_name}}");
  pnmpi_level = start_level;
  return;
}


/* shmem_init */
void shmem_init() {
    /**
     * We call MPI_Init (if not already initialized) here in a way
     * in which we wrap it by ourselves. This is crucial as we use
     * that call to initialize ourselves.
     */
    int initialized = 0;
    MPI_Initialized(&initialized);

    pnmpi_set_return_address();
    pnmpi_set_function_address(pshmem_init);
    pnmpi_set_self_base_address(shmem_init);
    pnmpi_set_self_base_address(shmem_init);

    if (!initialized) {
        int provided, requested = MPI_THREAD_MULTIPLE;
        MPI_Init_thread(NULL, NULL, requested, &provided);
        if (requested > provided) {
            printf("PNMPI requested MPI thread level %d, but got thread level %d\n", requested, provided);
        }
    }

    // Recurse in PNMPI layer
    internal_shmem_init();

    pnmpi_reset_return_address();
    pnmpi_reset_function_address();
}


/* shmem_init_thread */
int shmem_init_thread(int requested, int *provided) {
    /**
     * We call MPI_Init (if not already initialized) here in a way
     * in which we wrap it by ourselves. This is crucial as we use
     * that call to initialize ourselves.
     */
    int initialized = 0;
    MPI_Initialized(&initialized);

    pnmpi_set_return_address();
    pnmpi_set_function_address(pshmem_init_thread);
    pnmpi_set_self_base_address(shmem_init_thread);
    pnmpi_set_self_base_address(shmem_init_thread);

    if (!initialized) {
        int provided, requested = MPI_THREAD_MULTIPLE;
        MPI_Init_thread(NULL, NULL, requested, &provided);
        if (requested > provided) {
            printf("PNMPI requested MPI thread level %d, but got thread level %d\n", requested, provided);
        }
    }

    // Recurse in PNMPI layer
    int ret = internal_shmem_init_thread(requested, provided);

    pnmpi_reset_return_address();
    pnmpi_reset_function_address();

    return ret;
}

/* shmem_finalize */
void shmem_finalize() {
    // Recurse in PNMPI layer
    internal_shmem_finalize();

    // finalize MPI
    MPI_Finalize();
}


/*-------------------------------------------------------------------*/
/* The End. */

//#ifdef COMPILE_FOR_FORTRAN
//#include "wrapper_cf.c"
//#else
#include "shm_wrapper_c.c"
//#endif
