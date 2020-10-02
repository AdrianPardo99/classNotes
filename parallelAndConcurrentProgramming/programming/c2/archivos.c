#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

void guarda_datos(float *s){
  FILE *apArch;
  register int n;
  apArch=fopen("seno.dat","w");
  if(!apArch){
    perror("Error when try to open file");
    exit(EXIT_FAILURE);
  }
  for(n=0;n<MUESTRAS;n++){
    fprintf(apArch,"%f\n",*(s+n));
  }
  fclose(apArch);
}
