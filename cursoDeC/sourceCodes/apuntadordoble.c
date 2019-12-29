#include <stdio.h>
#include <stdlib.h>

#define OK 		1
#define ERROR	0

int crearVector(int **arr, int N);
int desplegarVector(int *arr, int N);
int destruirVector(int *arr);
int destruirVectorSerguramente(int **arr);

int main(int argc, char *argv[]){
	int **d= NULL;
	int *p= NULL, *q= NULL;
	int *vec= NULL;
	int x=0, N= 100, sw= OK;

	printf("x= %d\n", x);

	p= &x;
	*p= 2019;

	printf("x= %d\n", x);

	// apuntador doble:
	d= &p;
	q= *d;
	(*q)++;

	printf("x= %d\n", x);

	sw= crearVector(&vec, N);

	if (sw==OK)
	  {
		desplegarVector(vec, N);
		//vec= NULL;
		//destruirVector(vec);
		printf("vec= %X\n", vec);
		destruirVectorSerguramente(&vec);
		printf("vec= %X\n", vec);

	  }

	return 0;
}

int crearVector(int **arr, int N){
	int *loc= NULL;
	int k=0;

	loc = (int *) malloc(N*sizeof(int));

	if (loc==NULL)
	  return(ERROR);

	for (k=0; k<N; k++)
	   loc[k]= 6;

	*arr= loc;		// mecanismo de paso por referencia
	// arr= &loc;   // trabajar con el paso por valor
					// i.e copia

	return(OK);
}

int desplegarVector(int *arr, int N){
	int k=0;

	if (arr==NULL || N<=0)
	  return(ERROR);

	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);

	return(OK);
}

int destruirVector(int *arr){
	if (arr!=NULL){
		free(arr);
		return(OK);
	}
	return(ERROR);
}

int destruirVectorSerguramente(int **arr){
	int *loc= NULL;

	loc= *arr;

	if(loc!=NULL){
		free(loc);
		*arr= NULL;
	  return(OK);
	}
	return(ERROR);
}
