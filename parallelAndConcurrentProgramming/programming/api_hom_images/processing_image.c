#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "defs.h"

void newRGBToGray(unsigned char *src,unsigned char *dst,
  uint32_t width,uint32_t height){
  register int indiceRGB,indiceGray;
  uint32_t tope=width*height;
  unsigned char nivelGris;

  for(indiceRGB=0,indiceGray=0;indiceGray<tope;indiceRGB+=3,indiceGray++){
    /* nivel de gris = (R + G + B)/3 */
    nivelGris=(*(src+indiceRGB)*30+*(src+indiceRGB+1)*59+*(src+indiceRGB+2)*11)/100;
    *(dst+indiceGray)=nivelGris;
  }
}

void RGBToGray(unsigned char *src,unsigned char *dst,
  uint32_t width,uint32_t height){
  register int indiceRGB,indiceGray;
  uint32_t tope=width*height;
  unsigned char nivelGris;
  for(indiceRGB=0,indiceGray=0;indiceGray<tope;indiceRGB+=3,indiceGray++){
    /* nivel de gris = (R + G + B)/3 */
    nivelGris=(*(src+indiceRGB)+*(src+indiceRGB+1)+*(src+indiceRGB+2))/3;
    *(dst+indiceGray)=nivelGris;
  }

}

void GrayToRGB(unsigned char *dst,unsigned char *src,
  uint32_t width,uint32_t height){
  register int indiceRGB,indiceGray;
  uint32_t tope=width*height;
  for(indiceRGB=0,indiceGray=0;indiceGray<tope;indiceRGB+=3,indiceGray++){
    *(dst+indiceRGB)=*(src+indiceGray);
    *(dst+indiceRGB+1)=*(src+indiceGray);
    *(dst+indiceRGB+2)=*(src+indiceGray);
  }

}

void brilloImagen(unsigned char *src,uint32_t width,uint32_t height){
  register int i;
  uint32_t tope=width*height;
  int pixel;
  for(i=0;i<tope;i++){
    pixel=*(src+i)+70;
    *(src+i)=pixel>255?255:(unsigned char)pixel;
  }
}

void filtroPB(unsigned char *imagenG, unsigned char *imagenF,
  uint32_t width, uint32_t height, int init){
	register int x, y, xm, ym;
	int indicem, indicei, conv;
	int mascara[DIMASK*DIMASK] = {
		1,	4,	7,	4,	1,
		4,	20,	33,	20,	4,
		7,	33,	54,	33,	7,
		4,	20,	33,	20,	4,
		1,	4,	7,	4,	1
	};
	for(y=init;y<=height-DIMASK;y+=NUM_THREADS)
		for(x=0;x<=width-DIMASK;x++){
			indicem=0;
			conv=0;
			for(ym=0;ym<DIMASK;ym++)
				for(xm= 0;xm<DIMASK;xm++){
					indicei=(y+ym)*width+(x+xm);
					conv+=imagenG[indicei]*mascara[indicem++];
				}
			conv/=FACTOR;
			indicei=(y+1)*width+(x+1);
			imagenF[indicei]=conv;
		}
}

unsigned char* reservar_memoria(uint32_t width,uint32_t height){
  unsigned char *a=(unsigned char*)malloc(sizeof(unsigned char)*(width*height));
  if(!a){
    perror("Error almacenando memoria "),exit(EXIT_FAILURE);
  }
  return a;
}