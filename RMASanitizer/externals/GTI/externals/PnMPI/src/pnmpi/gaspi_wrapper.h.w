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

#include <GASPI.h>
#include <PGASPI.h>

{{forallfn fn_name gaspi_atomic_max gaspi_build_infrastructure gaspi_passive_transfer_size_min gaspi_print_error}}
{{ret_type}} {{sub {{fn_name}} '^gaspi' NQgaspi}}({{formals}});
{{endforallfn}}

#include <pnmpi/xmpi.h>
#include <pnmpi/xgaspi.h>

{{forallfn fn_name gaspi_atomic_max gaspi_build_infrastructure gaspi_passive_transfer_size_min gaspi_print_error}}
#define {{fn_name}}_ID {{fn_num}}
{{endforallfn}}

{{forallfn fn_name gaspi_atomic_max gaspi_build_infrastructure gaspi_passive_transfer_size_min gaspi_print_error}}
#define Internal_X{{fn_name}} {{sub {{fn_name}} '^gaspi' NQgaspi}}
{{endforallfn}}

{{forallfn fn_name gaspi_atomic_max gaspi_build_infrastructure gaspi_passive_transfer_size_min gaspi_print_error}}
typedef {{ret_type}} (*pngaspi_int_{{fn_name}}_t)({{formals}});{{endforallfn}}

typedef struct pngaspi_functions_d
{
{{forallfn fn_name gaspi_atomic_max gaspi_build_infrastructure gaspi_passive_transfer_size_min gaspi_print_error}}  pngaspi_int_{{fn_name}}_t *pngaspi_int_{{fn_name}};
{{endforallfn}}
} pngaspi_functions_t;

#define GASPI_INITIALIZE_ALL_FUNCTION_STACKS(mods) \
{{forallfn fn_name gaspi_atomic_max gaspi_build_infrastructure gaspi_passive_transfer_size_min gaspi_print_error}}GASPI_INITIALIZE_FUNCTION_STACK("{{fn_name}}", {{fn_name}}_ID, pngaspi_int_{{fn_name}}_t, pngaspi_int_{{fn_name}}, mods, {{fn_name}});\
{{endforallfn}}
