#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "hilo.h"
#include "helper.h"
#include "defs.h"

int *datos,prom,par,prim;
pthread_mutex_t block=PTHREAD_MUTEX_INITIALIZER;
int main(void){
  pthread_t id_thread[N_THREAD];
  int *res,id_i_thread[N_THREAD];
  register int i;
  datos=reserva_memoria();
  llenar_arreglo(datos);
  pthread_mutex_init(&block,NULL);
  for(i=0;i<N_THREAD;i++){
    id_i_thread[i]=i;
    pthread_create(&id_thread[i],NULL,hilo,(void*)&id_i_thread[i]);
  }
  for(i=0;i<N_THREAD;i++){
    pthread_join(id_thread[i],(void**)&res);
    printf("Thread in main %d with operation %s: ",*res,
    *res==0?"Bubble sort":*res==1?"Integer average":
    *res==2?"How many pairs":"How many prime numbers");
    switch (*res){
      case 0:
      printf("\n");
        imprimir_arreglo(datos);
      break;
      case 1:case 2:case 3:
        printf("%d\n",*res==1?prom:*res==2?par:prim);
    }
  }
  pthread_mutex_destroy(&block);
  return 0;
}
