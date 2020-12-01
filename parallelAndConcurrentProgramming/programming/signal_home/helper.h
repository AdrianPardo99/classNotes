#ifndef HELPER_H

/*
 * @author Adrian Gonzalez Pardo
 **/

#define HELPER_H

/*
 * @return devuelve la memoria almacenada para un arreglo de tamanio MUESTRAS
 **/
float *reservar_memoria();
/*
 * @params float* es el arreglo a ser imprimido
 **/
void print_float_array(float*);
/*
 * @params float* es el arreglo a ser llenado
 * @params int es el tipo de llenado, ya sea por el archivo o por la funcion de procesamiento
 **/
void fill_array(float*,int);

#endif
