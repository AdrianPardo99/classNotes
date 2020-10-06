#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  float n1=45,n2=13,suma,resta;
  printf("Probando procesos...\n");
  pid_t pid;
  int status;
  if((pid=fork())==-1){
    perror("Error al crear el proceso...");
    exit(EXIT_FAILURE);
  }
  if(!pid){
    printf("Proceso hijo ejecutando...\nPID hijo: %d\n",getpid());
    suma=n1+n2;
    printf("La suma es: %f\n",suma);
    exit(20);
  }else{
    sleep(5);
    printf("Proceso padre ejecutando...\nPID padre: %d\n",getpid());
    resta=n1,n2;
    printf("La resta es: %f\n",resta);
    pid=wait(&status);
    printf("Proceso terminado con pid: %d y estado: %d\n",pid,status>>8);
  }
  return 0;
}
