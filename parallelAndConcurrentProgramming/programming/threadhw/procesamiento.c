#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "procesamiento.h"


int check_par(int a){
  return a%2==0;
}

int check_is_prime(int a){
  if(a==0){
    return 0;
  }else if(a==1){
    return 1;
  }
  register int i;
  for(i=2;i<a;i++){
    if(a%i==0){
      return 0;
    }
  }
  return 1;
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
  int p=0;
  register int i;
  for(i=0;i<N;i++){
    p+=*(a+i);
  }
  return p/N;
}

int pares(int *a){
  int p=0;
  register int i;
  for(i=0;i<N;i++){
    if(check_par(*(a+i))){
      p++;
    }
  }
  return p;
}

int primos(int *a){
  int p=0;
  register int i;
  for(i=0;i<N;i++){
    if(check_is_prime(*(a+i))){
      p++;
      if(p%16==0&&p>0){
        printf("\n");
      }
      printf("%4d",*(a+i));
    }
  }
  printf("\n");
  return p;
}
