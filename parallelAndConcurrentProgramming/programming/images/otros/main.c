#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "imagen.h"

/* @author Adrian Gonzalez Pardo
 * @version 1
 **/

void newRGBToGray(unsigned char*,unsigned char*,uint32_t,uint32_t);
void RGBToGray(unsigned char*,unsigned char*,uint32_t,uint32_t);
void GrayToRGB(unsigned char*,unsigned char*,uint32_t,uint32_t);
unsigned char* reservar_memoria(uint32_t,uint32_t);

int main(int argc, char **argv) {
  if(argc<4){
    printf("Usage: %s <BMP-file> <BMP-output> <BMP-output-newgray>\n",*argv)
      ,exit(EXIT_FAILURE);
  }
  bmpInfoHeader info;
  unsigned char *imagenRGB,*imagenGray,*imagenNewGray;
  imagenRGB=abrirBMP(*(argv+1),&info);
  displayInfo(&info);
  imagenGray=reservar_memoria(info.width,info.height);
  imagenNewGray=reservar_memoria(info.width,info.height);
  RGBToGray(imagenRGB,imagenGray,info.width,info.height);
  newRGBToGray(imagenRGB,imagenNewGray,info.width,info.height);
  GrayToRGB(imagenRGB,imagenGray,info.width,info.height);
  guardarBMP(*(argv+2),&info,imagenRGB);
  GrayToRGB(imagenRGB,imagenNewGray,info.width,info.height);
  guardarBMP(*(argv+3),&info,imagenRGB);
  free(imagenGray);
  free(imagenRGB);
  free(imagenNewGray);
  return 0;
}

void newRGBToGray(unsigned char *src,unsigned char *dst,
  uint32_t width,uint32_t height){
  register int x,y;
  int indiceRGB,indiceGray;
  unsigned char nivelGris;
  for(y=0;y<height;y++){
    for(x=0;x<width;x++){
      indiceGray=(y*width)+x;
      indiceRGB=indiceGray*3;
      /* nivel de gris = (R + G + B)/3 */
      nivelGris=(*(src+indiceRGB)*30+*(src+indiceRGB+1)*59+*(src+indiceRGB+2)*11)/100;
      *(dst+indiceGray)=nivelGris;
    }
  }
}

void RGBToGray(unsigned char *src,unsigned char *dst,
  uint32_t width,uint32_t height){
  register int x,y;
  int indiceRGB,indiceGray;
  unsigned char nivelGris;
  for(y=0;y<height;y++){
    for(x=0;x<width;x++){
      indiceGray=(y*width)+x;
      indiceRGB=indiceGray*3;
      /* nivel de gris = (R + G + B)/3 */
      nivelGris=(*(src+indiceRGB)+*(src+indiceRGB+1)+*(src+indiceRGB+2))/3;
      *(dst+indiceGray)=nivelGris;
    }
  }
}

void GrayToRGB(unsigned char *dst,unsigned char *src,
  uint32_t width,uint32_t height){
  register int x,y;
  int indiceRGB,indiceGray;
  for(y=0;y<height;y++){
    for(x=0;x<width;x++){
      indiceGray=(y*width)+x;
      indiceRGB=indiceGray*3;
      *(dst+indiceRGB)=*(src+indiceGray);
      *(dst+indiceRGB+1)=*(src+indiceGray);
      *(dst+indiceRGB+2)=*(src+indiceGray);
    }
  }

}

unsigned char* reservar_memoria(uint32_t width,uint32_t height){
  unsigned char *a=(unsigned char*)malloc(sizeof(unsigned char)*(width*height));
  if(!a){
    perror("Error almacenando memoria "),exit(EXIT_FAILURE);
  }
  return a;
}
