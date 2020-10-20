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

void bubble_sort(int *a){
  int a1;
  register int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N-i;j++){
      if(*(a+j)>*(a+j+1)){
        a1=*(a+j);
        *(a+j)=*(a+j+1);
        *(a+j+1)=a1;
      }
    }
  }
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

void multiplica_const(int *a){
  register int i;
  for(i=0;i<N;i++){
    *(a+i)*=CONSTANT;
  }
}
