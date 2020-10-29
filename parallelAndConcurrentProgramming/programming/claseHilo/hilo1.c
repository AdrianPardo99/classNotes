#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_HILOS 4

void * funHilo( void *arg );

int main(){
	register int nh;
	pthread_t tids[NUM_HILOS];
	int *resultado, nhs[NUM_HILOS];

	printf("Ejemplo de hilos\n");

	for( nh = 0; nh < NUM_HILOS; nh++ ){
		nhs[nh] = nh;
		//nhs[0] = 0;
		//nhs[1] = 1;
		//nhs[2] = 2;
		//nhs[3] = 3;
		pthread_create( &tids[nh] , NULL, funHilo, (void *)&nhs[nh] );
	}

	for( nh = 0; nh < NUM_HILOS; nh++ ){
		pthread_join( tids[nh], (void **)&resultado );
		printf("Resultado: %d \n", *resultado);
		free( resultado );
	}

	return 0;
}

void * funHilo( void *arg ){
	int nh = *(int *)arg;
	int num1 = 20, num2 = 4;
	int *res = malloc( sizeof(int) );

	printf("Hilo %d en ejecución \n", nh);
	if( nh == 0 )
		*res = num1 + num2;
	else if( nh == 1 )
		*res = num1 - num2;
	else if( nh == 2 )
		*res = num1 * num2;
	else if( nh == 3 )
		*res = num1 / num2;

	pthread_exit( (void *)res );
}
