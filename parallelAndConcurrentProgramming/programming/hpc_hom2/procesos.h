#ifndef PROCESOS_H

/*
 * @author Adrian Gonzalez Pardo
 **/

#define PROCESOS_H

/*
 * @params int** es el descriptor del pipe
 */
void proceso_padre(int**);

/*
 * @params int es el id del proceso hijo
 * @params int* es el descriptor del pipe
 */
void proceso_hijo(int,int*);

#endif
