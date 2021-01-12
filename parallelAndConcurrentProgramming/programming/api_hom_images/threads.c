#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "imagen.h"
#include "defs.h"
#include "processing_image.h"

/*
 * @author Adrian Gonzalez Pardo
 **/

extern bmpInfoHeader info;
extern unsigned char *imgGray,*imgFiltrada;
extern int type;

void *processing_pb(void* arg){
  int *id=(int*)arg;
  printf("Thread pb %d init\n",*id);
  (type==0)?(filtroPB(imgGray,imgFiltrada,info.width,info.height,*id)):
    (filtroPB_bloque(imgGray,imgFiltrada,info.width,info.height,*id));
  printf("Thread pb %d finish\n",*id);
  pthread_exit(arg);
}
void *processing_sobel(void* arg){
  int *id=(int*)arg;
  printf("Thread sobel %d init\n",*id);
  (type==0)?(sobel(imgGray,imgFiltrada,info.width,info.height,*id)):
    (sobel_bloque(imgGray,imgFiltrada,info.width,info.height,*id));
  printf("Thread sobel %d finish\n",*id);
  pthread_exit(arg);
}
