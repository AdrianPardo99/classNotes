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
  printf("\nProceso padre: \n");
  pid_t pid[N_PROC];
  int status[N_PROC];//*r1,r;
  int register i;
  for(i=0;i<N_PROC;i++){
    pid[i]=wait(&status[i]);
    printf("Proceso finalizado %d\n",pid[i]);
  }
  pid_t aux;
  int saux;
  for(i=0;i<N_PROC;i++){
    for(register int j=0;j<N_PROC-i;j++){
      if(pid[j]>pid[j+1]){
        aux=pid[j];
        pid[j]=pid[j+1];
        pid[j+1]=aux;
        saux=status[j];
        status[j]=status[j+1];
        status[j+1]=saux;
      }
    }
  }
  for(i=0;i<N_PROC;i++){
    printf("Proceso con pid %d finalizo con retorno %d\n\tel cual"
      " es la operacion %s\n\n",
      pid[i],status[i]>>8,(i==0)?("mayor valor del arreglo"):
      ((i==1)?("menor valor del arreglo"):
      ((i==2)?("promedio entero del arreglo"):
      ("numero de pares en el arreglo"))));
  }
}

void proceso_hijo(int id,int *a){
  int r=0;
  /*printf("Proceso hijo %d: realiza tarea de %s\n",getpid(),
    (id==0)?("elemento mayor del arreglo"):
    ((id==1)?("elemento menor del arreglo"):
    ((id==2)?("promedio del arreglo"):
    ("cuantos numeros pares existe en el arreglo"))));*/
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
