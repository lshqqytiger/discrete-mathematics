#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <sys/resource.h>

typedef struct timeval timeval_t;
#endif

double time(){
#ifdef WIN32
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
#else
    timeval_t t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec * 1e-6;
#endif
}