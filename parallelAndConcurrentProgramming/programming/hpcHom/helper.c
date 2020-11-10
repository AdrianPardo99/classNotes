#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "procesamiento.h"

/*
 * @author Adrian Gonzalez Pardo
 */

/*
 * @return devuelve la memoria almacenada para un arreglo de tamanio MUESTRAS
 */
float *reservar_memoria(){
  float *a=(float*)malloc(sizeof(float)*MUESTRAS);
  if(!a){
    perror("Error al alamacenar memoria"),exit(EXIT_FAILURE);
  }
  return a;
}
/*
 * @params *a es el arreglo a ser imprimido
 */
void print_float_array(float *a){
  register int i;
  for(i=0;i<MUESTRAS;i++){
    printf("%f %s",*(a+i),i%8==0&&i>0?"\n":" ");
  }
  printf("\n");
}
/*
 * @params *a es el arreglo a ser llenado
 * @params d es el tipo de llenado, ya sea por el archivo o por la funcion de procesamiento
 */
void fill_array(float *a,int d){
  d==0?(create_hann_window(a)):(read_pulse_signal(a));
}
