#ifndef PROCESAMIENTO_H
/*
 * @author Adrian Gonzalez Pardo
 **/
#define PROCESAMIENTO_H

/*
 * @params float* es el arreglo donde sera almacenado
 **/
void create_hann_window(float*);

/*
 * @params float* es el arreglo donde se almacenara la operacion
 * @params float es la frecuencia f
 * @params float es la frecuencia fs
 **/
void create_sin_function(float*,float,float);

/*
 * @params float* es el arreglo donde sera almacenado
 **/
void read_pulse_signal(float*);

#endif
