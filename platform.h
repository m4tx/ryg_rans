// Just some platform utilities.
#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

// Timer

#if defined(_WIN32)

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#define PRIu64 "llu"

static inline double timer()
{
    LARGE_INTEGER ctr, freq;
    QueryPerformanceCounter(&ctr);
    QueryPerformanceFrequency(&freq);
    return 1.0 * ctr.QuadPart / freq.QuadPart;
}

#elif defined(__linux__)

#define __STDC_FORMAT_MACROS
#include <time.h>
#include <inttypes.h>
#include <assert.h>

static inline double timer()
{
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 0;
    int status = clock_gettime(CLOCK_MONOTONIC, &ts);
    assert(status == 0);
    return ((double) (ts.tv_sec)) + 1.0e-9 * ((double) (ts.tv_nsec));
}

#else

#error Unknown platform!

#endif

#endif // PLATFORM_H_INCLUDED

