// Just some platform utilities for SSE targets.
#ifndef SSE_PLATFORM_H_INCLUDED
#define SSE_PLATFORM_H_INCLUDED

// x86 intrinsics (__rdtsc etc.)

#if defined(_MSC_VER)

#define _CRT_SECURE_NO_DEPRECATE
#include <intrin.h>
#define ALIGNSPEC(type,name,alignment) __declspec(align(alignment)) type name

#elif defined(__GNUC__)

#include <x86intrin.h>
#define ALIGNSPEC(type,name,alignment) type name __attribute__((aligned(alignment)))

#else
#error Unknown compiler!
#endif

#endif // SSE_PLATFORM_H_INCLUDED

