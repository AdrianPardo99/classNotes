#include <stdio.h>
#include <stdlib.h>

int main(void){
  int p[]={1,2,3,4,5},i;
  char p1[]={'a','b','c','d','e'};
  void *pv;
  pv=(void*)p;
  /*Modo de obtener el tamanio del array solo con operacion sizeof y
   * conociendo el tipo de dato*/
  printf("Integer array with void pointer\n");
  for(i=0;i<(sizeof(p)/sizeof(int));i++){
    printf("Void pointer position [%d] address %p that contain %d\n",
        i,pv,*(int*)pv);
    pv=(void*)((char*)pv+1);
    /*Cambio de tipo de valor int to char*/
  }
  /*Modo de obtener el tamanio del array solo con operacion sizeof y
   * sin conocer el tipo de dato*/
  printf("Char array with void pointer\n");
  pv=(void*)p1;
  for(i=0;i<(sizeof(p1)/sizeof(*p1));i++){
    printf("Void pointer position [%d] address %p that contain %c\n",
        i,pv,*(char*)pv);
    pv=(void*)((int*)pv+1);
    /*Segundo cambio char to int*/
  }
  return 0;
}
