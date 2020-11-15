#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * @author Adrian Gonzalez Pardo
 **/

/*
 * @return a retorna la memoria para trabajar
 **/
int *reservar_memoria(){
  int *a=(int*)malloc(sizeof(int)*N);
  if(!a){
    perror("Error allocating memory"),exit(EXIT_FAILURE);
  }
  return a;
}

/*
 * @params a es el arreglo que se va a imprimir
 **/
 void print_array(int *a){
   register int i;
   for(i=0;i<N;i++){
     printf("%5d%s",*(a+i),(i+1)%16==0&&i>0?"\n":"");
   }
   printf("\n");
 }

 /*
  * @params a es el arreglo que sera llenado de un valor aleatorio
  **/
 void llenar_arreglo(int *a){
   register int i;
   for(i=0;i<N;i++){
     *(a+i)=rand()%RANGE;
   }
 }
