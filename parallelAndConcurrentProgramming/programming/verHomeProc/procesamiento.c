/*
 * @author Adrian Gonzalez Pardo
 */
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "procesamiento.h"

int isPair(int a){
  return a%2==0;
}

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

int pares(int *a){
  int coun=0;
  register int i;
  for(i=0;i<N;i++){
    if(isPair(*(a+i))){
      coun++;
    }
  }
  return coun;
}
