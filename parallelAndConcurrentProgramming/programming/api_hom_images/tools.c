#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * @author Adrian Gonzalez Pardo
 **/

void call_repair(char *src){
  int status;
  char *file[3];
  file[0]="/usr/bin/convert";
  file[1]=src;
  file[2]=src;
  if(fork()==0){
    execv(file[0],file);
  }
  wait(&status);
  printf("Repair complete\n");
}
