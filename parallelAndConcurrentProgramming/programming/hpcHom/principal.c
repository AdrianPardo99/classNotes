#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "defs.h"
#include "helper.h"
#include "archivos.h"
#include "hilos.h"
#include "procesos.h"

/*
 * @author Adrian Gonzalez Pardo
 */

float *a,*b,*c;
void fun_threads();
void fun_processs();

int main(int argc,char **argv){
  if(argc<2){
    printf("Error missing params\nUsage: %s <process-solv>",*argv);
    exit(EXIT_FAILURE);
  }
  int solv=atoi(*(argv+1));
  a=reservar_memoria(),b=reservar_memoria(),c=reservar_memoria();
  fill_array(a,0);
  fill_array(b,1);

  printf("Hann Window created succesfully\n");
  printf("Pulse signal read succesfully\n");
  if(solv==0){
    printf("Solucion con hilos\n");
    fun_threads();
  }else{
    printf("Solucion con procesos\n");
    fun_processs();

  }
  free(a);
  free(b);
  free(c);
  return 0;
}

void fun_threads(){
  pthread_t t_id[N_THREADS];
  int id_t[N_THREADS];
  register int i;
  for(i=0;i<N_THREADS;i++){
    id_t[i]=i;
    pthread_create(&t_id[i],NULL,hilo_procesamiento,(void*)&id_t[i]);
  }
  for(i=0;i<N_THREADS;i++){
    pthread_join(t_id[i],NULL);
  }
  guardar_archivo(c,"Producto_threads.dat",MUESTRAS);
}

void fun_processs(){
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
  guardar_archivo(c,"Producto_process.dat",MUESTRAS);
  free(pipefd);
}
