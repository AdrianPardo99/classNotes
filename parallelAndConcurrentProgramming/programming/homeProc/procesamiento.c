#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "helper.h"
#include "procesamiento.h"

int mayor_valor(int *a){
  register int i;
  int m=*a;
  for(i=1;i<N;i++){
    if(m<*(a+i)){
      m=*(a+i);
    }
  }
  return m;
}

int menor_valor(int *a){
  register int i;
  int m=*a;
  for(i=1;i<N;i++){
    if(m>*(a+i)){
      m=*(a+i);
    }
  }
  return m;
}

int promedio(int *a){
  register int i;
  int p=0;
  for(i=0;i<N;i++){
    p+=*(a+i);
  }
  return p/N;
}

int *pares(int *a){
  int *b,coun=0;
  register int i;
  b=reserva_memoria(N);
  if(b==NULL){
    perror("Error al asignar memoria");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<N;i++){
    if(isPair(*(a+i))){
      *(b+coun)=*(a+i);
      coun++;
    }
  }
  for(i=coun;i<N;i++){
    *(b+i)=0;
  }
  return b;
}
