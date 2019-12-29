#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	float **mat= NULL;
	int M= 10, N= 10;
	int i=0, j=0, k=0;

	// creacion de matriz:

	mat= (float **) malloc(M*sizeof(float *));
	//vec= (int *) malloc(N*sizeof(int));

	for (i=0; i<M; i++)
	   mat[i]= (float *) malloc(N*sizeof(float));

	// inicializacion:

	for (i=0; i<M; i++)
	   for (j=0; j<N; j++)
	      mat[i][j]= i*j;

	for (i=0; i<M; i++){
		for (j=0; j<N; j++)
			printf("%0.2f  ", mat[i][j]);
		printf("\n");
	}

	//destruccion de matriz:

	for (i=0; i<M; i++)
		free(mat[i]);
	free(mat);

	return 0;
}

// double **crearMatriz(int M, int N);
// void destruirMatriz(double **mat, int M);
// inicializarMatriz(double **mat, int M, int N);
// multiplicarMatriz(double **mC, double **mA, double **mB, int M, int N, int L);

// int crearMatriz(double ***mat, int M, int N);
// int destruirMatriz(double ***mat, int M);

// C= A*B;
