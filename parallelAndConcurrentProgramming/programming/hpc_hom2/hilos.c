#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include "defs.h"


extern int suma,*a,*b;
extern pthread_mutex_t lock;

/*
 * @params arg es la seccion de memoria del hilo
 **/
void *hilo_procesamiento(void *arg){
  int *id=(int*)arg,
    bloque=N/N_THREAD,
    init=*id*bloque,
    end=init+bloque;
  int *s_p=(int*)malloc(sizeof(int));
  if(!s_p){
    perror("Error in thread allocating memory"),exit(EXIT_FAILURE);
  }
  *s_p=0;
  printf("Thread %d init\n",*id);
  register int i;
  for(i=init;i<end;i++){
    *s_p+=*(a+i)**(b+i);
  }

  printf("Thread %d end\n",*id);
  pthread_exit((void**)s_p);
}
