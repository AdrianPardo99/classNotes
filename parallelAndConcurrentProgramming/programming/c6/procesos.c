#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N_PROC 4
void proceso_padre(int*);
void proceso_hijo(int,int*);

int main(){
  pid_t pid;
  register int i;
  int pipefd[2];
  printf("Probando procesos\n");
  if(pipe(pipefd)==-1){
    perror("Error al crear el pipe");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<N_PROC;i++){
    if((pid=fork())==-1){
      perror("Error al crear el proceso");
      exit(EXIT_FAILURE);
    }
    if(!pid){
      proceso_hijo(i,pipefd);
    }
  }
  proceso_padre(pipefd);
  return 0;
}

void proceso_padre(int *pipefd){
  pid_t pid;
  int status,r;
  int register i;
  for(i=0;i<N_PROC;i++){
    pid=wait(&status);
    read(*pipefd,(void*)&r,sizeof(int));
    printf("Proceso con pid %d y retorno %d & resultado %d\n",
        pid,status>>8,r);
  }
  close(*pipefd);
  close(*(pipefd+1));
}

void proceso_hijo(int id,int *pipefd){
  int n1=20,n2=4,suma,resta,multi,divi;
  switch(id){
    case 0:
      suma=n1+n2;
      write(*(pipefd+1),(void*)&suma,sizeof(int));
    break;
    case 1:
      resta=n1-n2;
      write(*(pipefd+1),(void*)&resta,sizeof(int));
    break;
    case 2:
      multi=n1*n2;
        write(*(pipefd+1),(void*)&multi,sizeof(int));
    break;
    case 3:
      divi=n1/n2;
      write(*(pipefd+1),(void*)&divi,sizeof(int));
    break;
  }
  close(*pipefd);
  close(*(pipefd+1));
  exit(id);
}
