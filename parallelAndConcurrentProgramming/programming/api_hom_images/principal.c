#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include "imagen.h"
#include "processing_image.h"
#include "threads.h"
#include "defs.h"
#include "flag_parser.h"

/*
 * @author Adrian Gonzalez Pardo
 **/

bmpInfoHeader info;
unsigned char *imgGray,*imgFiltrada;
int type;

char *reserva_memoria_char();
void call_pthreads(bmpInfoHeader,int);

typedef struct timeval timer;

int main(int argc,char **argv){
  if(argc<2){
    printf("Error\nUsage: %s <Input_bmp_file> <Flag solution>",
      *argv),exit(EXIT_FAILURE);
  }
  type=get_processing_type(argc,argv);
  if(type==0||type==2){
    printf("Solucion con hilos %s\n",(type==0)?("alternada"):("bloques"));
  }else if(type==-1){
    exit(1);
  }else{
    printf("Solucion concurrente\n");
  }
  char *prefix[]={"outputs/salida_threads_filtro_newgray_",
    "outputs/salida_threads_newgray_","outputs/salida_threads_gray_",
    "outputs/salida_threads_filtro_gray_",
    "outputs/salida_threads_brillo_newgraw_",
    "outputs/salida_threads_brillo_gray_",
    "outputs/salida_threads_sobel_newgray_",
    "outputs/salida_threads_sobel_gray_"},
  *prefix1[]={"outputs/salida_concurrente_filtro_newgray_",
    "outputs/salida_concurrente_newgray_","outputs/salida_concurrente_gray_",
    "outputs/salida_concurrente_filtro_gray_",
    "outputs/salida_concurrente_brillo_newgraw_",
    "outputs/salida_concurrente_brillo_gray_",
    "outputs/salida_concurrente_sobel_newgray_",
    "outputs/salida_concurrente_sobel_gray_"};
  register int i=0;
  unsigned char *imgRGB,*imgGray_2;
  char *src=*(argv+1),*dst;

  timer start,end,ip,ep;
  long total=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0;
  gettimeofday(&start,NULL);
  imgRGB=abrirBMP(src,&info);
  imgGray=reservar_memoria(info.width,info.height);
  imgGray_2=reservar_memoria(info.width,info.height);
  imgFiltrada=reservar_memoria(info.width,info.height);
  dst=reserva_memoria_char();

  memset(dst,0,1000);
  memset(imgFiltrada,255,info.width*info.height);
  memset(imgGray_2,0,info.width*info.height);

  int t=strlen(src),p=0;
  for(i=0;i<t;i++){
    if(*(src+i)=='/'){
      p=i+1;
    }
  }

  /* Crea el primer nombre de salida para el newgray */
  memcpy(dst,(type==0||type==2)?(*(prefix+1)):(*(prefix1+1)),
    strlen((type==0||type==2)?(*(prefix+1)):(*(prefix1+1))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+1)):(*(prefix1+1))),src+p,strlen(src)-p);
  displayInfo(&info);

  /* Apartado para guardar en newgray */
  gettimeofday(&ip,NULL);
  newRGBToGray(imgRGB,imgGray,info.width,info.height);
  gettimeofday(&ep,NULL);
  p1=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;

  gettimeofday(&ip,NULL);
  RGBToGray(imgRGB,imgGray_2,info.width,info.height);
  gettimeofday(&ep,NULL);
  p4=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;

  GrayToRGB(imgRGB,imgGray,info.width,info.height);
  guardarBMP(dst,&info,imgRGB);

  /* Llama a hilos para el procesamiento paralelo de filtro pb newgray */
  gettimeofday(&ip,NULL);
  if(type==0||type==2){
    call_pthreads(info,0);
  }else{
    for(i=0;i<NUM_THREADS;i++){
      filtroPB(imgGray,imgFiltrada,info.width,info.height,i);
    }
  }
  gettimeofday(&ep,NULL);
  GrayToRGB(imgRGB,imgFiltrada,info.width,info.height);
  p2=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;

  /* Apartado para crear el nombre del filtro pasa bajas de newgray */
  memset(dst,0,1000);
  memcpy(dst,(type==0||type==2)?(*(prefix)):(*(prefix1)),
    strlen((type==0||type==2)?(*(prefix)):(*(prefix1))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix)):(*(prefix1))),
    src+p,strlen(src)-p);

  guardarBMP(dst,&info,imgRGB);

  /* Apartado para filtro sobel con newgray */
  memset(imgFiltrada,255,info.width*info.height);
  gettimeofday(&ip,NULL);
  if(type==0||type==2){
    call_pthreads(info,1);
  }else{
    for(i=0;i<NUM_THREADS;i++){
      sobel(imgGray,imgFiltrada,info.width,info.height,i);
    }
  }
  gettimeofday(&ep,NULL);
  GrayToRGB(imgRGB,imgFiltrada,info.width,info.height);
  p7=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;
  /* Guarda */
  memset(dst,0,1000);
  memcpy(dst,(type==0||type==2)?(*(prefix+6)):(*(prefix1+6)),
    strlen((type==0||type==2)?(*(prefix+6)):(*(prefix1+6))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+6)):(*(prefix1+6))),
    src+p,strlen(src)-p);
  guardarBMP(dst,&info,imgRGB);

  /* Apartado para guardar newgray con brillo */
  gettimeofday(&ip,NULL);
  brilloImagen(imgGray,info.width,info.height);
  gettimeofday(&ep,NULL);
  GrayToRGB(imgRGB,imgGray,info.width,info.height);
  p3=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;

  /* Apartado para crear el nombre newgray con brillo */
  memset(dst,0,1000);
  memcpy(dst,(type==0||type==2)?(*(prefix+4)):(*(prefix1+4)),
    strlen((type==0||type==2)?(*(prefix+4)):(*(prefix1+4))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+4)):(*(prefix1+4))),
    src+p,strlen(src)-p);
  guardarBMP(dst,&info,imgRGB);


  /* Apartado para guardar gray */
  memset(imgFiltrada,255,info.width*info.height);
  memset(imgGray,0,info.height*info.width);
  memset(dst,0,1000);
  memcpy(imgGray,imgGray_2,info.width*info.height);

  /* Apartado para crear el nombre gray */
  memcpy(dst,(type==0||type==2)?(*(prefix+2)):(*(prefix1+2)),
    strlen((type==0||type==2)?(*(prefix+2)):(*(prefix1+2))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+2)):(*(prefix1+2))),
    src+p,strlen(src)-p);

  GrayToRGB(imgRGB,imgGray,info.width,info.height);
  guardarBMP(dst,&info,imgRGB);

  /* Apartado para procesamiento paralelo de filtro pb gray */
  gettimeofday(&ip,NULL);
  if(type==0||type==2){
    call_pthreads(info,0);
  }else{
    for(i=0;i<NUM_THREADS;i++){
      filtroPB(imgGray,imgFiltrada,info.width,info.height,i);
    }
  }
  gettimeofday(&ep,NULL);
  p5=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;
  GrayToRGB(imgRGB,imgFiltrada,info.width,info.height);

  /* Apartado para crear el nombre del filtro pasa bajas gray */
  memset(dst,0,1000);
  memcpy(dst,(type==0||type==2)?(*(prefix+3)):(*(prefix1+3)),
    strlen((type==0||type==2)?(*(prefix+3)):(*(prefix1+3))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+3)):(*(prefix1+3))),
    src+p,strlen(src)-p);
  guardarBMP(dst,&info,imgRGB);

  /* Apartado para filtro sobel con newgray */
  memset(imgFiltrada,255,info.width*info.height);
  gettimeofday(&ip,NULL);
  if(type==0||type==2){
    call_pthreads(info,1);
  }else{
    for(i=0;i<NUM_THREADS;i++){
      sobel(imgGray,imgFiltrada,info.width,info.height,i);
    }
  }
  gettimeofday(&ep,NULL);
  GrayToRGB(imgRGB,imgFiltrada,info.width,info.height);
  p8=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;
  /* Guarda */
  memset(dst,0,1000);
  memcpy(dst,(type==0||type==2)?(*(prefix+7)):(*(prefix1+7)),
    strlen((type==0||type==2)?(*(prefix+7)):(*(prefix1+7))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+7)):(*(prefix1+7))),
    src+p,strlen(src)-p);
  guardarBMP(dst,&info,imgRGB);

  /* Apartado para guardar gray con brillo */
  gettimeofday(&ip,NULL);
  brilloImagen(imgGray,info.width,info.height);
  gettimeofday(&ep,NULL);
  GrayToRGB(imgRGB,imgGray,info.width,info.height);
  p6=((ep.tv_sec-ip.tv_sec)*1000 + (ep.tv_usec-ip.tv_usec)/1000)+0.5;

  /* Apartado para crear el nombre gray con brillo */
  memset(dst,0,1000);
  memcpy(dst,(type==0||type==2)?(*(prefix+5)):(*(prefix1+5)),
    strlen((type==0||type==2)?(*(prefix+5)):(*(prefix1+5))));
  memcpy(dst+strlen((type==0||type==2)?(*(prefix+5)):(*(prefix1+5))),
    src+p,strlen(src)-p);
  guardarBMP(dst,&info,imgRGB);
  free(imgRGB);
  free(imgGray_2);
  free(imgFiltrada);
  free(imgGray);
  free(dst);
  gettimeofday(&end,NULL);
  total=((end.tv_sec-start.tv_sec)*1000 + (end.tv_usec-start.tv_usec)/1000)+0.5;

  printf("Tiempo de procesamiento de cada proceso concurrente:\n"
    "T1 Crear bmp new gray %ld ms\n"
    "T2 Procesamiento paralelo o concurrente new gray PB %ld ms\n"
    "T3 Procesamiento paralelo o concurrente new gray filtro sobel %ld ms\n"
    "T4 Crear bmp con brillo de newgray %ld ms\n"
    "T5 Crear bmp gray %ld ms\n"
    "T6 Procesamiento paralelo o concurrente gray PB %ld ms\n"
    "T7 Procesamiento paralelo o concurrente gray filtro sobel %ld ms\n"
    "T8 Crear bmp con brillo de gray %ld ms\n"
    "Total de tiempo en ejecucion %ld ms\n",p1,p2,p7,p3,p4,p5,p8,p6,total);
  return 0;
}

char *reserva_memoria_char(){
  char *a=(char*)malloc(sizeof(char)*1000);
  if(!a){
    perror("Error allocating memory"),exit(EXIT_FAILURE);
  }
  return a;
}

void call_pthreads(bmpInfoHeader info,int type_fil){
  register int i;
  pthread_t *id=(pthread_t*)malloc(sizeof(pthread_t)*NUM_THREADS);
  int *id_thread=(int*)malloc(sizeof(int)*NUM_THREADS);
  if(!id){
    perror("Error allocating memory threads"),exit(EXIT_FAILURE);
  }
  if(!id_thread){
    perror("Error allocating memory int"),exit(EXIT_FAILURE);
  }
  for(i=0;i<NUM_THREADS;i++){
    *(id_thread+i)=i;

    pthread_create(&*(id+i),NULL,(type_fil==0)?processing_pb:processing_sobel
      ,(void*)&*(id_thread+i));
  }
  for(i=0;i<NUM_THREADS;i++){
    pthread_join(*(id+i),NULL);
  }
  free(id);
  free(id_thread);
}
