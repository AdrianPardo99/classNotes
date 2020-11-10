#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "defs.h"

/*
 * @author Adrian Gonzalez Pardo
 */

extern float *a,*b,*c;

/*
 * @params *arg es la seccion de memoria del hilo
 */
void *hilo_procesamiento(void *arg){
  int *id=(int*)arg;
  printf("Thread %d init \n",*id);
  register int i;
  for(i=*id;i<MUESTRAS;i+=N_THREADS){
    c[i]=a[i]*b[i];
  }
  printf("Thread %d finish\n",*id);
  pthread_exit(arg);
}
