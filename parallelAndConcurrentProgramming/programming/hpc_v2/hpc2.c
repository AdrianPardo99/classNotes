#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 16
#define N_THREAD 4

int *reservar_memoria();
void llenar_arreglo(int*);
void muestra_arreglo(int*,char*);
void *function(void*);
int *A,*B,*C;


int main(void){
  srand(time(NULL));
  A=reservar_memoria();
  B=reservar_memoria();
  C=reservar_memoria();
  llenar_arreglo(A),llenar_arreglo(B),
  muestra_arreglo(A,"A"),muestra_arreglo(B,"B");
  pthread_t id_thread[N_THREAD];
  int id_int_thread[N_THREAD];
  register int i;
  for(i=0;i<N_THREAD;i++){
    id_int_thread[i]=i;
    pthread_create(&id_thread[i],NULL,function,(void*)&id_int_thread[i]);
  }
  for(i=0;i<N_THREAD;i++){
    pthread_join(id_thread[i],NULL);
  }
  muestra_arreglo(C,"C=AxB");
  free(A);
  free(B);
  free(C);
  return 0;
}

int *reservar_memoria(){
  int *a=(int*)malloc(sizeof(int)*N);
  if(!a){
    perror("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }
  return a;
}

void llenar_arreglo(int *a){
  register int i;
  for(i=0;i<N;i++){
    *(a+i)=rand()%256;
  }
}

void muestra_arreglo(int *a,char *x){
  printf("Arreglo %s\n",x);
  register int i;
  for(i=0;i<N;i++){
    if(i%8==0&&i>0){
      printf("\n");
    }
    printf(" %d ",*(a+i));
  }
  printf("\n");
}

void *function(void *arg){
  int *id=(int*)arg;
  printf("Thread id: %d\n",*id);
  register int i;
  for(i=*id;i<N;i+=N_THREAD){
    C[i]=A[i]*B[i];
  }
  pthread_exit(NULL);
}
