# GPI2_DIR = /opt/GPI-2-1.3.0
# NETCDF_DIR = $(HOME)/intel64/netcdf-3.6.3
# MPI_DIR= /opt/intel/impi/5.1.2.150
CC = mpicc
BIN += hybrid.f6.exe

NUM_ITER ?= 400

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wshadow
CFLAGS += -O3 -g 
CFLAGS += -std=c99
CFLAGS += -fopenmp
CFLAGS += -DNUM_ITER=$(NUM_ITER)
#CFLAGS += -DDEBUG 

CFLAGS += -DGCC_EXTENSION
#CFLAGS += -DUSE_MPI_MULTI_THREADED
#CFLAGS += -DUSE_MPI_1_SIDED
CFLAGS += -DUSE_GASPI
#CFLAGS += -DUSE_GASPI_TEST
#CFLAGS += -DUSE_MPI_TEST_ANY
#CFLAGS += -DUSE_MPI_WAIT_ANY
#CFLAGS += -DUSE_MPI_IMMEDIATE_WAIT
#CFLAGS += -DUSE_MPI_EARLY_WAIT
#CFLAGS += -DUSE_MPI_TEST
#CFLAGS += -DUSE_MPI_TEST_MASTER_ONLY
CFLAGS += -DUSE_PACK_IN_BULK_SYNC
# CFLAGS += -DUSE_PARALLEL_GATHER
# CFLAGS += -DUSE_PARALLEL_SCATTER
CFLAGS += -DUSE_NTHREADS=1

# Select solvers
# CFLAGS += -DSOLVER_COMM_FREE=1
# CFLAGS += -DSOLVER_MPI_BULK_SYNC=1
# CFLAGS += -DSOLVER_MPI_BULK_SYNC_EARLY_RECV=1
# CFLAGS += -DSOLVER_MPI_ASYNC=1
CFLAGS += -DSOLVER_GASPI_BULK_SYNC=1
#CFLAGS += -DSOLVER_GASPI_ASYNC=1
# CFLAGS += -DSOLVER_MPI_PUT_FENCE_SYNC=1
# CFLAGS += -DSOLVER_MPI_PUT_FENCE_ASYNC=1
# CFLAGS += -DSOLVER_MPI_PUT_PSCW_SYNC=1
# CFLAGS += -DSOLVER_MPI_PUT_PSCW_ASYNC=1

# Set if infrastructure should be built dynamically, if not, then remove this flag
CFLAGS += -DGASPI_BUILD_INFRASTRUCTURE_DYNAMIC=1

###############################################################################

# INCLUDE_DIR += /usr/include
# INCLUDE_DIR += $(NETCDF_DIR)/include 
# INCLUDE_DIR += $(MPI_DIR)/include 
# INCLUDE_DIR += $(GPI2_DIR)/include 
INCLUDE_DIR += ..

# LIBRARY_DIR += $(NETCDF_DIR)/lib
# LIBRARY_DIR += $(MPI_DIR)/lib
# LIBRARY_DIR += $(GPI2_DIR)/lib64

LDFLAGS += $(addprefix -L,$(LIBRARY_DIR))
CFLAGS += $(addprefix -I,$(INCLUDE_DIR))

OBJ += solver
OBJ += comm_data
OBJ += solver_data
OBJ += error_handling
OBJ += read_netcdf
OBJ += exchange_data_mpi
OBJ += exchange_data_gaspi
OBJ += exchange_data_mpidma
OBJ += gradients
OBJ += flux
OBJ += rangelist
OBJ += threads
OBJ += eval
OBJ += thread_comm
OBJ += points_of_color
OBJ += waitsome
OBJ += queue
OBJ += util

LIB += GPI2
#LIB += ibverbs
#LIB += mpich
#LIB += mpi_mt
#LIB += mpi
LIB += netcdf
LIB += m

###############################################################################

default: $(BIN)

%.exe: %.o $(addsuffix .o, $(OBJ))
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(addprefix -l, $(LIB))

###############################################################################

.PHONY: clean objclean

objclean:
	rm -f *.o

clean: objclean
	rm -f $(BIN)
