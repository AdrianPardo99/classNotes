#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "defs.h"
#include "helper.h"
#include "procesamiento.h"
#include "proceso.h"

void proceso_padre(int *fd){
  printf("\n\nProceso padre: \n");
  pid_t pid;
  int status,*r1,r;
  int register i;
  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    if((status>>8)>=0&&(status>>8)<=2){
      read(*fd,(void*)&r,sizeof(int));
    }else{
      r1=reserva_memoria(N);
      if(r1==NULL){
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
      }
      read(*fd,(void*)&*r1,sizeof(int)*N);
    }
    printf("Proceso con pid %d y retorno %d & ",
      pid,status>>8);
    switch((status>>8)){
      case 0:
        printf("Valor mayor del arreglo: %d\n",r);
      continue;
      case 1:
        printf("Valor menor del arreglo: %d\n",r);
      continue;
      case 2:
        printf("Promedio del arreglo: %d\n",r);
      continue;
      case 3:
        imprimir_arreglo(r1);
      continue;
    }
  }
  close(*fd);
  close(*(fd+1));
}

void proceso_hijo(int id,int *fd,int *a){
  int r,*r1;
  switch(id){
    case 0:
      r=mayor_valor(a);
      write(*(fd+1),(void*)&r,sizeof(int));
    break;
    case 1:
      r=menor_valor(a);
      write(*(fd+1),(void*)&r,sizeof(int));
    break;
    case 2:
      r=promedio(a);
      write(*(fd+1),(void*)&r,sizeof(int));
    break;
    case 3:
      r1=pares(a);
      write(*(fd+1),(void*)&*r1,sizeof(int)*N);
      free(r1);
    break;
  }
  free(a);
  close(*fd);
  close(*(fd+1));
  exit(id);
}
