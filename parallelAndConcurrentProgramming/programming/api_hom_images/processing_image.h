#ifndef PROCESSING_IMAGE_H
#define PROCESSING_IMAGE_H

void newRGBToGray(unsigned char*,unsigned char*,uint32_t,uint32_t);
void RGBToGray(unsigned char*,unsigned char*,uint32_t,uint32_t);
void GrayToRGB(unsigned char*,unsigned char*,uint32_t,uint32_t);
void brilloImagen(unsigned char*,uint32_t,uint32_t);
void filtroPB(unsigned char*, unsigned char*, uint32_t, uint32_t, int);
unsigned char* reservar_memoria(uint32_t,uint32_t);

#endif
