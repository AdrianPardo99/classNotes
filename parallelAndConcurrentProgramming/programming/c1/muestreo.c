#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MUESTRAS 512

void generarSeno(float*);
void guardaDatos(float*);

int main(void){
  float seno[MUESTRAS];

  generarSeno(seno);
  guardaDatos(seno);

  return 0;
}

void generarSeno(float *s){
  float f=1000,fs=45000;
  register int n;
  /* Lenguaje C tiene 3 especificadores de acceso
   *
   * register Indica al compilador que reserve un
   *  registro para la variable en lugar de
   *  una dirección de memoria
   *
   * | Jerarquia |
   * Procesador ------- Cache -------- Principal
   *                    SRAM             DRAM
   *
   * static Se usa para declarar variables locales 
   *  con alcance global. Su valor no se pierde cuando
   *  salen de la función
   *
   * extern Se utiliza cuando tengo un programa en
   *  varios módulos y necesito utilizar una variable
   *  que ha sido declarada en un módulo X que ha sido
   *  declarada en un módulo Y
   **/
  for(n=0;n<MUESTRAS;n++){
    *(s+n)=sinf(2*M_PI*f*n/fs);
  }
}

void guardaDatos(float *s){
  FILE *apArch;
  register int n;
  apArch=fopen("seno.dat","w");
  if(apArch==NULL){
    perror("Error when try to open file");
    exit(EXIT_FAILURE);
  }
  for(n=0;n<MUESTRAS;n++){
    fprintf(apArch,"%f\n",*(s+n));
  }
  fclose(apArch);
}
