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
  int fd[2],*a;
  a=reserva_memoria(N);
  if(a==NULL){
    perror("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }
  llenar_arreglo(a);
  imprimir_arreglo(a);
  if(pipe(fd)==-1){
    perror("Error al crear el pipe");
    exit(EXIT_FAILURE);
  }
  printf("Probando procesos\n");
  for(i=0;i<N_PROC;i++){
    if((pid=fork())==-1){
      perror("Error al crear el proceso");
      exit(EXIT_FAILURE);
    }
    if(!pid){
      proceso_hijo(i,fd,a);
    }
  }
  proceso_padre(fd);
  close(*fd);
  close(*(fd+1));
  free(a);
  return 0;
}
