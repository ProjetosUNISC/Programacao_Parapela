#include <stdio.h>
#include <omp.h>

#define N 10


int global_offset;
#pragma omp threadprivate(global_offset)

int main() {
    int a[N], b[N], soma[N];
    int i;

    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2;
    }
    global_offset = 10;

#pragma omp parallel copyin(global_offset)
    {

#pragma omp sections nowait
        {

#pragma omp section
            {
                printf("Thread %d processando de 0 a %d\n", omp_get_thread_num(), (N/2)-1);
                for (int j = 0; j < N/2; j++) {
                    soma[j] = a[j] + b[j] + global_offset;
                }
            }

#pragma omp section
{
    printf("Thread %d processando de %d a %d\n", omp_get_thread_num(), N/2, N-1);
    for (int j = N/2; j < N; j++) {
        soma[j] = a[j] + b[j] + global_offset;
    }
}
        }

    }
    printf("\nResultado da soma (com offset %d):\n", global_offset);
    for (i = 0; i < N; i++) {
        printf("%d ", soma[i]);
    }
    printf("\n");

    return 0;
}