#include <stdio.h>
#include <math.h>
#include "defs.h"

void genera_seno(float *s){
  float f=1000,fs=45000;
  register int n;
  for(n=0;n<MUESTRAS;n++){
    *(s+n)=sinf(2*n*M_PI*f/fs);
  }
}
