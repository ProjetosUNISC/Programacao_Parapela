#include <stdio.h>
#include <omp.h>
#define N 50
void main (int argc, char *argv[]){
    int i, nthreads, tid;
    float a[N], b[N], c[N], d[N];
    for (i=0; i<N; i++) {
        a[i] = 10;
        b[i] = 20;
        c[i] = d[i] = 0.0;
    }
#pragma omp parallel shared(a,b,c,d,nthreads) private(i,tid)
    {
        tid = omp_get_thread_num();
        if (tid == 0) { //master thread
            nthreads = omp_get_num_threads();
            printf("Num de threads = %d\n", nthreads);
        }
        printf("Thread %d iniciando...\n",tid);
#pragma omp sections
        {
#pragma omp section
            {
                printf("Thread %d na secao A\n", tid);
                for (i=0; i<N; i++) {
                    c[i] = a[i] + b[i];
                    printf("Thread %d: c[%d]=%f\n",tid,i,c[i]);
                }
            }
#pragma omp section
{
    printf("Thread %d na seção B\n", tid);
    for (i=0; i<N; i++) {
        d[i] = a[i] * b[i];
        printf("Thread %d: d[%d]=%f\n",tid,i,d[i]);
    }
}
        } /* fim das sections */
        printf("Thread %d saiu.\n",tid);
    } /* fim da parallel section */
}