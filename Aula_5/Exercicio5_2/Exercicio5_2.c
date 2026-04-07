#include <stdio.h>
#include <omp.h>

int main() {
    long long iteracoes = 100000000;
    long double soma = 0.0;
    double inicio = omp_get_wtime();

#pragma omp parallel for reduction(+:soma)
    for (long long i = 1; i <= iteracoes; i++) {
        long double n = 2.0 * i;
        long double termo = 4.0 / (n * (n + 1.0) * (n + 2.0));

        if (i % 2 == 1)
            soma += termo;
        else
            soma -= termo;
    }

    long double pi = 3.0 + soma;
    double fim = omp_get_wtime();
    printf("PI Nilakantha: %20Lf\n", pi);
    printf("Tempo: %f segundos\n", fim - inicio);
    return 0;
}