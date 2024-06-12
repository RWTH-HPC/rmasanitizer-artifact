// DO NOT EDIT!
// On specification update: Copy header and format to be compatible to bash script.
// Can use clang-format. Config file in project root seems compatible with script, just need to
// increase column limit -> inf.
// Additionally:
//   - Delete C++ overload and C11 portion of header
//   - Remove alternative definitions of shmem_global_exit
//   - Delete sections marked as "Special case"

/* -*- C -*-
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S.  Government
 * retains certain rights in this software.
 *
 * Copyright (c) 2016 Intel Corporation. All rights reserved.
 * This software is available to you under the BSD license.
 *
 * This file is part of the Sandia OpenSHMEM software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
 *
 */

/*
 * This is a generated file, do not edit directly.
 */

#ifndef SHMEM_H
#define SHMEM_H

#include <stddef.h>
#include <stdint.h>
#include <shmem.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SHMEM_FUNCTION_ATTRIBUTES
#if SHMEM_HAVE_ATTRIBUTE_VISIBILITY == 1
#define SHMEM_FUNCTION_ATTRIBUTES __attribute__((visibility("default")))
#else
#define SHMEM_FUNCTION_ATTRIBUTES
#endif
#endif

#ifndef SHMEM_ATTRIBUTE_DEPRECATED
#if SHMEM_HAVE_ATTRIBUTE_DEPRECATED == 1
#define SHMEM_ATTRIBUTE_DEPRECATED __attribute__((deprecated))
#else
#define SHMEM_ATTRIBUTE_DEPRECATED
#endif
#endif

/* Library Setup, Exit, and Query Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_init(void);
SHMEM_FUNCTION_ATTRIBUTES int shmem_init_thread(int requested, int* provided);
SHMEM_FUNCTION_ATTRIBUTES void shmem_query_thread(int* provided);
SHMEM_FUNCTION_ATTRIBUTES void shmem_finalize(void);
SHMEM_FUNCTION_ATTRIBUTES int shmem_n_pes(void);
SHMEM_FUNCTION_ATTRIBUTES int shmem_my_pe(void);
SHMEM_FUNCTION_ATTRIBUTES void shmem_global_exit(int status);

SHMEM_FUNCTION_ATTRIBUTES int shmem_pe_accessible(int pe);
SHMEM_FUNCTION_ATTRIBUTES int shmem_addr_accessible(const void* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES void* shmem_ptr(const void* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void* shmem_team_ptr(shmem_team_t team, const void* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_info_get_version(int* major, int* minor);
SHMEM_FUNCTION_ATTRIBUTES void shmem_info_get_name(char* name);

/* Memory Management Routines */
SHMEM_FUNCTION_ATTRIBUTES void* shmem_malloc(size_t size);
SHMEM_FUNCTION_ATTRIBUTES void* shmem_calloc(size_t count, size_t size);
SHMEM_FUNCTION_ATTRIBUTES void* shmem_align(size_t alignment, size_t size);
SHMEM_FUNCTION_ATTRIBUTES void* shmem_realloc(void* ptr, size_t size);
SHMEM_FUNCTION_ATTRIBUTES void shmem_free(void* ptr);

