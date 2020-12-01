#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defs.h"
#include "archivos.h"

/*
 * @author Adrian Gonzalez Pardo
 **/

/*
 * @params *a es el arreglo donde sera almacenado
 **/
void create_hann_window(float *a){
  register int i;
  for(i=0;i<MUESTRAS;i++){
    *(a+i)=powf(sinf((M_PI*i)/(MUESTRAS-1)),2);
  }
  guardar_archivo(a,"HannWindow.dat",MUESTRAS);
}

/*
 * @params *a es el arreglo donde se almacenara la operacion
 * @params f es la frecuencia
 * @params fs es la frecuencia
 **/
void create_sin_function(float *a,float f,float fs){
  register int i;
  for(i=0;i<MUESTRAS;i++){
    *(a+i)=sinf(2*i*M_PI*f/fs);
  }
}

/*
 * @params *a es el arreglo donde sera almacenado
 **/
void read_pulse_signal(float *a){
  leer_archivo(a,"PulseSensor.dat",MUESTRAS);
}
