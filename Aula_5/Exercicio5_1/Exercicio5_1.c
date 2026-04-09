#include <stdio.h>
#include <omp.h>

int main() {
    long long iteracoes = 1000000000; // Quanto maior, mais preciso
    long double pi = 0.0;
    double inicio = omp_get_wtime();

#pragma omp parallel for reduction(+:pi)
    for (long long i = 0; i < iteracoes; i++) {
        long double termo = 4.0 / (2.0 * i + 1.0);
        if (i % 2 == 0)
            pi += termo;
        else
            pi -= termo;
    }

    double fim = omp_get_wtime();
    printf("PI: %20Lf\n", pi);
    printf("Tempo: %f segundos\n", fim - inicio);
    return 0;
}