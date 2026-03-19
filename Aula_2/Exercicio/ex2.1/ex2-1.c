#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Variáveis Globais
long long resultado_soma = 0;
long long resultado_mult = 1;

// Função da primeira thread: Soma
void* func_soma(void* arg) {
    int n = atoi((char*)arg);
    for (int i = 0; i <= n; i++) {
        resultado_soma += i;
    }
    pthread_exit(NULL);
}

// Função da segunda thread: Multiplicação
void* func_mult(void* arg) {
    int m = atoi((char*)arg);
    for (int i = 1; i <= m; i++) {
        resultado_mult *= i;
    }
    pthread_exit(NULL);
}

int main() {
    
    char* n_para_soma = "1000000000";  
    char* m_para_mult = "20";   
    

    pthread_t t1, t2;

    
    pthread_create(&t1, NULL, func_soma, n_para_soma);
    pthread_create(&t2, NULL, func_mult, m_para_mult);

   
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    
    printf("Resultado Soma (0 ate %s): %lld\n", n_para_soma, resultado_soma);
    printf("Resultado Mult (1 ate %s): %lld\n", m_para_mult, resultado_mult);

    return 0;
}