/* Communicatoin Management Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_create(long options, shmem_ctx_t* ctx);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_destroy(shmem_ctx_t ctx);

/* RMA: Elemental Data Put Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_p(float* addr, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_p(double* addr, double value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_p(long double* addr, long double value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_p(char* addr, char value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_p(signed char* addr, signed char value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_p(short* addr, short value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_p(int* addr, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_p(long* addr, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_p(long long* addr, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_p(unsigned char* addr, unsigned char value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_p(unsigned short* addr, unsigned short value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_p(unsigned int* addr, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_p(unsigned long* addr, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_p(unsigned long long* addr, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_p(int8_t* addr, int8_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_p(int16_t* addr, int16_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_p(int32_t* addr, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_p(int64_t* addr, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_p(uint8_t* addr, uint8_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_p(uint16_t* addr, uint16_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_p(uint32_t* addr, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_p(uint64_t* addr, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_p(size_t* addr, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_p(ptrdiff_t* addr, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_p(shmem_ctx_t ctx, float* addr, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_p(shmem_ctx_t ctx, double* addr, double value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_p(shmem_ctx_t ctx, long double* addr, long double value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_p(shmem_ctx_t ctx, char* addr, char value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_p(shmem_ctx_t ctx, signed char* addr, signed char value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_p(shmem_ctx_t ctx, short* addr, short value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_p(shmem_ctx_t ctx, int* addr, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_p(shmem_ctx_t ctx, long* addr, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_p(shmem_ctx_t ctx, long long* addr, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_p(shmem_ctx_t ctx, unsigned char* addr, unsigned char value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_p(shmem_ctx_t ctx, unsigned short* addr, unsigned short value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_p(shmem_ctx_t ctx, unsigned int* addr, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_p(shmem_ctx_t ctx, unsigned long* addr, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_p(shmem_ctx_t ctx, unsigned long long* addr, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_p(shmem_ctx_t ctx, int8_t* addr, int8_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_p(shmem_ctx_t ctx, int16_t* addr, int16_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_p(shmem_ctx_t ctx, int32_t* addr, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_p(shmem_ctx_t ctx, int64_t* addr, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_p(shmem_ctx_t ctx, uint8_t* addr, uint8_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_p(shmem_ctx_t ctx, uint16_t* addr, uint16_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_p(shmem_ctx_t ctx, uint32_t* addr, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_p(shmem_ctx_t ctx, uint64_t* addr, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_p(shmem_ctx_t ctx, size_t* addr, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_p(shmem_ctx_t ctx, ptrdiff_t* addr, ptrdiff_t value, int pe);

/* RMA: Contiguous Data Put Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_put(float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_put(double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_put(long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_put(char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_put(signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_put(short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_put(int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_put(long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_put(long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_put(unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_put(unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_put(unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_put(unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_put(unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_put(int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_put(int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_put(int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_put(int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_put(uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_put(uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_put(uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_put(uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_put(size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_put(ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_put(shmem_ctx_t ctx, float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_put(shmem_ctx_t ctx, double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_put(shmem_ctx_t ctx, long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_put(shmem_ctx_t ctx, char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_put(shmem_ctx_t ctx, signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_put(shmem_ctx_t ctx, short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_put(shmem_ctx_t ctx, int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_put(shmem_ctx_t ctx, long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_put(shmem_ctx_t ctx, long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_put(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_put(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_put(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_put(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_put(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_put(shmem_ctx_t ctx, int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_put(shmem_ctx_t ctx, int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_put(shmem_ctx_t ctx, int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_put(shmem_ctx_t ctx, int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_put(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_put(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_put(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_put(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_put(shmem_ctx_t ctx, size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_put(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_put8(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put16(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put32(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put64(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put128(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_putmem(void* target, const void* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put8(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put16(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put32(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put64(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put128(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_putmem(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);

/* Blocking put with signal */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_put_signal(float* target, const float* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_put_signal(double* target, const double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_put_signal(long double* target, const long double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_put_signal(char* target, const char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_put_signal(signed char* target, const signed char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_put_signal(short* target, const short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_put_signal(int* target, const int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_put_signal(long* target, const long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_put_signal(long long* target, const long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_put_signal(unsigned char* target, const unsigned char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_put_signal(unsigned short* target, const unsigned short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_put_signal(unsigned int* target, const unsigned int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_put_signal(unsigned long* target, const unsigned long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_put_signal(unsigned long long* target, const unsigned long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_put_signal(int8_t* target, const int8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_put_signal(int16_t* target, const int16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_put_signal(int32_t* target, const int32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_put_signal(int64_t* target, const int64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_put_signal(uint8_t* target, const uint8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_put_signal(uint16_t* target, const uint16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_put_signal(uint32_t* target, const uint32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_put_signal(uint64_t* target, const uint64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_put_signal(size_t* target, const size_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_put_signal(ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_put_signal(shmem_ctx_t ctx, float* target, const float* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_put_signal(shmem_ctx_t ctx, double* target, const double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_put_signal(shmem_ctx_t ctx, long double* target, const long double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_put_signal(shmem_ctx_t ctx, char* target, const char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_put_signal(shmem_ctx_t ctx, signed char* target, const signed char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_put_signal(shmem_ctx_t ctx, short* target, const short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_put_signal(shmem_ctx_t ctx, int* target, const int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_put_signal(shmem_ctx_t ctx, long* target, const long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_put_signal(shmem_ctx_t ctx, long long* target, const long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_put_signal(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_put_signal(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_put_signal(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_put_signal(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_put_signal(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_put_signal(shmem_ctx_t ctx, int8_t* target, const int8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_put_signal(shmem_ctx_t ctx, int16_t* target, const int16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_put_signal(shmem_ctx_t ctx, int32_t* target, const int32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_put_signal(shmem_ctx_t ctx, int64_t* target, const int64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_put_signal(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_put_signal(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_put_signal(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_put_signal(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_put_signal(shmem_ctx_t ctx, size_t* target, const size_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_put_signal(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_put8_signal(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put16_signal(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put32_signal(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put64_signal(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put128_signal(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_putmem_signal(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put8_signal(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put16_signal(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put32_signal(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put64_signal(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put128_signal(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_putmem_signal(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

/* Non-blocking put with signal */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_put_signal_nbi(float* target, const float* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_put_signal_nbi(double* target, const double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_put_signal_nbi(long double* target, const long double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_put_signal_nbi(char* target, const char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_put_signal_nbi(signed char* target, const signed char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_put_signal_nbi(short* target, const short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_put_signal_nbi(int* target, const int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_put_signal_nbi(long* target, const long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_put_signal_nbi(long long* target, const long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_put_signal_nbi(unsigned char* target, const unsigned char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_put_signal_nbi(unsigned short* target, const unsigned short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_put_signal_nbi(unsigned int* target, const unsigned int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_put_signal_nbi(unsigned long* target, const unsigned long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_put_signal_nbi(unsigned long long* target, const unsigned long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_put_signal_nbi(int8_t* target, const int8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_put_signal_nbi(int16_t* target, const int16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_put_signal_nbi(int32_t* target, const int32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_put_signal_nbi(int64_t* target, const int64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_put_signal_nbi(uint8_t* target, const uint8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_put_signal_nbi(uint16_t* target, const uint16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_put_signal_nbi(uint32_t* target, const uint32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_put_signal_nbi(uint64_t* target, const uint64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_put_signal_nbi(size_t* target, const size_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_put_signal_nbi(ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_put_signal_nbi(shmem_ctx_t ctx, float* target, const float* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_put_signal_nbi(shmem_ctx_t ctx, double* target, const double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_put_signal_nbi(shmem_ctx_t ctx, long double* target, const long double* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_put_signal_nbi(shmem_ctx_t ctx, char* target, const char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_put_signal_nbi(shmem_ctx_t ctx, signed char* target, const signed char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_put_signal_nbi(shmem_ctx_t ctx, short* target, const short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_put_signal_nbi(shmem_ctx_t ctx, int* target, const int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_put_signal_nbi(shmem_ctx_t ctx, long* target, const long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_put_signal_nbi(shmem_ctx_t ctx, long long* target, const long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_put_signal_nbi(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_put_signal_nbi(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_put_signal_nbi(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_put_signal_nbi(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_put_signal_nbi(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_put_signal_nbi(shmem_ctx_t ctx, int8_t* target, const int8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_put_signal_nbi(shmem_ctx_t ctx, int16_t* target, const int16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_put_signal_nbi(shmem_ctx_t ctx, int32_t* target, const int32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_put_signal_nbi(shmem_ctx_t ctx, int64_t* target, const int64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_put_signal_nbi(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_put_signal_nbi(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_put_signal_nbi(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_put_signal_nbi(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_put_signal_nbi(shmem_ctx_t ctx, size_t* target, const size_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_put_signal_nbi(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_put8_signal_nbi(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put16_signal_nbi(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put32_signal_nbi(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put64_signal_nbi(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put128_signal_nbi(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_putmem_signal_nbi(void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put8_signal_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put16_signal_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put32_signal_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put64_signal_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put128_signal_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_putmem_signal_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, uint64_t* sig_addr, uint64_t signal, int sig_op, int pe);

/* RMA: Strided Put Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_iput(float* target, const float* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_iput(double* target, const double* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_iput(long double* target, const long double* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_iput(char* target, const char* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_iput(signed char* target, const signed char* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_iput(short* target, const short* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_iput(int* target, const int* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_iput(long* target, const long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_iput(long long* target, const long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_iput(unsigned char* target, const unsigned char* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_iput(unsigned short* target, const unsigned short* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_iput(unsigned int* target, const unsigned int* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_iput(unsigned long* target, const unsigned long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_iput(unsigned long long* target, const unsigned long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_iput(int8_t* target, const int8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_iput(int16_t* target, const int16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_iput(int32_t* target, const int32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_iput(int64_t* target, const int64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_iput(uint8_t* target, const uint8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_iput(uint16_t* target, const uint16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_iput(uint32_t* target, const uint32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_iput(uint64_t* target, const uint64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_iput(size_t* target, const size_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_iput(ptrdiff_t* target, const ptrdiff_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_iput(shmem_ctx_t ctx, float* target, const float* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_iput(shmem_ctx_t ctx, double* target, const double* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_iput(shmem_ctx_t ctx, long double* target, const long double* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_iput(shmem_ctx_t ctx, char* target, const char* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_iput(shmem_ctx_t ctx, signed char* target, const signed char* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_iput(shmem_ctx_t ctx, short* target, const short* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_iput(shmem_ctx_t ctx, int* target, const int* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_iput(shmem_ctx_t ctx, long* target, const long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_iput(shmem_ctx_t ctx, long long* target, const long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_iput(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_iput(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_iput(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_iput(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_iput(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_iput(shmem_ctx_t ctx, int8_t* target, const int8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_iput(shmem_ctx_t ctx, int16_t* target, const int16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_iput(shmem_ctx_t ctx, int32_t* target, const int32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_iput(shmem_ctx_t ctx, int64_t* target, const int64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_iput(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_iput(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_iput(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_iput(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_iput(shmem_ctx_t ctx, size_t* target, const size_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_iput(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_iput8(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iput16(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iput32(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iput64(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iput128(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iput8(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iput16(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iput32(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iput64(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iput128(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t len, int pe);

/* RMA: Elemental Data Get Routines */
SHMEM_FUNCTION_ATTRIBUTES float shmem_float_g(const float* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES double shmem_double_g(const double* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES long double shmem_longdouble_g(const long double* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES char shmem_char_g(const char* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES signed char shmem_schar_g(const signed char* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES short shmem_short_g(const short* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_g(const int* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_g(const long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_g(const long long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned char shmem_uchar_g(const unsigned char* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned short shmem_ushort_g(const unsigned short* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_g(const unsigned int* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_g(const unsigned long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_g(const unsigned long long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int8_t shmem_int8_g(const int8_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int16_t shmem_int16_g(const int16_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_g(const int32_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_g(const int64_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint8_t shmem_uint8_g(const uint8_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint16_t shmem_uint16_g(const uint16_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_g(const uint32_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_g(const uint64_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_g(const size_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_g(const ptrdiff_t* addr, int pe);

SHMEM_FUNCTION_ATTRIBUTES float shmem_ctx_float_g(shmem_ctx_t ctx, const float* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES double shmem_ctx_double_g(shmem_ctx_t ctx, const double* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES long double shmem_ctx_longdouble_g(shmem_ctx_t ctx, const long double* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES char shmem_ctx_char_g(shmem_ctx_t ctx, const char* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES signed char shmem_ctx_schar_g(shmem_ctx_t ctx, const signed char* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES short shmem_ctx_short_g(shmem_ctx_t ctx, const short* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_int_g(shmem_ctx_t ctx, const int* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_ctx_long_g(shmem_ctx_t ctx, const long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_ctx_longlong_g(shmem_ctx_t ctx, const long long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned char shmem_ctx_uchar_g(shmem_ctx_t ctx, const unsigned char* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned short shmem_ctx_ushort_g(shmem_ctx_t ctx, const unsigned short* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_g(shmem_ctx_t ctx, const unsigned int* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_g(shmem_ctx_t ctx, const unsigned long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_g(shmem_ctx_t ctx, const unsigned long long* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int8_t shmem_ctx_int8_g(shmem_ctx_t ctx, const int8_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int16_t shmem_ctx_int16_g(shmem_ctx_t ctx, const int16_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_g(shmem_ctx_t ctx, const int32_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_g(shmem_ctx_t ctx, const int64_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint8_t shmem_ctx_uint8_g(shmem_ctx_t ctx, const uint8_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint16_t shmem_ctx_uint16_g(shmem_ctx_t ctx, const uint16_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_g(shmem_ctx_t ctx, const uint32_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_g(shmem_ctx_t ctx, const uint64_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ctx_size_g(shmem_ctx_t ctx, const size_t* addr, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ctx_ptrdiff_g(shmem_ctx_t ctx, const ptrdiff_t* addr, int pe);

/* RMA: Contiguous Data Get Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_get(float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_get(double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_get(long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_get(char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_get(signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_get(short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_get(int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_get(long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_get(long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_get(unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_get(unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_get(unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_get(unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_get(unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_get(int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_get(int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_get(int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_get(int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_get(uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_get(uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_get(uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_get(uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_get(size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_get(ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_get(shmem_ctx_t ctx, float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_get(shmem_ctx_t ctx, double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_get(shmem_ctx_t ctx, long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_get(shmem_ctx_t ctx, char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_get(shmem_ctx_t ctx, signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_get(shmem_ctx_t ctx, short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_get(shmem_ctx_t ctx, int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_get(shmem_ctx_t ctx, long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_get(shmem_ctx_t ctx, long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_get(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_get(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_get(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_get(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_get(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_get(shmem_ctx_t ctx, int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_get(shmem_ctx_t ctx, int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_get(shmem_ctx_t ctx, int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_get(shmem_ctx_t ctx, int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_get(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_get(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_get(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_get(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_get(shmem_ctx_t ctx, size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_get(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_get8(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get16(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get32(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get64(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get128(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_getmem(void* target, const void* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get8(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get16(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get32(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get64(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get128(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_getmem(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);

/* RMA: Strided Get Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_iget(float* target, const float* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_iget(double* target, const double* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_iget(long double* target, const long double* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_iget(char* target, const char* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_iget(signed char* target, const signed char* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_iget(short* target, const short* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_iget(int* target, const int* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_iget(long* target, const long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_iget(long long* target, const long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_iget(unsigned char* target, const unsigned char* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_iget(unsigned short* target, const unsigned short* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_iget(unsigned int* target, const unsigned int* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_iget(unsigned long* target, const unsigned long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_iget(unsigned long long* target, const unsigned long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_iget(int8_t* target, const int8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_iget(int16_t* target, const int16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_iget(int32_t* target, const int32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_iget(int64_t* target, const int64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_iget(uint8_t* target, const uint8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_iget(uint16_t* target, const uint16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_iget(uint32_t* target, const uint32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_iget(uint64_t* target, const uint64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_iget(size_t* target, const size_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_iget(ptrdiff_t* target, const ptrdiff_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_iget(shmem_ctx_t ctx, float* target, const float* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_iget(shmem_ctx_t ctx, double* target, const double* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_iget(shmem_ctx_t ctx, long double* target, const long double* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_iget(shmem_ctx_t ctx, char* target, const char* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_iget(shmem_ctx_t ctx, signed char* target, const signed char* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_iget(shmem_ctx_t ctx, short* target, const short* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_iget(shmem_ctx_t ctx, int* target, const int* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_iget(shmem_ctx_t ctx, long* target, const long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_iget(shmem_ctx_t ctx, long long* target, const long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_iget(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_iget(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_iget(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_iget(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_iget(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_iget(shmem_ctx_t ctx, int8_t* target, const int8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_iget(shmem_ctx_t ctx, int16_t* target, const int16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_iget(shmem_ctx_t ctx, int32_t* target, const int32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_iget(shmem_ctx_t ctx, int64_t* target, const int64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_iget(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_iget(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_iget(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_iget(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_iget(shmem_ctx_t ctx, size_t* target, const size_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_iget(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_iget8(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iget16(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iget32(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iget64(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_iget128(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iget8(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iget16(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iget32(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iget64(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_iget128(shmem_ctx_t ctx, void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst, size_t nelems, int pe);

/* RMA: Nonblocking Contiguous Data Put Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_put_nbi(float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_put_nbi(double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_put_nbi(long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_put_nbi(char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_put_nbi(signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_put_nbi(short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_put_nbi(int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_put_nbi(long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_put_nbi(long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_put_nbi(unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_put_nbi(unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_put_nbi(unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_put_nbi(unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_put_nbi(unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_put_nbi(int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_put_nbi(int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_put_nbi(int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_put_nbi(int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_put_nbi(uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_put_nbi(uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_put_nbi(uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_put_nbi(uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_put_nbi(size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_put_nbi(ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_put_nbi(shmem_ctx_t ctx, float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_put_nbi(shmem_ctx_t ctx, double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_put_nbi(shmem_ctx_t ctx, long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_put_nbi(shmem_ctx_t ctx, char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_put_nbi(shmem_ctx_t ctx, signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_put_nbi(shmem_ctx_t ctx, short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_put_nbi(shmem_ctx_t ctx, int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_put_nbi(shmem_ctx_t ctx, long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_put_nbi(shmem_ctx_t ctx, long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_put_nbi(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_put_nbi(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_put_nbi(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_put_nbi(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_put_nbi(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_put_nbi(shmem_ctx_t ctx, int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_put_nbi(shmem_ctx_t ctx, int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_put_nbi(shmem_ctx_t ctx, int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_put_nbi(shmem_ctx_t ctx, int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_put_nbi(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_put_nbi(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_put_nbi(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_put_nbi(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_put_nbi(shmem_ctx_t ctx, size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_put_nbi(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_put8_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put16_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put32_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put64_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_put128_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_putmem_nbi(void* target, const void* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put8_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put16_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put32_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put64_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_put128_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_putmem_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);

/* RMA: Nonblocking Contiguous Data Get Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_get_nbi(float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_get_nbi(double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_get_nbi(long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_char_get_nbi(char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_schar_get_nbi(signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_get_nbi(short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_get_nbi(int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_get_nbi(long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_get_nbi(long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uchar_get_nbi(unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_get_nbi(unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_get_nbi(unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_get_nbi(unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_get_nbi(unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int8_get_nbi(int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int16_get_nbi(int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_get_nbi(int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_get_nbi(int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint8_get_nbi(uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint16_get_nbi(uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_get_nbi(uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_get_nbi(uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_get_nbi(size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_get_nbi(ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_get_nbi(shmem_ctx_t ctx, float* target, const float* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_get_nbi(shmem_ctx_t ctx, double* target, const double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longdouble_get_nbi(shmem_ctx_t ctx, long double* target, const long double* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_char_get_nbi(shmem_ctx_t ctx, char* target, const char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_schar_get_nbi(shmem_ctx_t ctx, signed char* target, const signed char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_short_get_nbi(shmem_ctx_t ctx, short* target, const short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_get_nbi(shmem_ctx_t ctx, int* target, const int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_get_nbi(shmem_ctx_t ctx, long* target, const long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_get_nbi(shmem_ctx_t ctx, long long* target, const long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uchar_get_nbi(shmem_ctx_t ctx, unsigned char* target, const unsigned char* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ushort_get_nbi(shmem_ctx_t ctx, unsigned short* target, const unsigned short* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_get_nbi(shmem_ctx_t ctx, unsigned int* target, const unsigned int* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_get_nbi(shmem_ctx_t ctx, unsigned long* target, const unsigned long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_get_nbi(shmem_ctx_t ctx, unsigned long long* target, const unsigned long long* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int8_get_nbi(shmem_ctx_t ctx, int8_t* target, const int8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int16_get_nbi(shmem_ctx_t ctx, int16_t* target, const int16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_get_nbi(shmem_ctx_t ctx, int32_t* target, const int32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_get_nbi(shmem_ctx_t ctx, int64_t* target, const int64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint8_get_nbi(shmem_ctx_t ctx, uint8_t* target, const uint8_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint16_get_nbi(shmem_ctx_t ctx, uint16_t* target, const uint16_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_get_nbi(shmem_ctx_t ctx, uint32_t* target, const uint32_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_get_nbi(shmem_ctx_t ctx, uint64_t* target, const uint64_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_get_nbi(shmem_ctx_t ctx, size_t* target, const size_t* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_get_nbi(shmem_ctx_t ctx, ptrdiff_t* target, const ptrdiff_t* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_get8_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get16_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get32_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get64_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_get128_nbi(void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_getmem_nbi(void* target, const void* source, size_t nelems, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get8_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get16_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get32_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get64_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_get128_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_getmem_nbi(shmem_ctx_t ctx, void* target, const void* source, size_t nelems, int pe);

/* AMO: Atomic Swap Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_swap(int* target, int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_swap(long* target, long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_swap(long long* target, long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_swap(unsigned int* target, unsigned int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_swap(unsigned long* target, unsigned long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_swap(unsigned long long* target, unsigned long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_swap(int32_t* target, int32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_swap(int64_t* target, int64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_swap(uint32_t* target, uint32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_swap(uint64_t* target, uint64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_swap(size_t* target, size_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_swap(ptrdiff_t* target, ptrdiff_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES float shmem_float_swap(float* target, float value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES double shmem_double_swap(double* target, double value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES int shmem_int_atomic_swap(int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_atomic_swap(long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_atomic_swap(long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_swap(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_swap(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_swap(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_swap(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_swap(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_swap(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_swap(uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_atomic_swap(size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_atomic_swap(ptrdiff_t* target, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES float shmem_float_atomic_swap(float* target, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES double shmem_double_atomic_swap(double* target, double value, int pe);

SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_int_atomic_swap(shmem_ctx_t ctx, int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_ctx_long_atomic_swap(shmem_ctx_t ctx, long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_ctx_longlong_atomic_swap(shmem_ctx_t ctx, long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_swap(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_swap(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_swap(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_swap(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_swap(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_swap(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_swap(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ctx_size_atomic_swap(shmem_ctx_t ctx, size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ctx_ptrdiff_atomic_swap(shmem_ctx_t ctx, ptrdiff_t* target, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES float shmem_ctx_float_atomic_swap(shmem_ctx_t ctx, float* target, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES double shmem_ctx_double_atomic_swap(shmem_ctx_t ctx, double* target, double value, int pe);

/* AMO: Atomic Conditional Swap Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_cswap(int* target, int cond, int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_cswap(long* target, long cond, long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_cswap(long long* target, long long cond, long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_cswap(unsigned int* target, unsigned int cond, unsigned int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_cswap(unsigned long* target, unsigned long cond, unsigned long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_cswap(unsigned long long* target, unsigned long long cond, unsigned long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_cswap(int32_t* target, int32_t cond, int32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_cswap(int64_t* target, int64_t cond, int64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_cswap(uint32_t* target, uint32_t cond, uint32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_cswap(uint64_t* target, uint64_t cond, uint64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_cswap(size_t* target, size_t cond, size_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_cswap(ptrdiff_t* target, ptrdiff_t cond, ptrdiff_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES int shmem_int_atomic_compare_swap(int* target, int cond, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_atomic_compare_swap(long* target, long cond, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_atomic_compare_swap(long long* target, long long cond, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_compare_swap(unsigned int* target, unsigned int cond, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_compare_swap(unsigned long* target, unsigned long cond, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_compare_swap(unsigned long long* target, unsigned long long cond, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_compare_swap(int32_t* target, int32_t cond, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_compare_swap(int64_t* target, int64_t cond, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_compare_swap(uint32_t* target, uint32_t cond, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_compare_swap(uint64_t* target, uint64_t cond, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_atomic_compare_swap(size_t* target, size_t cond, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_atomic_compare_swap(ptrdiff_t* target, ptrdiff_t cond, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_int_atomic_compare_swap(shmem_ctx_t ctx, int* target, int cond, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_ctx_long_atomic_compare_swap(shmem_ctx_t ctx, long* target, long cond, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_ctx_longlong_atomic_compare_swap(shmem_ctx_t ctx, long long* target, long long cond, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_compare_swap(shmem_ctx_t ctx, unsigned int* target, unsigned int cond, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_compare_swap(shmem_ctx_t ctx, unsigned long* target, unsigned long cond, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_compare_swap(shmem_ctx_t ctx, unsigned long long* target, unsigned long long cond, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_compare_swap(shmem_ctx_t ctx, int32_t* target, int32_t cond, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_compare_swap(shmem_ctx_t ctx, int64_t* target, int64_t cond, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_compare_swap(shmem_ctx_t ctx, uint32_t* target, uint32_t cond, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_compare_swap(shmem_ctx_t ctx, uint64_t* target, uint64_t cond, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ctx_size_atomic_compare_swap(shmem_ctx_t ctx, size_t* target, size_t cond, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ctx_ptrdiff_atomic_compare_swap(shmem_ctx_t ctx, ptrdiff_t* target, ptrdiff_t cond, ptrdiff_t value, int pe);

/* AMO: Atomic Fetch-and-Add Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_fadd(int* target, int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_fadd(long* target, long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_fadd(long long* target, long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_fadd(unsigned int* target, unsigned int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_fadd(unsigned long* target, unsigned long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_fadd(unsigned long long* target, unsigned long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_fadd(int32_t* target, int32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_fadd(int64_t* target, int64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_fadd(uint32_t* target, uint32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_fadd(uint64_t* target, uint64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_fadd(size_t* target, size_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_fadd(ptrdiff_t* target, ptrdiff_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES int shmem_int_atomic_fetch_add(int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_atomic_fetch_add(long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_atomic_fetch_add(long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_fetch_add(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_fetch_add(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_fetch_add(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_fetch_add(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_fetch_add(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_fetch_add(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_fetch_add(uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_atomic_fetch_add(size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_atomic_fetch_add(ptrdiff_t* target, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_int_atomic_fetch_add(shmem_ctx_t ctx, int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_ctx_long_atomic_fetch_add(shmem_ctx_t ctx, long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_ctx_longlong_atomic_fetch_add(shmem_ctx_t ctx, long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_fetch_add(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_fetch_add(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_fetch_add(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_fetch_add(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_fetch_add(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_fetch_add(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_fetch_add(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ctx_size_atomic_fetch_add(shmem_ctx_t ctx, size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ctx_ptrdiff_atomic_fetch_add(shmem_ctx_t ctx, ptrdiff_t* target, ptrdiff_t value, int pe);

/* AMO: Atomic Fetch-and-Increment Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_finc(int* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_finc(long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_finc(long long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_finc(unsigned int* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_finc(unsigned long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_finc(unsigned long long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_finc(int32_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_finc(int64_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_finc(uint32_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_finc(uint64_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_finc(size_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_finc(ptrdiff_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES int shmem_int_atomic_fetch_inc(int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_atomic_fetch_inc(long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_atomic_fetch_inc(long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_fetch_inc(unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_fetch_inc(unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_fetch_inc(unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_fetch_inc(int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_fetch_inc(int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_fetch_inc(uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_fetch_inc(uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_atomic_fetch_inc(size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_atomic_fetch_inc(ptrdiff_t* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_int_atomic_fetch_inc(shmem_ctx_t ctx, int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_ctx_long_atomic_fetch_inc(shmem_ctx_t ctx, long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_ctx_longlong_atomic_fetch_inc(shmem_ctx_t ctx, long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_fetch_inc(shmem_ctx_t ctx, unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_fetch_inc(shmem_ctx_t ctx, unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_fetch_inc(shmem_ctx_t ctx, unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_fetch_inc(shmem_ctx_t ctx, int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_fetch_inc(shmem_ctx_t ctx, int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_fetch_inc(shmem_ctx_t ctx, uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_fetch_inc(shmem_ctx_t ctx, uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ctx_size_atomic_fetch_inc(shmem_ctx_t ctx, size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ctx_ptrdiff_atomic_fetch_inc(shmem_ctx_t ctx, ptrdiff_t* target, int pe);

/* AMO: Atomic Add Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_add(int* target, int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_add(long* target, long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_add(long long* target, long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_add(unsigned int* target, unsigned int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_add(unsigned long* target, unsigned long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_add(unsigned long long* target, unsigned long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_add(int32_t* target, int32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_add(int64_t* target, int64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_add(uint32_t* target, uint32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_add(uint64_t* target, uint64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_add(size_t* target, size_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_add(ptrdiff_t* target, ptrdiff_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_add(int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_add(long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_add(long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_add(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_add(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_add(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_add(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_add(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_add(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_add(uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_add(size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_add(ptrdiff_t* target, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_add(shmem_ctx_t ctx, int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_add(shmem_ctx_t ctx, long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_add(shmem_ctx_t ctx, long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_add(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_add(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_add(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_add(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_add(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_add(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_add(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_add(shmem_ctx_t ctx, size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_add(shmem_ctx_t ctx, ptrdiff_t* target, ptrdiff_t value, int pe);

/* AMO: Atomic Increment Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_inc(int* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_inc(long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_inc(long long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_inc(unsigned int* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_inc(unsigned long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_inc(unsigned long long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_inc(int32_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_inc(int64_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_inc(uint32_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_inc(uint64_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_inc(size_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_inc(ptrdiff_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_inc(int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_inc(long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_inc(long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_inc(unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_inc(unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_inc(unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_inc(int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_inc(int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_inc(uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_inc(uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_inc(size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_inc(ptrdiff_t* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_inc(shmem_ctx_t ctx, int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_inc(shmem_ctx_t ctx, long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_inc(shmem_ctx_t ctx, long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_inc(shmem_ctx_t ctx, unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_inc(shmem_ctx_t ctx, unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_inc(shmem_ctx_t ctx, unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_inc(shmem_ctx_t ctx, int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_inc(shmem_ctx_t ctx, int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_inc(shmem_ctx_t ctx, uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_inc(shmem_ctx_t ctx, uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_inc(shmem_ctx_t ctx, size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_inc(shmem_ctx_t ctx, ptrdiff_t* target, int pe);

/* AMO: Atomic Fetch Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_fetch(const int* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_fetch(const long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_fetch(const long long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_fetch(const unsigned int* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_fetch(const unsigned long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_fetch(const unsigned long long* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_fetch(const int32_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_fetch(const int64_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_fetch(const uint32_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_fetch(const uint64_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_fetch(const size_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_fetch(const ptrdiff_t* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES float shmem_float_fetch(const float* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES double shmem_double_fetch(const double* target, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES int shmem_int_atomic_fetch(const int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_long_atomic_fetch(const long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_longlong_atomic_fetch(const long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_fetch(const unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_fetch(const unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_fetch(const unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_fetch(const int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_fetch(const int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_fetch(const uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_fetch(const uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_atomic_fetch(const size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ptrdiff_atomic_fetch(const ptrdiff_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES float shmem_float_atomic_fetch(const float* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES double shmem_double_atomic_fetch(const double* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_int_atomic_fetch(shmem_ctx_t ctx, const int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long shmem_ctx_long_atomic_fetch(shmem_ctx_t ctx, const long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES long long shmem_ctx_longlong_atomic_fetch(shmem_ctx_t ctx, const long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_fetch(shmem_ctx_t ctx, const unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_fetch(shmem_ctx_t ctx, const unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_fetch(shmem_ctx_t ctx, const unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_fetch(shmem_ctx_t ctx, const int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_fetch(shmem_ctx_t ctx, const int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_fetch(shmem_ctx_t ctx, const uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_fetch(shmem_ctx_t ctx, const uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ctx_size_atomic_fetch(shmem_ctx_t ctx, const size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES ptrdiff_t shmem_ctx_ptrdiff_atomic_fetch(shmem_ctx_t ctx, const ptrdiff_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES float shmem_ctx_float_atomic_fetch(shmem_ctx_t ctx, const float* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES double shmem_ctx_double_atomic_fetch(shmem_ctx_t ctx, const double* target, int pe);

/* AMO: Atomic Set Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_set(int* target, int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_set(long* target, long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_set(long long* target, long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_set(unsigned int* target, unsigned int value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_set(unsigned long* target, unsigned long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_set(unsigned long long* target, unsigned long long value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_set(int32_t* target, int32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_set(int64_t* target, int64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_set(uint32_t* target, uint32_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_set(uint64_t* target, uint64_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_set(size_t* target, size_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_set(ptrdiff_t* target, ptrdiff_t value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_set(float* target, float value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_set(double* target, double value, int pe) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_set(int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_set(long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_set(long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_set(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_set(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_set(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_set(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_set(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_set(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_set(uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_set(size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_set(ptrdiff_t* target, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_atomic_set(float* target, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_atomic_set(double* target, double value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_set(shmem_ctx_t ctx, int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_set(shmem_ctx_t ctx, long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_set(shmem_ctx_t ctx, long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_set(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_set(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_set(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_set(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_set(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_set(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_set(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_set(shmem_ctx_t ctx, size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_set(shmem_ctx_t ctx, ptrdiff_t* target, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_atomic_set(shmem_ctx_t ctx, float* target, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_atomic_set(shmem_ctx_t ctx, double* target, double value, int pe);

/* AMO: Atomic Bitwise Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_xor(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_xor(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_xor(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_xor(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_xor(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_xor(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_xor(uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_xor(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_xor(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_xor(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_xor(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_xor(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_xor(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_xor(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_and(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_and(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_and(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_and(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_and(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_and(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_and(uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_and(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_and(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_and(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_and(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_and(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_and(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_and(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_or(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_or(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_or(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_or(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_or(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_or(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_or(uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_or(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_or(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_or(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_or(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_or(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_or(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_or(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);

/* AMO: Fetching atomic Bitwise Routines */
SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_fetch_xor(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_fetch_xor(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_fetch_xor(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_fetch_xor(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_fetch_xor(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_fetch_xor(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_fetch_xor(uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_fetch_xor(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_fetch_xor(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_fetch_xor(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_fetch_xor(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_fetch_xor(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_fetch_xor(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_fetch_xor(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_fetch_and(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_fetch_and(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_fetch_and(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_fetch_and(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_fetch_and(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_fetch_and(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_fetch_and(uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_fetch_and(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_fetch_and(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_fetch_and(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_fetch_and(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_fetch_and(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_fetch_and(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_fetch_and(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_uint_atomic_fetch_or(unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ulong_atomic_fetch_or(unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ulonglong_atomic_fetch_or(unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_int32_atomic_fetch_or(int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_int64_atomic_fetch_or(int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_uint32_atomic_fetch_or(uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_uint64_atomic_fetch_or(uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES unsigned int shmem_ctx_uint_atomic_fetch_or(shmem_ctx_t ctx, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long shmem_ctx_ulong_atomic_fetch_or(shmem_ctx_t ctx, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES unsigned long long shmem_ctx_ulonglong_atomic_fetch_or(shmem_ctx_t ctx, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int32_t shmem_ctx_int32_atomic_fetch_or(shmem_ctx_t ctx, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES int64_t shmem_ctx_int64_atomic_fetch_or(shmem_ctx_t ctx, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint32_t shmem_ctx_uint32_atomic_fetch_or(shmem_ctx_t ctx, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_ctx_uint64_atomic_fetch_or(shmem_ctx_t ctx, uint64_t* target, uint64_t value, int pe);

/* COLL: Barrier Synchronization Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_barrier(int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_barrier_all(void);
SHMEM_FUNCTION_ATTRIBUTES void shmem_sync(int PE_start, int logPE_stride, int PE_size, long* pSync);
SHMEM_FUNCTION_ATTRIBUTES void shmem_sync_all(void);

/* COLL: Reduction Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_and_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_and_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_and_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_and_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_or_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_or_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_or_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_or_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_xor_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_xor_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_xor_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_xor_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_min_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_min_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_min_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_min_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_min_to_all(float* target, const float* source, int nreduce, int PE_start, int logPE_stride, int PE_size, float* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_min_to_all(double* target, const double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_min_to_all(long double* target, const long double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_max_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_max_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_max_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_max_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_max_to_all(float* target, const float* source, int nreduce, int PE_start, int logPE_stride, int PE_size, float* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_max_to_all(double* target, const double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_max_to_all(long double* target, const long double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_sum_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_sum_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_sum_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_sum_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_sum_to_all(float* target, const float* source, int nreduce, int PE_start, int logPE_stride, int PE_size, float* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_sum_to_all(double* target, const double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_sum_to_all(long double* target, const long double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_complexf_sum_to_all(float _Complex* target, const float _Complex* source, int nreduce, int PE_start, int logPE_stride, int PE_size, float _Complex* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_complexd_sum_to_all(double _Complex* target, const double _Complex* source, int nreduce, int PE_start, int logPE_stride, int PE_size, double _Complex* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_prod_to_all(short* target, const short* source, int nreduce, int PE_start, int logPE_stride, int PE_size, short* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_prod_to_all(int* target, const int* source, int nreduce, int PE_start, int logPE_stride, int PE_size, int* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_prod_to_all(long* target, const long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_prod_to_all(long long* target, const long long* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_prod_to_all(float* target, const float* source, int nreduce, int PE_start, int logPE_stride, int PE_size, float* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_prod_to_all(double* target, const double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longdouble_prod_to_all(long double* target, const long double* source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_complexf_prod_to_all(float _Complex* target, const float _Complex* source, int nreduce, int PE_start, int logPE_stride, int PE_size, float _Complex* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_complexd_prod_to_all(double _Complex* target, const double _Complex* source, int nreduce, int PE_start, int logPE_stride, int PE_size, double _Complex* pWrk, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

/* COLL: Collect Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_collect32(void* target, const void* source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_collect64(void* target, const void* source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_fcollect32(void* target, const void* source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_fcollect64(void* target, const void* source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

/* COLL: Broadcast Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_broadcast32(void* target, const void* source, size_t nlong, int PE_root, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_broadcast64(void* target, const void* source, size_t nlong, int PE_root, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

/* COLL: All-to-All routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_alltoall32(void* dest, const void* source, size_t nelems, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_alltoall64(void* dest, const void* source, size_t nelems, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_alltoalls32(void* dest, const void* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_alltoalls64(void* dest, const void* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems, int PE_start, int logPE_stride, int PE_size, long* pSync) SHMEM_ATTRIBUTE_DEPRECATED;

/* Point-to-Point Synchronization Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_wait(long* ivar, long cmp_value) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_short_wait(short* var, short value) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_wait(int* var, int value) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_wait(long* var, long value) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_wait(long long* var, long long value) SHMEM_ATTRIBUTE_DEPRECATED;

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_wait_until(short* var, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_wait_until(int* var, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_wait_until(long* var, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_wait_until(long long* var, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_wait_until(unsigned short* var, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_wait_until(unsigned int* var, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_wait_until(unsigned long* var, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_wait_until(unsigned long long* var, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_wait_until(int32_t* var, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_wait_until(int64_t* var, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_wait_until(uint32_t* var, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_wait_until(uint64_t* var, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_wait_until(size_t* var, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_wait_until(ptrdiff_t* var, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_wait_until_all(short* vars, size_t nelems, const int* status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_wait_until_all(int* vars, size_t nelems, const int* status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_wait_until_all(long* vars, size_t nelems, const int* status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_wait_until_all(long long* vars, size_t nelems, const int* status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_wait_until_all(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_wait_until_all(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_wait_until_all(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_wait_until_all(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_wait_until_all(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_wait_until_all(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_wait_until_all(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_wait_until_all(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_wait_until_all(size_t* vars, size_t nelems, const int* status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_wait_until_all(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_wait_until_any(short* vars, size_t nelems, const int* status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_wait_until_any(int* vars, size_t nelems, const int* status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_wait_until_any(long* vars, size_t nelems, const int* status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_wait_until_any(long long* vars, size_t nelems, const int* status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_wait_until_any(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_wait_until_any(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_wait_until_any(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_wait_until_any(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_wait_until_any(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_wait_until_any(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_wait_until_any(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_wait_until_any(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_wait_until_any(size_t* vars, size_t nelems, const int* status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_wait_until_any(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_wait_until_some(short* vars, size_t nelems, size_t* indices, const int* status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_wait_until_some(int* vars, size_t nelems, size_t* indices, const int* status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_wait_until_some(long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_wait_until_some(long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_wait_until_some(unsigned short* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_wait_until_some(unsigned int* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_wait_until_some(unsigned long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_wait_until_some(unsigned long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_wait_until_some(int32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_wait_until_some(int64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_wait_until_some(uint32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_wait_until_some(uint64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_wait_until_some(size_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_wait_until_some(ptrdiff_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES void shmem_short_wait_until_all_vector(short* vars, size_t nelems, const int* status, int cmp, short* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_wait_until_all_vector(int* vars, size_t nelems, const int* status, int cmp, int* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_wait_until_all_vector(long* vars, size_t nelems, const int* status, int cmp, long* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_wait_until_all_vector(long long* vars, size_t nelems, const int* status, int cmp, long long* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ushort_wait_until_all_vector(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_wait_until_all_vector(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_wait_until_all_vector(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_wait_until_all_vector(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_wait_until_all_vector(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_wait_until_all_vector(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_wait_until_all_vector(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_wait_until_all_vector(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_wait_until_all_vector(size_t* vars, size_t nelems, const int* status, int cmp, size_t* values);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_wait_until_all_vector(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t* values);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_wait_until_any_vector(short* vars, size_t nelems, const int* status, int cmp, short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_wait_until_any_vector(int* vars, size_t nelems, const int* status, int cmp, int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_wait_until_any_vector(long* vars, size_t nelems, const int* status, int cmp, long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_wait_until_any_vector(long long* vars, size_t nelems, const int* status, int cmp, long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_wait_until_any_vector(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_wait_until_any_vector(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_wait_until_any_vector(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_wait_until_any_vector(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_wait_until_any_vector(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_wait_until_any_vector(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_wait_until_any_vector(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_wait_until_any_vector(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_wait_until_any_vector(size_t* vars, size_t nelems, const int* status, int cmp, size_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_wait_until_any_vector(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t* values);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_wait_until_some_vector(short* vars, size_t nelems, size_t* indices, const int* status, int cmp, short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_wait_until_some_vector(int* vars, size_t nelems, size_t* indices, const int* status, int cmp, int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_wait_until_some_vector(long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_wait_until_some_vector(long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_wait_until_some_vector(unsigned short* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_wait_until_some_vector(unsigned int* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_wait_until_some_vector(unsigned long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_wait_until_some_vector(unsigned long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_wait_until_some_vector(int32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_wait_until_some_vector(int64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_wait_until_some_vector(uint32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_wait_until_some_vector(uint64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_wait_until_some_vector(size_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, size_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_wait_until_some_vector(ptrdiff_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, ptrdiff_t* values);

SHMEM_FUNCTION_ATTRIBUTES int shmem_short_test(short* var, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_test(int* var, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_test(long* var, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_test(long long* var, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_test(unsigned short* var, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_test(unsigned int* var, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_test(unsigned long* var, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_test(unsigned long long* var, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_test(int32_t* var, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_test(int64_t* var, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_test(uint32_t* var, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_test(uint64_t* var, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_test(size_t* var, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_test(ptrdiff_t* var, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES int shmem_short_test_all(short* vars, size_t nelems, const int* status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_test_all(int* vars, size_t nelems, const int* status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_test_all(long* vars, size_t nelems, const int* status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_test_all(long long* vars, size_t nelems, const int* status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_test_all(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_test_all(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_test_all(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_test_all(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_test_all(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_test_all(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_test_all(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_test_all(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_test_all(size_t* vars, size_t nelems, const int* status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_test_all(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_test_any(short* vars, size_t nelems, const int* status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_test_any(int* vars, size_t nelems, const int* status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_test_any(long* vars, size_t nelems, const int* status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_test_any(long long* vars, size_t nelems, const int* status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_test_any(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_test_any(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_test_any(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_test_any(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_test_any(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_test_any(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_test_any(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_test_any(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_test_any(size_t* vars, size_t nelems, const int* status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_test_any(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_test_some(short* vars, size_t nelems, size_t* indices, const int* status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_test_some(int* vars, size_t nelems, size_t* indices, const int* status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_test_some(long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_test_some(long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_test_some(unsigned short* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_test_some(unsigned int* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_test_some(unsigned long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_test_some(unsigned long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_test_some(int32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_test_some(int64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_test_some(uint32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_test_some(uint64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_test_some(size_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_test_some(ptrdiff_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES int shmem_short_test_all_vector(short* vars, size_t nelems, const int* status, int cmp, short* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_test_all_vector(int* vars, size_t nelems, const int* status, int cmp, int* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_test_all_vector(long* vars, size_t nelems, const int* status, int cmp, long* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_test_all_vector(long long* vars, size_t nelems, const int* status, int cmp, long long* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_test_all_vector(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_test_all_vector(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_test_all_vector(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_test_all_vector(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_test_all_vector(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_test_all_vector(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_test_all_vector(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_test_all_vector(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_test_all_vector(size_t* vars, size_t nelems, const int* status, int cmp, size_t* values);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_test_all_vector(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t* values);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_test_any_vector(short* vars, size_t nelems, const int* status, int cmp, short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_test_any_vector(int* vars, size_t nelems, const int* status, int cmp, int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_test_any_vector(long* vars, size_t nelems, const int* status, int cmp, long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_test_any_vector(long long* vars, size_t nelems, const int* status, int cmp, long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_test_any_vector(unsigned short* vars, size_t nelems, const int* status, int cmp, unsigned short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_test_any_vector(unsigned int* vars, size_t nelems, const int* status, int cmp, unsigned int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_test_any_vector(unsigned long* vars, size_t nelems, const int* status, int cmp, unsigned long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_test_any_vector(unsigned long long* vars, size_t nelems, const int* status, int cmp, unsigned long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_test_any_vector(int32_t* vars, size_t nelems, const int* status, int cmp, int32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_test_any_vector(int64_t* vars, size_t nelems, const int* status, int cmp, int64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_test_any_vector(uint32_t* vars, size_t nelems, const int* status, int cmp, uint32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_test_any_vector(uint64_t* vars, size_t nelems, const int* status, int cmp, uint64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_test_any_vector(size_t* vars, size_t nelems, const int* status, int cmp, size_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_test_any_vector(ptrdiff_t* vars, size_t nelems, const int* status, int cmp, ptrdiff_t* values);

SHMEM_FUNCTION_ATTRIBUTES size_t shmem_short_test_some_vector(short* vars, size_t nelems, size_t* indices, const int* status, int cmp, short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int_test_some_vector(int* vars, size_t nelems, size_t* indices, const int* status, int cmp, int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_long_test_some_vector(long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_longlong_test_some_vector(long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ushort_test_some_vector(unsigned short* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned short* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint_test_some_vector(unsigned int* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned int* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulong_test_some_vector(unsigned long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ulonglong_test_some_vector(unsigned long long* vars, size_t nelems, size_t* indices, const int* status, int cmp, unsigned long long* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int32_test_some_vector(int32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_int64_test_some_vector(int64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, int64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint32_test_some_vector(uint32_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint32_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_uint64_test_some_vector(uint64_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, uint64_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_size_test_some_vector(size_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, size_t* values);
SHMEM_FUNCTION_ATTRIBUTES size_t shmem_ptrdiff_test_some_vector(ptrdiff_t* vars, size_t nelems, size_t* indices, const int* status, int cmp, ptrdiff_t* values);

SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_signal_wait_until(uint64_t* sig_addr, int cmp, uint64_t cmp_value);

/* Memory Ordering Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_quiet(void);
SHMEM_FUNCTION_ATTRIBUTES void shmem_fence(void);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_quiet(shmem_ctx_t ctx);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_fence(shmem_ctx_t ctx);

/* Distributed Locking Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmem_set_lock(long* lock);
SHMEM_FUNCTION_ATTRIBUTES void shmem_clear_lock(long* lock);
SHMEM_FUNCTION_ATTRIBUTES int shmem_test_lock(long* lock);

/* Cache Management Routines (deprecated) */
SHMEM_FUNCTION_ATTRIBUTES void shmem_set_cache_inv(void) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_set_cache_line_inv(void* target) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_clear_cache_inv(void) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_clear_cache_line_inv(void* target) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_udcflush(void) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shmem_udcflush_line(void* target) SHMEM_ATTRIBUTE_DEPRECATED;

/* Deprecated API */
SHMEM_FUNCTION_ATTRIBUTES int _num_pes(void) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES int _my_pe(void) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void* shmalloc(size_t size) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void* shmemalign(size_t alignment, size_t size) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void* shrealloc(void* ptr, size_t size) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void shfree(void* ptr) SHMEM_ATTRIBUTE_DEPRECATED;
SHMEM_FUNCTION_ATTRIBUTES void start_pes(int npes) SHMEM_ATTRIBUTE_DEPRECATED;

/* Memory Management Routines */
SHMEM_FUNCTION_ATTRIBUTES void* shmem_malloc_with_hints(size_t size, long hints);

/* Nonblocking swap operations */
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_swap_nbi(int* fetch, int* dest, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_swap_nbi(long* fetch, long* dest, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_swap_nbi(long long* fetch, long long* dest, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_swap_nbi(unsigned int* fetch, unsigned int* dest, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_swap_nbi(unsigned long* fetch, unsigned long* dest, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_swap_nbi(unsigned long long* fetch, unsigned long long* dest, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_swap_nbi(int32_t* fetch, int32_t* dest, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_swap_nbi(int64_t* fetch, int64_t* dest, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_swap_nbi(uint32_t* fetch, uint32_t* dest, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_swap_nbi(uint64_t* fetch, uint64_t* dest, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_swap_nbi(size_t* fetch, size_t* dest, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_swap_nbi(ptrdiff_t* fetch, ptrdiff_t* dest, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_atomic_swap_nbi(float* fetch, float* dest, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_atomic_swap_nbi(double* fetch, double* dest, double value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_swap_nbi(shmem_ctx_t ctx, int* fetch, int* dest, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_swap_nbi(shmem_ctx_t ctx, long* fetch, long* dest, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_swap_nbi(shmem_ctx_t ctx, long long* fetch, long long* dest, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_swap_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* dest, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_swap_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* dest, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_swap_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* dest, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_swap_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* dest, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_swap_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* dest, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_swap_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* dest, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_swap_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* dest, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_swap_nbi(shmem_ctx_t ctx, size_t* fetch, size_t* dest, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_swap_nbi(shmem_ctx_t ctx, ptrdiff_t* fetch, ptrdiff_t* dest, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_atomic_swap_nbi(shmem_ctx_t ctx, float* fetch, float* dest, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_atomic_swap_nbi(shmem_ctx_t ctx, double* fetch, double* dest, double value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_compare_swap_nbi(int* fetch, int* dest, int cond, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_compare_swap_nbi(long* fetch, long* dest, long cond, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_compare_swap_nbi(long long* fetch, long long* dest, long long cond, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_compare_swap_nbi(unsigned int* fetch, unsigned int* dest, unsigned int cond, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_compare_swap_nbi(unsigned long* fetch, unsigned long* dest, unsigned long cond, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_compare_swap_nbi(unsigned long long* fetch, unsigned long long* dest, unsigned long long cond, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_compare_swap_nbi(int32_t* fetch, int32_t* dest, int32_t cond, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_compare_swap_nbi(int64_t* fetch, int64_t* dest, int64_t cond, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_compare_swap_nbi(uint32_t* fetch, uint32_t* dest, uint32_t cond, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_compare_swap_nbi(uint64_t* fetch, uint64_t* dest, uint64_t cond, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_compare_swap_nbi(size_t* fetch, size_t* dest, size_t cond, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_compare_swap_nbi(ptrdiff_t* fetch, ptrdiff_t* dest, ptrdiff_t cond, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_compare_swap_nbi(shmem_ctx_t ctx, int* fetch, int* dest, int cond, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_compare_swap_nbi(shmem_ctx_t ctx, long* fetch, long* dest, long cond, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_compare_swap_nbi(shmem_ctx_t ctx, long long* fetch, long long* dest, long long cond, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* dest, unsigned int cond, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* dest, unsigned long cond, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* dest, unsigned long long cond, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_compare_swap_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* dest, int32_t cond, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_compare_swap_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* dest, int64_t cond, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_compare_swap_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* dest, uint32_t cond, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_compare_swap_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* dest, uint64_t cond, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_compare_swap_nbi(shmem_ctx_t ctx, size_t* fetch, size_t* dest, size_t cond, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_compare_swap_nbi(shmem_ctx_t ctx, ptrdiff_t* fetch, ptrdiff_t* dest, ptrdiff_t cond, ptrdiff_t value, int pe);

/* Nonblocking fetching AMOs */
SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_fetch_nbi(int* fetch, const int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_fetch_nbi(long* fetch, const long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_fetch_nbi(long long* fetch, const long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_fetch_nbi(unsigned int* fetch, const unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_fetch_nbi(unsigned long* fetch, const unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_fetch_nbi(unsigned long long* fetch, const unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_fetch_nbi(int32_t* fetch, const int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_fetch_nbi(int64_t* fetch, const int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_fetch_nbi(uint32_t* fetch, const uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_fetch_nbi(uint64_t* fetch, const uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_fetch_nbi(size_t* fetch, const size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_fetch_nbi(ptrdiff_t* fetch, const ptrdiff_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_float_atomic_fetch_nbi(float* fetch, const float* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_double_atomic_fetch_nbi(double* fetch, const double* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_fetch_nbi(shmem_ctx_t ctx, int* fetch, const int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_fetch_nbi(shmem_ctx_t ctx, long* fetch, const long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_fetch_nbi(shmem_ctx_t ctx, long long* fetch, const long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned int* fetch, const unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned long* fetch, const unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned long long* fetch, const unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_fetch_nbi(shmem_ctx_t ctx, int32_t* fetch, const int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_fetch_nbi(shmem_ctx_t ctx, int64_t* fetch, const int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_fetch_nbi(shmem_ctx_t ctx, uint32_t* fetch, const uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_fetch_nbi(shmem_ctx_t ctx, uint64_t* fetch, const uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_fetch_nbi(shmem_ctx_t ctx, size_t* fetch, const size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_fetch_nbi(shmem_ctx_t ctx, ptrdiff_t* fetch, const ptrdiff_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_float_atomic_fetch_nbi(shmem_ctx_t ctx, float* fetch, const float* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_double_atomic_fetch_nbi(shmem_ctx_t ctx, double* fetch, const double* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_fetch_inc_nbi(int* fetch, int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_fetch_inc_nbi(long* fetch, long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_fetch_inc_nbi(long long* fetch, long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_fetch_inc_nbi(unsigned int* fetch, unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_fetch_inc_nbi(unsigned long* fetch, unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_fetch_inc_nbi(unsigned long long* fetch, unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_fetch_inc_nbi(int32_t* fetch, int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_fetch_inc_nbi(int64_t* fetch, int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_fetch_inc_nbi(uint32_t* fetch, uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_fetch_inc_nbi(uint64_t* fetch, uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_fetch_inc_nbi(size_t* fetch, size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_fetch_inc_nbi(ptrdiff_t* fetch, ptrdiff_t* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int* fetch, int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_fetch_inc_nbi(shmem_ctx_t ctx, long* fetch, long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_fetch_inc_nbi(shmem_ctx_t ctx, long long* fetch, long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_fetch_inc_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_fetch_inc_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_fetch_inc_nbi(shmem_ctx_t ctx, size_t* fetch, size_t* target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_fetch_inc_nbi(shmem_ctx_t ctx, ptrdiff_t* fetch, ptrdiff_t* target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_int_atomic_fetch_add_nbi(int* fetch, int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_long_atomic_fetch_add_nbi(long* fetch, long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_longlong_atomic_fetch_add_nbi(long long* fetch, long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_fetch_add_nbi(unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_fetch_add_nbi(unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_fetch_add_nbi(unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_fetch_add_nbi(int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_fetch_add_nbi(int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_fetch_add_nbi(uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_fetch_add_nbi(uint64_t* fetch, uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_size_atomic_fetch_add_nbi(size_t* fetch, size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ptrdiff_atomic_fetch_add_nbi(ptrdiff_t* fetch, ptrdiff_t* target, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int_atomic_fetch_add_nbi(shmem_ctx_t ctx, int* fetch, int* target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_long_atomic_fetch_add_nbi(shmem_ctx_t ctx, long* fetch, long* target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_longlong_atomic_fetch_add_nbi(shmem_ctx_t ctx, long long* fetch, long long* target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_fetch_add_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_fetch_add_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_fetch_add_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_fetch_add_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_size_atomic_fetch_add_nbi(shmem_ctx_t ctx, size_t* fetch, size_t* target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ptrdiff_atomic_fetch_add_nbi(shmem_ctx_t ctx, ptrdiff_t* fetch, ptrdiff_t* target, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_fetch_xor_nbi(unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_fetch_xor_nbi(unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_fetch_xor_nbi(unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_fetch_xor_nbi(int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_fetch_xor_nbi(int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_fetch_xor_nbi(uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_fetch_xor_nbi(uint64_t* fetch, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_fetch_xor_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_fetch_xor_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_fetch_xor_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_fetch_xor_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_fetch_and_nbi(unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_fetch_and_nbi(unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_fetch_and_nbi(unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_fetch_and_nbi(int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_fetch_and_nbi(int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_fetch_and_nbi(uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_fetch_and_nbi(uint64_t* fetch, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_fetch_and_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_fetch_and_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_fetch_and_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_fetch_and_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_uint_atomic_fetch_or_nbi(unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulong_atomic_fetch_or_nbi(unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ulonglong_atomic_fetch_or_nbi(unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int32_atomic_fetch_or_nbi(int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_int64_atomic_fetch_or_nbi(int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint32_atomic_fetch_or_nbi(uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_uint64_atomic_fetch_or_nbi(uint64_t* fetch, uint64_t* target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned int* fetch, unsigned int* target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulong_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned long* fetch, unsigned long* target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_ulonglong_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned long long* fetch, unsigned long long* target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int32_atomic_fetch_or_nbi(shmem_ctx_t ctx, int32_t* fetch, int32_t* target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_int64_atomic_fetch_or_nbi(shmem_ctx_t ctx, int64_t* fetch, int64_t* target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint32_atomic_fetch_or_nbi(shmem_ctx_t ctx, uint32_t* fetch, uint32_t* target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmem_ctx_uint64_atomic_fetch_or_nbi(shmem_ctx_t ctx, uint64_t* fetch, uint64_t* target, uint64_t value, int pe);

/* Team Management Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_team_my_pe(shmem_team_t team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_translate_pe(shmem_team_t src_team, int src_pe, shmem_team_t dest_team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_n_pes(shmem_team_t team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_get_config(shmem_team_t team, long config_mask, shmem_team_config_t* config);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_split_strided(shmem_team_t parent_team, int PE_start, int PE_stride, int PE_size, const shmem_team_config_t* config, long config_mask, shmem_team_t* new_team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_split_2d(shmem_team_t parent_team, int xrange, const shmem_team_config_t* xaxis_config, long xaxis_mask, shmem_team_t* xaxis_team, const shmem_team_config_t* yaxis_config, long yaxis_mask, shmem_team_t* yaxis_team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_destroy(shmem_team_t team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_create_ctx(shmem_team_t team, long options, shmem_ctx_t* ctx);

SHMEM_FUNCTION_ATTRIBUTES int shmem_ctx_get_team(shmem_ctx_t ctx, shmem_team_t* team);

SHMEM_FUNCTION_ATTRIBUTES int shmem_team_sync(shmem_team_t team);

/* Team Collective Routines */
SHMEM_FUNCTION_ATTRIBUTES int shmem_float_alltoall(shmem_team_t team, float* dest, const float* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_alltoall(shmem_team_t team, double* dest, const double* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_alltoall(shmem_team_t team, long double* dest, const long double* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_char_alltoall(shmem_team_t team, char* dest, const char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_alltoall(shmem_team_t team, signed char* dest, const signed char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_alltoall(shmem_team_t team, short* dest, const short* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_alltoall(shmem_team_t team, int* dest, const int* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_alltoall(shmem_team_t team, long* dest, const long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_alltoall(shmem_team_t team, long long* dest, const long long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_alltoall(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_alltoall(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_alltoall(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_alltoall(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_alltoall(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_alltoall(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_alltoall(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_alltoall(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_alltoall(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_alltoall(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_alltoall(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_alltoall(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_alltoall(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_alltoall(shmem_team_t team, size_t* dest, const size_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_alltoall(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_alltoallmem(shmem_team_t team, void* dest, const void* source, size_t nelems);

SHMEM_FUNCTION_ATTRIBUTES int shmem_float_alltoalls(shmem_team_t team, float* dest, const float* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_alltoalls(shmem_team_t team, double* dest, const double* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_alltoalls(shmem_team_t team, long double* dest, const long double* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_char_alltoalls(shmem_team_t team, char* dest, const char* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_alltoalls(shmem_team_t team, signed char* dest, const signed char* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_alltoalls(shmem_team_t team, short* dest, const short* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_alltoalls(shmem_team_t team, int* dest, const int* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_alltoalls(shmem_team_t team, long* dest, const long* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_alltoalls(shmem_team_t team, long long* dest, const long long* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_alltoalls(shmem_team_t team, unsigned char* dest, const unsigned char* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_alltoalls(shmem_team_t team, unsigned short* dest, const unsigned short* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_alltoalls(shmem_team_t team, unsigned int* dest, const unsigned int* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_alltoalls(shmem_team_t team, unsigned long* dest, const unsigned long* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_alltoalls(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_alltoalls(shmem_team_t team, int8_t* dest, const int8_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_alltoalls(shmem_team_t team, int16_t* dest, const int16_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_alltoalls(shmem_team_t team, int32_t* dest, const int32_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_alltoalls(shmem_team_t team, int64_t* dest, const int64_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_alltoalls(shmem_team_t team, uint8_t* dest, const uint8_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_alltoalls(shmem_team_t team, uint16_t* dest, const uint16_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_alltoalls(shmem_team_t team, uint32_t* dest, const uint32_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_alltoalls(shmem_team_t team, uint64_t* dest, const uint64_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_alltoalls(shmem_team_t team, size_t* dest, const size_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_alltoalls(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_alltoallsmem(shmem_team_t team, void* dest, const void* source, ptrdiff_t dst, ptrdiff_t sst, size_t nelems);

SHMEM_FUNCTION_ATTRIBUTES int shmem_float_broadcast(shmem_team_t team, float* dest, const float* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_broadcast(shmem_team_t team, double* dest, const double* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_broadcast(shmem_team_t team, long double* dest, const long double* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_char_broadcast(shmem_team_t team, char* dest, const char* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_broadcast(shmem_team_t team, signed char* dest, const signed char* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_broadcast(shmem_team_t team, short* dest, const short* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_broadcast(shmem_team_t team, int* dest, const int* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_broadcast(shmem_team_t team, long* dest, const long* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_broadcast(shmem_team_t team, long long* dest, const long long* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_broadcast(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_broadcast(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_broadcast(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_broadcast(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_broadcast(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_broadcast(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_broadcast(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_broadcast(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_broadcast(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_broadcast(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_broadcast(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_broadcast(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_broadcast(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_broadcast(shmem_team_t team, size_t* dest, const size_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_broadcast(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nelems, int PE_root);
SHMEM_FUNCTION_ATTRIBUTES int shmem_broadcastmem(shmem_team_t team, void* dest, const void* source, size_t nelems, int PE_root);

SHMEM_FUNCTION_ATTRIBUTES int shmem_float_collect(shmem_team_t team, float* dest, const float* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_collect(shmem_team_t team, double* dest, const double* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_collect(shmem_team_t team, long double* dest, const long double* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_char_collect(shmem_team_t team, char* dest, const char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_collect(shmem_team_t team, signed char* dest, const signed char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_collect(shmem_team_t team, short* dest, const short* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_collect(shmem_team_t team, int* dest, const int* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_collect(shmem_team_t team, long* dest, const long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_collect(shmem_team_t team, long long* dest, const long long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_collect(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_collect(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_collect(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_collect(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_collect(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_collect(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_collect(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_collect(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_collect(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_collect(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_collect(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_collect(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_collect(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_collect(shmem_team_t team, size_t* dest, const size_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_collect(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_collectmem(shmem_team_t team, void* dest, const void* source, size_t nelems);

SHMEM_FUNCTION_ATTRIBUTES int shmem_float_fcollect(shmem_team_t team, float* dest, const float* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_fcollect(shmem_team_t team, double* dest, const double* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_fcollect(shmem_team_t team, long double* dest, const long double* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_char_fcollect(shmem_team_t team, char* dest, const char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_fcollect(shmem_team_t team, signed char* dest, const signed char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_fcollect(shmem_team_t team, short* dest, const short* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_fcollect(shmem_team_t team, int* dest, const int* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_fcollect(shmem_team_t team, long* dest, const long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_fcollect(shmem_team_t team, long long* dest, const long long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_fcollect(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_fcollect(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_fcollect(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_fcollect(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_fcollect(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_fcollect(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_fcollect(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_fcollect(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_fcollect(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_fcollect(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_fcollect(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_fcollect(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_fcollect(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_fcollect(shmem_team_t team, size_t* dest, const size_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_fcollect(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nelems);
SHMEM_FUNCTION_ATTRIBUTES int shmem_fcollectmem(shmem_team_t team, void* dest, const void* source, size_t nelems);

SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_and_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_and_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_and_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_and_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_and_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_and_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_and_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_and_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_and_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_and_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_and_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_and_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_and_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_and_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_and_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_and_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_and_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_and_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);

SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_or_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_or_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_or_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_or_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_or_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_or_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_or_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_or_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_or_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_or_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_or_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_or_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_or_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_or_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_or_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_or_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_or_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_or_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);

SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_xor_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_xor_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_xor_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_xor_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_xor_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_xor_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_xor_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_xor_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_xor_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_xor_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_xor_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_xor_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_xor_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_xor_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_xor_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_xor_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_xor_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_xor_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);

SHMEM_FUNCTION_ATTRIBUTES int shmem_char_min_reduce(shmem_team_t team, char* dest, const char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_min_reduce(shmem_team_t team, signed char* dest, const signed char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_min_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_min_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_min_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_min_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_min_reduce(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_min_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_min_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_min_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_min_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_min_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_min_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_min_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_min_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_min_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_min_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_min_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_min_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_min_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_min_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_float_min_reduce(shmem_team_t team, float* dest, const float* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_min_reduce(shmem_team_t team, double* dest, const double* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_min_reduce(shmem_team_t team, long double* dest, const long double* source, size_t nreduce);

SHMEM_FUNCTION_ATTRIBUTES int shmem_char_max_reduce(shmem_team_t team, char* dest, const char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_max_reduce(shmem_team_t team, signed char* dest, const signed char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_max_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_max_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_max_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_max_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_max_reduce(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_max_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_max_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_max_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_max_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_max_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_max_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_max_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_max_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_max_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_max_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_max_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_max_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_max_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_max_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_float_max_reduce(shmem_team_t team, float* dest, const float* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_max_reduce(shmem_team_t team, double* dest, const double* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_max_reduce(shmem_team_t team, long double* dest, const long double* source, size_t nreduce);

SHMEM_FUNCTION_ATTRIBUTES int shmem_char_sum_reduce(shmem_team_t team, char* dest, const char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_sum_reduce(shmem_team_t team, signed char* dest, const signed char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_sum_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_sum_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_sum_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_sum_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_sum_reduce(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_sum_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_sum_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_sum_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_sum_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_sum_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_sum_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_sum_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_sum_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_sum_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_sum_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_sum_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_sum_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_sum_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_sum_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_float_sum_reduce(shmem_team_t team, float* dest, const float* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_sum_reduce(shmem_team_t team, double* dest, const double* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_sum_reduce(shmem_team_t team, long double* dest, const long double* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_complexd_sum_reduce(shmem_team_t team, double _Complex* dest, const double _Complex* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_complexf_sum_reduce(shmem_team_t team, float _Complex* dest, const float _Complex* source, size_t nreduce);

SHMEM_FUNCTION_ATTRIBUTES int shmem_char_prod_reduce(shmem_team_t team, char* dest, const char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_schar_prod_reduce(shmem_team_t team, signed char* dest, const signed char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_short_prod_reduce(shmem_team_t team, short* dest, const short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int_prod_reduce(shmem_team_t team, int* dest, const int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_long_prod_reduce(shmem_team_t team, long* dest, const long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longlong_prod_reduce(shmem_team_t team, long long* dest, const long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ptrdiff_prod_reduce(shmem_team_t team, ptrdiff_t* dest, const ptrdiff_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uchar_prod_reduce(shmem_team_t team, unsigned char* dest, const unsigned char* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ushort_prod_reduce(shmem_team_t team, unsigned short* dest, const unsigned short* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint_prod_reduce(shmem_team_t team, unsigned int* dest, const unsigned int* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulong_prod_reduce(shmem_team_t team, unsigned long* dest, const unsigned long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_ulonglong_prod_reduce(shmem_team_t team, unsigned long long* dest, const unsigned long long* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int8_prod_reduce(shmem_team_t team, int8_t* dest, const int8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int16_prod_reduce(shmem_team_t team, int16_t* dest, const int16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int32_prod_reduce(shmem_team_t team, int32_t* dest, const int32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_int64_prod_reduce(shmem_team_t team, int64_t* dest, const int64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint8_prod_reduce(shmem_team_t team, uint8_t* dest, const uint8_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint16_prod_reduce(shmem_team_t team, uint16_t* dest, const uint16_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint32_prod_reduce(shmem_team_t team, uint32_t* dest, const uint32_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_uint64_prod_reduce(shmem_team_t team, uint64_t* dest, const uint64_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_size_prod_reduce(shmem_team_t team, size_t* dest, const size_t* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_float_prod_reduce(shmem_team_t team, float* dest, const float* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_double_prod_reduce(shmem_team_t team, double* dest, const double* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_longdouble_prod_reduce(shmem_team_t team, long double* dest, const long double* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_complexd_prod_reduce(shmem_team_t team, double _Complex* dest, const double _Complex* source, size_t nreduce);
SHMEM_FUNCTION_ATTRIBUTES int shmem_complexf_prod_reduce(shmem_team_t team, float _Complex* dest, const float _Complex* source, size_t nreduce);

/* Signal Fetch */
SHMEM_FUNCTION_ATTRIBUTES uint64_t shmem_signal_fetch(const uint64_t* sig_addr);

SHMEM_FUNCTION_ATTRIBUTES void shmem_pcontrol(int level, ...);

/* C++ overloaded declarations */
// DELETED

/* C11 Generic Macros */
// DELETED

#endif /* SHMEM_H */
