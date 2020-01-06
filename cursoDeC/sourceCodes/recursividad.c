#include <stdio.h>
#include <stdlib.h>

void fun(int nivel, int nodo, int profundidad, int *cont);
void fun3(int nivel, int nodo, int profundidad, int *cont);
void funN(int nivel, int nodo, int profundidad, int *cont, int base);

int main(int argc, char *argv[]){
	int nivel=0, profundidad= 4, nodo=0;
	int cont=0, base= 4;

	//fun(nivel, nodo, profundidad, &cont);
	//fun3(nivel, nodo, profundidad, &cont);
	funN(nivel, nodo, profundidad, &cont, base);

	printf("conteo de nodos= %d\n", cont);

	return 0;
}

void fun(int nivel, int nodo, int profundidad, int *cont){
	int k=0;

	if(nivel>=profundidad)
	  return;

	(*cont)++;

	for(k=0; k<nivel; k++)
		printf("   ");

	printf("E: nivel= %d nodo= %d\n", nivel, nodo);

	fun(nivel+1, 2*nodo + 0, profundidad, cont);
	fun(nivel+1, 2*nodo + 1, profundidad, cont);

	/*for (k=0; k<nivel; k++)
	   printf("   ");

	printf("S: nivel= %d\n", nivel);*/
}

void fun3(int nivel, int nodo, int profundidad, int *cont){
	int k=0;

	if(nivel>=profundidad)
	  return;

	(*cont)++;

	for(k=0; k<nivel; k++)
	   printf("   ");

	printf("E: nivel= %d nodo= %d\n", nivel, nodo);

	fun3(nivel+1, 3*nodo + 0, profundidad, cont);
	fun3(nivel+1, 3*nodo + 1, profundidad, cont);
	fun3(nivel+1, 3*nodo + 2, profundidad, cont);

	/*for (k=0; k<nivel; k++)
	   printf("   ");

	printf("S: nivel= %d\n", nivel);*/
}

void funN(int nivel, int nodo, int profundidad, int *cont, int base){
	int k=0;

	if(nivel>=profundidad)
	  return;

	(*cont)++;

	for (k=0; k<nivel; k++)
	   printf("   ");

	printf("E: nivel= %d nodo= %d\n", nivel, nodo);

	for (k=0; k<base; k++)
	   funN(nivel+1, base*nodo + k, profundidad, cont, base);

	/*for (k=0; k<nivel; k++)
	   printf("   ");

	printf("S: nivel= %d\n", nivel);*/
}
