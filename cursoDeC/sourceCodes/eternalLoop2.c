#include <stdio.h>
#include <stdlib.h>
void fun(int,int);
int main(int argc, char *argv[]) {
  int profundidad=1000000;
  if(argc>1){
    profundidad=atoi(argv[1]);
  }
  fun(0,profundidad);
  return 0;
}

void fun(int nivel,int profundidad){
  if(nivel==profundidad){
    return;
  }
  printf("Invocando fun() %d, profundidad: %d\n",nivel++,profundidad);
  fun(nivel,profundidad);
  printf("Concluyo fun() nivel: %d, profundidad: %d\n",nivel,profundidad);
}
