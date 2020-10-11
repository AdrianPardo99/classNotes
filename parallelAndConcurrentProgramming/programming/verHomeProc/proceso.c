#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "defs.h"
#include "helper.h"
#include "procesamiento.h"
#include "proceso.h"

void proceso_padre(){
  printf("\n\nProceso padre: \n");
  pid_t pid;
  int status;//*r1,r;
  int register i;
  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    printf("Proceso con pid %d finalizo con retorno %d \n",
      pid,status>>8);
  }
}

void proceso_hijo(int id,int *a){
  int r=0;
  printf("Proceso hijo %d: realiza tarea de %s\n",getpid(),
    (id==0)?("elemento mayor del arreglo"):
    ((id==1)?("elemento menor del arreglo"):
    ((id==2)?("promedio del arreglo"):
    ("cuantos numeros pares existe en el arreglo"))));
  switch(id){
    case 0:
      r=mayor_valor(a);
    break;
    case 1:
      r=menor_valor(a);
    break;
    case 2:
      r=promedio(a);
    break;
    case 3:
      r=pares(a);
    break;
  }
  free(a);
  exit(r);
}
