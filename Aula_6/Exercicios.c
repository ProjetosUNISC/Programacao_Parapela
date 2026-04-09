#include <omp.h>
#include <stdio.h>
#define N 10000
#define CHUNKSIZE 10
void main(int argc, char *argv[]) {
    int i, chunk;
    float a[N];
    chunk = CHUNKSIZE;
#pragma omp parallel num_threads(4) shared(a, chunk) private(i)
    {
#pragma omp for schedule(guided, chunk) nowait
        for (i=0; i < N; i++)
            a[i] = 10.0 * omp_get_thread_num();
    }
    for (i=0; i < N; i++)
        printf("a[%d] = %.1f\n", i, a[i]);
}