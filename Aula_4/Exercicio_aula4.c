#include <stdio.h>
#include <omp.h>
#define NTHREADS 4
int main() {
    int n = NTHREADS, tid = -1;
#pragma omp parallel default(none) \
    private(tid) shared(n)
    {
        // Obtém o identificador de thread
        tid = omp_get_thread_num();
        printf("Thread %d: Olá!\n", tid);
    }
    printf("Thread %d: Tchau!\n", tid);
}