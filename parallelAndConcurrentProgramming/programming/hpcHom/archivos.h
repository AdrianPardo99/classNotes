#ifndef ARCHIVOS_H

/*
 * @author Adrian Gonzalez Pardo
 */

#define ARCHIVOS_H

/*
 * @params float* es el arreglo que sera almacenado en un archivo
 * @params char* es el nombre del archivo
 * @params int es el tamanio de datos que va a guardar el archivo
 */
void guardar_archivo(float*,char*,int);

/*
 * @params float* es el arreglo en el que se almacenaran los datos
 * @params char* es el nombre del archivo
 * @params int es el tamanio de datos que va a leer y almacenara en float*
 */
void leer_archivo(float*,char*,int);

#endif
