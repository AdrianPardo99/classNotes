#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include "defs.h"

/*
 * @author Adrian Gonzalez Pardo
 */

extern float *a,*b,*c;

/*
 * @params int** es el descriptor del pipe
 */
void proceso_padre(int **pipefd){
  register int i;
  pid_t pid;
  int status,id,bloque=MUESTRAS/N_PROC,init_bloque;
  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    id=status>>8;
    printf("Termino proceso hijo con PID: %d del bloque %d con %ld bytes y max buffer del pipe: %d\n",pid,id,bloque*sizeof(float),PIPE_BUF);
    close(pipefd[id][1]);
    init_bloque=id*bloque;
    read(pipefd[id][0],c+init_bloque,sizeof(int)*bloque);
    close(pipefd[id][0]);
  }
}
/*
 * @params int es el id del proceso hijo
 * @params int* es el descriptor del pipe
 */
void proceso_hijo(int id,int *pipefd){
  register int i;
  int bloque=MUESTRAS/N_PROC;
  int init_bloque=id*bloque;
  int end_bloque=init_bloque+bloque;
  close(pipefd[0]);
  for(i=init_bloque;i<end_bloque;i++){
    c[i]=a[i]*b[i];
  }
  write(pipefd[1],c+init_bloque,sizeof(float)*bloque);
  close(pipefd[1]);
  free(pipefd);
  free(a);
  free(b);
  free(c);
  exit(id);
}
