#include <stdio.h>
#include <stdlib.h>

/*
 * @author Adrian Gonzalez Pardo
 */

/*
 * @params *a es el arreglo que sera almacenado en un archivo
 * @params *namefile es el nombre del archivo
 * @params t es el tamanio de datos que va a guardar el archivo
 */
void guardar_archivo(float *a,char *namefile,int t){
  FILE *out=fopen(namefile,"w");
  if(!out){
    perror("Error al crear el archivo"),exit(EXIT_FAILURE);
  }
  register int i=0;
  while(i<t){
    fprintf(out,"%f\n",*(a+i));
    i++;
  }
  fclose(out);
}

/*
 * @params *a es el arreglo en el que se almacenaran los datos
 * @params *namefile es el nombre del archivo
 * @params t es el tamanio de datos que va a leer y almacenara en *a
 */
void leer_archivo(float *a,char *namefile,int t){
  FILE *in=fopen(namefile,"r");
  if(!in){
    perror("Error al leer el archivo"),exit(EXIT_FAILURE);
  }
  register int i=0;
  while(i<t){
    fscanf(in,"%f",(a+i));
    *(a+i)-=2200;
    i++;
  }
  fclose(in);
}
