#include <stdio.h>
#include <stdlib.h>
void funTree(int,int,int,int*,int);
int main(int argc, char *argv[]) {
  int base=3,profundidad=3,con=0;
  funTree(0,0,profundidad,&con,base);
  return 0;
}

void funTree(int nivel, int nodo, int profundidad, int *con,int base){
  int k;
  if(nivel>=profundidad){
    return;
  }
  printf("\n");
  for(k=0;k!=nivel;k++){
    printf("\t");
  }
  printf("Nivel: %d\n",nivel);
  for(k=0;k!=base;k++){
    printf("\tNodo: %d\t Hoja: %d\n",nodo+k,(*con)++);
  }
  for(k=0;k!=base;k++){
    funTree(nivel+1,base*nodo+k,profundidad,con,base);
  }
}
