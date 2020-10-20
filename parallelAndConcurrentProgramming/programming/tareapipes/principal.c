/*
 * @author Adrian Gonzalez Pardo
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "defs.h"
#include "helper.h"
#include "proceso.h"

int main(void){
  pid_t pid;
  register int i;
  int *a,pipefd[N_PROC][2];
  a=reserva_memoria(N);
  if(a==NULL){
    perror("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }
  llenar_arreglo(a);
  imprimir_arreglo(a);

  printf("Probando procesos\n");
  for(i=0;i<N_PROC;i++){
    if((pipe(&pipefd[i][0]))==-1){
      perror("Error al crear tuberia");
      exit(EXIT_FAILURE);
    }
    if((pid=fork())==-1){
      perror("Error al crear el proceso");
      exit(EXIT_FAILURE);
    }
    if(!pid){
      proceso_hijo(i,a,&pipefd[i][0]);
    }
  }
  proceso_padre(pipefd,a);
  free(a);
  return 0;
}
