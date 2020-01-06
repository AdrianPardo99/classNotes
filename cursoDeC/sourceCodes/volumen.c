#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double ***vol= NULL;
	int i=0, j=0, k=0;
	int M= 10, N= 10, L= 10;
	vol= (double ***) malloc(L*sizeof(double **));

	for(i=0; i<L; i++){
		vol[i]= (double **) malloc(M*sizeof(double *));
		for(j=0; j<M; j++){
			vol[i][j]= (double *) malloc(N*sizeof(double));
			for(k=0; k<N; k++)
				vol[i][j][k]= i*j*k;
		}
	}
	for(i=0; i<L; i++){
		printf("i= %d\n", i);
		for (j=0; j<M; j++){
			for (k=0; k<N; k++)
				printf("%0.2lf  ", vol[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}

	for (i=0; i<L; i++){
		for (j=0; j<M; j++)
			free(vol[i][j]);
		free(vol[i]);
	}
	free(vol);
	return 0;
}
