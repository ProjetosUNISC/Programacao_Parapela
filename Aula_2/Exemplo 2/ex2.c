#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int soma;
void* func_soma(void* param)
{
int i, n = atoi(param);
soma = 0;
for (i = 1; i <= n; i++) {
soma = soma + i;
 }
pthread_exit(NULL);
}

void main(int argc, char* argv[]){
pthread_t th;
int valor;
if(argc != 2){
puts("./exec n");
return -1;
}
valor = atoi(argv[1]);
if(valor < 0){
printf("%d deve ser >=0\n", valor);
return -1;
}
pthread_create(&th, NULL, func_soma, argv[1]);
pthread_join(th, NULL);
printf("Soma = %d\n", soma);
}