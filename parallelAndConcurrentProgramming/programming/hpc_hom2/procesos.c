#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "defs.h"

/*
 * @author Adrian Gonzalez Pardo
 **/

extern int suma,*a,*b;

/*
 * @params pipefd es el descriptor del pipe
 */
void proceso_padre(int **pipefd){
  register int i;
  pid_t pid;
  int status,id,p;
  suma=0;
  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    id=status>>8;
    printf("Termino proceso hijo con PID: %d del bloque %d\n",pid,id);
    close(pipefd[id][1]);
    read(pipefd[id][0],&p,sizeof(int));
    close(pipefd[id][0]);
    suma+=p;
  }
}

/*
 * @params id es el id del proceso hijo
 * @params pipefd es el descriptor del pipe
 */

void proceso_hijo(int id,int *pipefd){
  register int i;
  suma=0;
  close(pipefd[0]);
  for(i=id;i<N;i+=N_PROC){
    suma+=*(a+i)**(b+i);
  }
  write(pipefd[1],&suma,sizeof(int));
  close(pipefd[1]);
  free(pipefd);
  free(a);
  free(b);
  exit(id);
}
