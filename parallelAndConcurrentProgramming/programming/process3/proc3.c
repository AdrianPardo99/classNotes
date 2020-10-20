#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N_PROC 4

void proceso_padre(int pipefd[N_PROC][2]);
void proceso_hijo(int id,int pipefd[]);

int main(void){
  pid_t pid;
  register int i;
  int pipefd[N_PROC][2],edo_pipe;
  printf("Probando procesos...\n");

  for(i=0;i<N_PROC;i++){
    if((edo_pipe=pipe(&pipefd[i][0]))==-1){
      perror("Error al crear la tuberia");
      exit(EXIT_FAILURE);
    }

    if((pid=fork())==-1){
      perror("Error al crear el proceso");
    }
    if(!pid){
      proceso_hijo(i,&pipefd[i][0]);
    }
  }
  proceso_padre(pipefd);
  return 0;
}

void proceso_padre(int pipefd[N_PROC][2]){
  pid_t pid;
  int status,r,id;
  int register i;

  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    id=status>>8;
    close(pipefd[id][1]);
    read(pipefd[id][0],&r,sizeof(int));
    printf("Proceso con pid %d y retorno %d & resultado %d de la %s\n",
        pid,id,r,(id==0)?("suma"):((id==1)?("resta"):
        ((id==2)?("multiplicacion"):("division"))));
    close(pipefd[id][0]);
  }
}

void proceso_hijo(int id,int pipefd[]){
  int n1=20,n2=4,suma,resta,multi,divi;
  close(pipefd[0]);
  switch(id){
    case 0:
      suma=n1+n2;
      write(pipefd[1],&suma,sizeof(int));
      close(pipefd[1]);
    break;
    case 1:
      resta=n1-n2;
      write(pipefd[1],&resta,sizeof(int));
      close(pipefd[1]);
    break;
    case 2:
      multi=n1*n2;
      write(pipefd[1],&multi,sizeof(int));
      close(pipefd[1]);
    break;
    case 3:
      divi=n1/n2;
      write(pipefd[1],&divi,sizeof(int));
      close(pipefd[1]);
    break;
  }
  exit(id);
}
