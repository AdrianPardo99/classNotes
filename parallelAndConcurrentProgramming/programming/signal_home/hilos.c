#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "defs.h"

/*
 * @author Adrian Gonzalez Pardo
 **/

extern float *a,*b,*c,*x;

/*
 * @params *arg es la seccion de memoria del hilo
 **/
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

/*
 * @params *arg es la seccion de memoria del hilo
 **/
void *hilo_producto(void *arg){
  int *id=(int*)arg,
  bloque=MUESTRAS/N_PROC,
  init=*id*bloque,
  end=init+bloque;
  printf("Thread %d init \nWith: block=%d, init_block=%d, end_block=%d\n",*id,
    bloque,init,end);

  register int i,j;
  for(i=init;i<end;i++){
    *(x+i)=0;
    for(j=i;j<MUESTRAS;j++){
      *(x+i)+=*(c+j)**(c+(j-i));
    }
  }
  printf("Thread %d finish\n",*id);
  pthread_exit(arg);
}
