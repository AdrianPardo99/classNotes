#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "defs.h"
#include "helper.h"

int isPair(int a){
  return a%2==0;
}

int *reserva_memoria(int s){
  return (int*)malloc(sizeof(int)*s);
}

void llenar_arreglo(int *a){
  srand(time(NULL));
  register int i;
  for(i=0;i<N;i++){
    *(a+i)=rand()%100+1;
  }
}

void imprimir_arreglo(int *a){
  register int i;
  printf("Arreglo:\n");
  for(i=0;i<N;i++){
    if(*(a+i)==0){
      break;
    }
    if(i%16==0){
      printf("\n");
    }
    printf("%4d",*(a+i));
  }
  printf("\n");
}
