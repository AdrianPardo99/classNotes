#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "defs.h"
#include "procesos.h"
#include "hilos.h"
#include "helper.h"

int suma,*a,*b;

void process_solv();
void thread_solv();

int main(int argc, char **argv){
  if(argc<2){
    printf("Error\nUsage: %s <type-solv>",*argv),exit(EXIT_FAILURE);
  }
  int solv=atoi(*(argv+1));
  a=reservar_memoria(),b=reservar_memoria();
  llenar_arreglo(a),llenar_arreglo(b);
  /*printf("Array a\n"),print_array(a),printf("Array b\n"),print_array(b);*/
  switch(solv){
    case 0:
      printf("Process Solution\n");
      process_solv();
    break;
    case 1:
      printf("Threads Solution\n");
      thread_solv();
    break;
    default:
      printf("Option error\nOnly options 0 use process, 1 use threads\n");
      exit(EXIT_FAILURE);
  }
  printf("La suma de la serie de productos punto es: %d\n",suma);
  free(a);
  free(b);
  return 0;
}

void process_solv(){
  register int i;
  int **pipefd=(int**)malloc(sizeof(int*)*N_PROC);
  if(!pipefd){
    perror("Error al asignar memoria a los pipes"),exit(EXIT_FAILURE);
  }
  for(i=0;i<N_PROC;i++){
    pipefd[i]=(int*)malloc(sizeof(int)*2);
    if(!pipefd[i]){
      perror("Error al asignar la segunda memoria de pipes"),exit(EXIT_FAILURE);
    }
  }
  pid_t pid;
  for(i=0;i<N_PROC;i++){
    if((pipe(&pipefd[i][0]))==-1){
      perror("Error creating pipe"),exit(EXIT_FAILURE);
    }
    if((pid=fork())==-1){
      perror("Error creating new process"),exit(EXIT_FAILURE);
    }
    if(!pid){
      proceso_hijo(i,&pipefd[i][0]);
    }
  }
  proceso_padre(pipefd);
  free(pipefd);
}

void thread_solv(){
  pthread_t t_id[N_THREAD];
  int id_t[N_THREAD],*sp;
  register int i;
  suma=0;
  for(i=0;i<N_THREAD;i++){
    id_t[i]=i;
    pthread_create(&t_id[i],NULL,hilo_procesamiento,(void*)&id_t[i]);
  }
  for(i=0;i<N_THREAD;i++){
    pthread_join(t_id[i],(void**)&sp);
    suma+=*sp;
    free(sp);
  }
}
