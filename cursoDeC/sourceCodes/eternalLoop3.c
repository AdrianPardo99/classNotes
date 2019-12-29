#include <stdio.h>
#include <stdlib.h>
void fun(int,int);
void fun1(int,int);
void fun2(int,int);
int main(int argc, char *argv[]) {
  int profundidad=1000000;
  if(argc>1){
    profundidad=atoi(argv[1]);
  }
  printf("Forma 1\n");
  fun(0,profundidad);
  printf("Forma 2\n");
  fun1(0,profundidad);
  printf("Forma 3\n");
  fun2(0,profundidad);
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

void fun1(int nivel,int profundidad){
  if(nivel==profundidad){
    return;
  }
  nivel++;
  fun1(nivel,profundidad);
  printf("fun1() %d, profundidad: %d\n",nivel,profundidad);
}

void fun2(int nivel,int profundidad){
  if(nivel==profundidad){
    return;
  }
  printf("fun2() %d, profundidad: %d\n",nivel++,profundidad);
  fun2(nivel,profundidad);
}
