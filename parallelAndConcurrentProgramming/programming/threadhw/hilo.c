#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "hilo.h"
#include "procesamiento.h"

extern int *datos,prom,par,prim;
extern pthread_mutex_t block;


void *hilo(void *args){
  int *id=(int*)args;
  printf("Thread init %d\n",*id);
  pthread_mutex_lock(&block);
  switch (*id){
    case 0:
      bubble_sort(datos);
    break;
    case 1:
      prom=promedio(datos);
    break;
    case 2:
      par=pares(datos);
    break;
    case 3:
      prim=primos(datos);
    break;
  }
  pthread_mutex_unlock(&block);
  printf("Thread finish %d\n",*id);
  pthread_exit((void*)args);
}
