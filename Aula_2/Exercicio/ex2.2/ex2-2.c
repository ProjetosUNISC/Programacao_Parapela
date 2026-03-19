#include <stdio.h>
#include <stdlib.h>


long long resultado_soma = 0;
long long resultado_mult = 1;

int main() {

    int n_para_soma = 1000000000;  
    int m_para_mult = 20;   


    printf("--- Execução Sequencial ---\n");

 
    printf("Calculando soma...\n");
    for (int i = 0; i <= n_para_soma; i++) {
        resultado_soma += i;
    }


    printf("Calculando multiplicacao...\n");
    for (int i = 1; i <= m_para_mult; i++) {
        resultado_mult *= i;
    }

    // Resultados
    printf("\n============================\n");
    printf("Resultado Soma (0 ate %d): %lld\n", n_para_soma, resultado_soma);
    printf("Resultado Mult (1 ate %d): %lld\n", m_para_mult, resultado_mult);
    printf("============================\n");

    return 0;
}