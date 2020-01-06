#include <stdio.h>
#include <stdlib.h>
void fun();
int main(int argc, char *argv[]) {
  fun();
  return 0;
}

void fun(){
  printf("Invocando fun()\n");
  fun();
  printf("Concluyo fun()\n");
}
