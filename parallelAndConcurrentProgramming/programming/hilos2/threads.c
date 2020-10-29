#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4

void *function(void*);


int n1=20,n2=4;
int main(void){
  register int i;
  int *r,*j;
  pthread_t *id_tread;
  /*
   * id_tread[0] suma
   * id_tread[1] resta
   * id_tread[2] multiplicacion
   * id_tread[3] division
   */
  printf("Probando hilos...\n");
  id_tread=(pthread_t*)malloc(sizeof(pthread_t)*N);
  j=(int*)malloc(sizeof(int)*N);
  if(!id_tread||!j){
    perror("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<N;i++){
    *(j+i)=i;
    pthread_create(&*(id_tread+i),NULL,function,(void*)&*(j+i));
  }
  for(i=0;i<N;i++){
    pthread_join(*(id_tread+i),(void**)&r);
    printf("La operacion es: %s con resultado %d\n",
      (i==0)?("suma"):((i==1)?("resta"):
      ((i==2)?("multiplicacion"):("division"))),*r);
    free(r);
  }
  free(j);
  free(id_tread);
  return 0;
}

void *function(void *arg){
  int *r=(int*)malloc(sizeof(int));
  int id=*(int*)arg;
  *r=id==0?n1+n2:id==1?n1-n2:id==2?n1*n2:n1/n2;
  printf("Proceso hijo en ejecucion %d\n",id);
  pthread_exit((void*)r);
}

