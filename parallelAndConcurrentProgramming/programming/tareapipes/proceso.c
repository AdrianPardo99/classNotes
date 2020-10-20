/*
 * @author Adrian Gonzalez Pardo
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "defs.h"
#include "helper.h"
#include "procesamiento.h"
#include "proceso.h"

void proceso_padre(int pipefd[N_PROC][2],int *r1){
  pid_t pid=0;
  int status,id;
  int register i;
  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    id=status>>8;
    printf("Termino el proceso hijo con PID: %d y estatus %d\n",pid,id);
    close(pipefd[id][1]);
    read(pipefd[id][0],r1,sizeof(int)*N);
    if(id==0||id==3){
      printf("%s\n",id==0?
        "Se realizo el ordenamiento del arreglo":
        "Se multiplico el arreglo por un escalar");
      imprimir_arreglo(r1);
    }else if(id==1||id==2){
      printf("%s%d\n\n",id==1?
        "Promedio entero del arreglo: ":
        "Numero de pares: ",*r1);
    }
    printf("\n");
    close(pipefd[id][0]);
  }
}

void proceso_hijo(int id,int *a,int pipefd[]){
  int r;
  close(pipefd[0]);
  switch (id){
    case 0:
      bubble_sort(a);
      write(pipefd[1],(void*)&*a,sizeof(int)*N);
    break;
    case 1:
      r=promedio(a);
      write(pipefd[1],(void*)&r,sizeof(int));
    break;
    case 2:
      r=pares(a);
      write(pipefd[1],(void*)&r,sizeof(int));
    break;
    default:
      multiplica_const(a);
      write(pipefd[1],(void*)&*a,sizeof(int)*N);
  }
  free(a);
  close(pipefd[1]);
  exit(id);
}
