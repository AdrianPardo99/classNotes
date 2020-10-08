#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_PROC 2
#define EVER 1
#define N 32

void procesoHijo(int,int* );
void procesoPadre();
int* reservarMemoria();
void llenarArreglo(int*);
void imprimirArreglo(int*);
int buscarMayor(int*);
int buscarMenor(int*);

int main () {
	register int np=0;
	pid_t pid;
	int* datos;

	printf("Probando Procesos...\n");
	
	datos = reservarMemoria();	
	llenarArreglo(datos);
	imprimirArreglo(datos);
	for(np = 0;np < NUM_PROC; np++){
		pid = fork();
		if (pid == -1) {
			perror("Error al crear al proceso\n");
			exit(EXIT_FAILURE);	
		}
	
		if(!pid){
			procesoHijo(np,datos);
		}
	}
	
	procesoPadre();
	free(datos);
	return 0;	

}

int buscarMayor(int* datos){
	int mayor = *datos;
	for(int i = 1;i<N;i++){
		if(*(datos+i) > mayor){
			mayor = *(datos+i);
		}
	}
	return mayor;
}

int buscarMenor(int* datos){
	int menor = *datos;

	for (int i = 0; i<N;i++){
		if(*(datos+i) < menor){
			menor = *(datos+i);
		}
	}
	return menor;
}

void imprimirArreglo(int* datos){
	for(register int n=0; n<N ; n++){
		if(!(n%16))
			printf("\n");
		printf("%3d ",*(datos+n));
	}
	printf("\n");
}
void llenarArreglo(int* datos){
	for (register int n = 0;n < N;n++){
		*(datos+n) = rand()%256;	
	}
}

int* reservarMemoria(){
	int* mem = NULL;	
	mem = (int*)malloc(sizeof(int)*N);
	if (mem == NULL){
		perror("Error al obtener memoria...\n");
		exit(EXIT_FAILURE);
	}
	return mem;
}
void procesoPadre(){
	pid_t pid;
	int status;
	for (int np=0;np < NUM_PROC;np++){
		pid = wait(&status);
		printf("Proceso hijo %d con pid: %d, regresa: %d \n",np,pid,status>>8);
	}
}	

void procesoHijo(int np,int* datos) {
	int mayor,menor;
	if (np == 0){
		mayor = buscarMayor(datos);
		exit(mayor);
	}else if(np == 1){
		menor = buscarMenor(datos);
		exit(menor);
	}
	exit(np);
}
