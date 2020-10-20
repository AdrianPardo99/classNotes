#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4

void *suma(void*);
void *resta(void*);
void *multiplicacion(void*);
void *division(void*);


int n1=20,n2=4;
int main(void){
  register int i;
  int *r;
  pthread_t *id_tread;
  /*
   * id_tread[0] suma
   * id_tread[1] resta
   * id_tread[2] multiplicacion
   * id_tread[3] division
   */
  printf("Probando hilos...\n");
  id_tread=(pthread_t*)malloc(sizeof(pthread_t)*N);
  if(!id_tread){
    perror("Error al asignar memoria al thread");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<N;i++){
    pthread_create(&*(id_tread+i),NULL,i==0?suma:i==1?resta:i==2?multiplicacion:division,NULL);
  }
  for(i=0;i<N;i++){
    pthread_join(*(id_tread+i),(void**)&r);
    printf("La operacion es: %s con resultado %d\n",
      (i==0)?("suma"):((i==1)?("resta"):
      ((i==2)?("multiplicacion"):("division"))),*r);
  }
  free(id_tread);
  return 0;
}

void *suma(void *arg){
  static int r;
  r=n1+n2;
  pthread_exit((void*)&r);
}

void *resta(void *arg){
  static int r;
  r=n1-n2;
  pthread_exit((void*)&r);
}

void *multiplicacion(void *arg){
  static int r;
  r=n1*n2;
  pthread_exit((void*)&r);
}

void *division(void *arg){
  static int r;
  r=n1/n2;
  pthread_exit((void*)&r);
}
