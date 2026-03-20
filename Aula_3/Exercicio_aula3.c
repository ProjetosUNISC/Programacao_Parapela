#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define ITENS_TOTAL 15

int buffer[BUFFER_SIZE];
int g_index = 0;

sem_t vagas;
sem_t ocupados;
pthread_mutex_t mutex;

// Função para desenhar
void exibir_buffer(char* quem, int item) {
    printf("%s %2d |", quem, item);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (i < g_index) {
            printf(" [#] "); // ocupado
        } else {
            printf(" [ ] "); // vazio
        }
    }
    printf("| (Qtd: %d)\n", g_index);
}

void* produtor(void* arg) {
    for (int i = 0; i < ITENS_TOTAL; i++) {
        int item = rand() % 99;

        sem_wait(&vagas); // espera
        pthread_mutex_lock(&mutex); // entra

        buffer[g_index] = item;
        g_index++;
        exibir_buffer("PROD ->", item);

        pthread_mutex_unlock(&mutex); // sai
        sem_post(&ocupados); // incrementa

        usleep(rand() % 500000); // velocidade varivel
    }
    pthread_exit(NULL);
}

void* consumidor(void* arg) {
    for (int i = 0; i < ITENS_TOTAL; i++) {
        sem_wait(&ocupados); // espera item
        pthread_mutex_lock(&mutex); // entra

        g_index--;
        int item = buffer[g_index];
        exibir_buffer("CONS <-", item);

        pthread_mutex_unlock(&mutex); // Sai
        sem_post(&vagas); // incrementa

        usleep(rand() % 1000000);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t_prod, t_cons;

    sem_init(&vagas, 0, BUFFER_SIZE);
    sem_init(&ocupados, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    printf("Legenda: [ ] Vazio | [#] Ocupado\n");
    printf("--------------------------------------------\n");

    pthread_create(&t_prod, NULL, produtor, NULL);
    pthread_create(&t_cons, NULL, consumidor, NULL);

    pthread_join(t_prod, NULL);
    pthread_join(t_cons, NULL);

    sem_destroy(&vagas);
    sem_destroy(&ocupados);
    pthread_mutex_destroy(&mutex);

    printf("--------------------------------------------\n");
    printf("Simlação finalizada!\n");
    return 0;
}