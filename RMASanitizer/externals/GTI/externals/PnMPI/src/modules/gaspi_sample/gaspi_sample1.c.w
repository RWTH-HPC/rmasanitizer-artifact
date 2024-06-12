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

/* \brief Count MPI calls.
 *
 * \details This module counts how often each MPI call was invoked. Before MPI
 *  finalizes, statistics will be printed for each rank and a sum of the made
 *  calls by all ranks.
 */


#include <stdio.h>

#include <mpi.h>
#include <GASPI.h>
#include <pnmpi/debug_io.h>
#include <pnmpi/hooks.h>
#include <pnmpi/private/pmpi_assert.h>
#include <pnmpi/xmpi.h>

#include "pnmpi-atomic.h"

/* If there is no atomic support, we'll limit the threading level of this module
 * to MPI_THREAD_SERIALIZED, so it is safe to use with threaded applications
 * (but they may become slower!). */
#if defined(METRIC_NO_ATOMIC)
const int PNMPI_SupportedThreadingLevel = MPI_THREAD_SERIALIZED;
#endif

/* Generate wrapper functions for all GASPI calls */

{{fnall fn_name}}
  int _wrap_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &_wrap_rank);
  printf("[%d] Called: %s\n", _wrap_rank, "{{fn_name}}")
  {{callfn}}
{{endfnall}}
