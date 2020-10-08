#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N_PROC 8
#define EVER 1
void proceso_hijo(int);
void proceso_padre();

int main(void){
  float n1=45,n2=13,suma,resta;
  printf("Probando procesos...\n");
  pid_t pid;
  register int i;
  for(i=0;i<N_PROC;i++){
    if((pid=fork())==-1){
      perror("Error al crear el proceso...");
      exit(EXIT_FAILURE);
    }
    if(!pid){
      proceso_hijo(i);
    }
  }
  proceso_padre();
  return 0;
}

void proceso_hijo(int n){
  for(;EVER;);

  exit(n);
}

void proceso_padre(){
  register int i;
  pid_t pid;
  int estado;
  for(i=0;i<N_PROC;i++){
    pid=wait(&estado);
    printf("Proceso hijo: %d con pid: %d\n",estado>>8,pid);
  }
}
