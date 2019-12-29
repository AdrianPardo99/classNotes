#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int *p=NULL,*q=NULL,*arr=NULL;
  int x=0,y=0,N=100,k;
  p=&x;
  *p=2019;
  printf("El valor de x = %d \n",x);
  printf("La direccion de x = %X \n",&x);
  printf("El valor de p= %X\n",p);
  printf("El contenido a donde apunta p= %d\n",*p);
  printf("La direccion de p= %X\n",&p);

  //Aumenta en 1 el contenido de a donde apunta p
  (*p)++;
  printf("1 Valores x= %d\tp= %X\t*p=%d\n",x,p,*p);
  (*p)*=9;
  (*p)*=6;
  (*p)+=3;
  printf("2 Valores x= %d\tp= %X\t*p=%d\n",x,p,*p);
  /*Experimento donde puedes matar secciones de memoria completamente
   * *p++;
   * printf("Valores x= %d\tp= %X\t*p=%d\n",x,p,*p);
   * *p++;
   * printf("Valores x= %d\tp= %X\t*p=%d\n",x,p,*p);*/
  /*Fuera del experimento se usarara un apartado de memoria dinamica arr[N]
   * Segun la descripcion de malloc tenemos void *malloc(size_t size);
   * size_t puede ser un valor numerico */
  arr=(int*)malloc(N*sizeof(int));
  /*Escritura y lectura convencional*/
  for(k=0;k<N;k++)
    arr[k]=3*k;

  for(k=0;k<N;k++)
    printf("arr[%d]=%d\n",k,arr[k]);
  /*Finalmente se libera la memoria*/
  free(arr);
  return 0;
}
