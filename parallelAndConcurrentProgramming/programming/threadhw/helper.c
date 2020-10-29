/*
 * @author Adrian Gonzalez Pardo
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper.h"
#include "defs.h"

int *reserva_memoria(){
  int *a=(int*)malloc(sizeof(int)*N);
  if(!a){
    perror("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }
  return a;
}

void llenar_arreglo(int *a){
  srand(time(NULL));
  register int i;
  for(i=0;i<N;i++){
    *(a+i)=rand()%256;
  }
}

void imprimir_arreglo(int *a){
  register int i;
  for(i=0;i<N;i++){
    if(i%16==0&&i>0){
      printf("\n");
    }
    printf("%4d",*(a+i));
  }
  printf("\n");
}
