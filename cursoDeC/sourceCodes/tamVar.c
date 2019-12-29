#include <stdlib.h>
#include <stdio.h>

int main(void){
  int a;
  char b;
  float c;
  long d;
  double e;
  /*Llamada de sizeof devuelve un valor equivalente en bytes
   * por ello se multiplica por 8 para hacer la conversion de bytes a bits
   * por otro lado se hacen llamadas a tipos de datos que estan
   * nativos del lenguaje por ello los de tipo unsigned y combinaciones
   * long otherDate no se encuentran en esta lista ya que sizeof no detecta
   * diferencia alguna. */
  printf("Size of int = %lu bits is equal to %lu bytes\n"
      "Size of char = %lu bits is equal to %lu byte\n"
      "Size of float = %lu bits is equal to %lu bytes\n"
      "Size of long = %lu bits is equal to %lu bytes\n"
      "Size of double = %lu bits is equal to %lu bytes\n",
      sizeof(int)*8,sizeof(int),sizeof(char)*8,sizeof(char),
      sizeof(float)*8,sizeof(float),
      sizeof(long)*8,sizeof(long),sizeof(double)*8,sizeof(double));
  return 0;
}
