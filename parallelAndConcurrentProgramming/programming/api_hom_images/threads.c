#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "imagen.h"
#include "defs.h"
#include "processing_image.h"

extern bmpInfoHeader info;
extern unsigned char *imgGray,*imgFiltrada;
extern int type;

void *processing_pb(void* arg){
  int *id=(int*)arg;
  printf("Thread %d init\n",*id);
  (type==0)?(filtroPB(imgGray,imgFiltrada,info.width,info.height,*id)):
    (filtroPB_bloque(imgGray,imgFiltrada,info.width,info.height,*id));
  printf("Thread %d finish\n",*id);
  pthread_exit(arg);
}
