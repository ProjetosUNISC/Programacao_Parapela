#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *thread_executa(void *arg){
    int num_thread = (int) arg;
    printf("Olá Mundo! Sou a thread %d\n", num_thread);
    pthread_exit(NULL);
}

void main(int argc, char **argv){
    pthread_t th[10];
    int i;
    for(i = 0; i < 10; i++)
        pthread_create(&th[i], NULL, thread_executa, (void *) i);
    pthread_exit(NULL);
}