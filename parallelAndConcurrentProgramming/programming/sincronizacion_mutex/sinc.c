#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 4


void *funHilo(void*);
int contador;
pthread_mutex_t block=PTHREAD_MUTEX_INITIALIZER;

int main(void){
  contador=0;
  register int i;
  pthread_t id[N];
  int *res,ids[N];

  
  pthread_mutex_init(&block,NULL);

  for(i=0;i<N;i++){
    ids[i]=i;
    pthread_create(&id[i],NULL,funHilo,(void*)&ids[i]);
  }
  for(i=0;i<N;i++){
    pthread_join(id[i],(void**)&res);
    printf("Hilo %d terminado\n",*res);
  }
  pthread_mutex_destroy(&block);
  return 0;
}

void *funHilo(void *arg){
  int id=*(int*)arg;
  register int i=0;
  pthread_mutex_lock(&block);
  contador++;
  printf("Hilo %d en ejecución con contador %d\n",id,contador);
  while((--i));
  printf("Hilo %d en ejecución con contador %d\n",id,contador);
  pthread_mutex_unlock(&block);
  pthread_exit(arg);
}
