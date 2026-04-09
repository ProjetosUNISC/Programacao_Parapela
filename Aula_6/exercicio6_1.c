#include <stdio.h>
#include <omp.h>

int main() {
    int escolha;
    printf("Digite 1 para execução Paralela ou 0 para Sequencial: ");
    scanf("%d", &escolha);


#pragma omp parallel if(escolha) num_threads(4)
    {

#pragma omp single
        {
            printf("\n--- Informações de Ambiente ---\n");

            printf("Número de processadores: %d\n", omp_get_num_procs());

            printf("Número de threads ativas: %d\n", omp_get_num_threads());

            printf("Máximo de threads possíveis: %d\n", omp_get_max_threads());

            printf("Execução em paralelo? %s\n", omp_in_parallel() ? "Sim" : "Não");

            printf("Ajuste dinâmico habilitado? %s\n", omp_get_dynamic() ? "Sim" : "Não");

            printf("Paralelismo aninhado habilitado? %s\n", omp_get_nested() ? "Sim" : "Não");
        }

        int tid = omp_get_thread_num();
        printf("Olá da thread ID: %d\n", tid);
    }

    return 0;
}