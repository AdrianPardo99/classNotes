#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Se redifine el nombre del struct como apuntador de nombre complejo
 * Mientras que por otro lado se define tComplejo para conocer el tamanio en
 * Memoria del struct*/
typedef struct complejo{
  /*Definicion x + iy*/
  float real,imag;

  /*Definicion r * e^ i(ang)*/
  float magnitud, fase;
}*complejo, tComplejo;

/*Firmas de las funciones en codigo*/
complejo crearNComplejoCar(float,float);
complejo crearNComplejoPol(float,float);
void destruirComplejo(complejo);
void sumarComplejo(complejo,complejo,complejo);
void mulComplejo(complejo,complejo,complejo);
void desplegarNComplejo(complejo);
void desplegarPolarComplejo(complejo);
complejo *crearArrayComplejo(int);
void destruirArrComplejo(complejo*,int);
void initComplejoCar(complejo,float,float);
void initComplejoPol(complejo,float,float);
void calcularRaicesUn(complejo*,complejo,int);

int main(int argc, char *argv[]) {
  complejo zA=NULL, zB=NULL, zC=NULL,*arr;
  zA=crearNComplejoCar(2.0,3.0); /* z = 2 + 3i*/
  zB=crearNComplejoPol(5.0,M_PI/3); /* z = 5*e^(PI/3)*/
  zC=(complejo)malloc(sizeof(tComplejo));
  int N=10;
  printf("Suma zA*zB\n");
  sumarComplejo(zC,zA,zB);
  desplegarNComplejo(zC);
  desplegarPolarComplejo(zC);
  printf("zA\n");
  desplegarNComplejo(zA);
  desplegarPolarComplejo(zA);
  printf("zB\n");
  desplegarNComplejo(zB);
  desplegarPolarComplejo(zB);
  printf("Multiplicacion zA*zB\n");
  mulComplejo(zC,zA,zB);
  desplegarNComplejo(zC);
  desplegarPolarComplejo(zC);
  printf("zA\n");
  desplegarNComplejo(zA);
  desplegarPolarComplejo(zA);
  printf("zB\n");
  desplegarNComplejo(zB);
  desplegarPolarComplejo(zB);
  printf("Raices complejas\n");
  arr=crearArrayComplejo(N);
  calcularRaicesUn(arr,crearNComplejoCar(1.0,0.0),N);
  destruirArrComplejo(arr,N);
  destruirComplejo(zA);
  destruirComplejo(zB);
  destruirComplejo(zC);

  return 0;
}

/*Escritura de cada una de las funciones y operaciones de la estructura del numero complejo*/
complejo crearNComplejoCar(float x,float y){
  complejo z=NULL;
  z=(complejo)malloc(sizeof(tComplejo));
  if(z==NULL){
    printf("Error al asignar memoria en crearNComplejoCar\n");
    return NULL;
  }
  z->real=x;
  z->imag=y;
  z->magnitud=sqrtf((x*x)+(y*y));
  z->fase=atan2f(y,x);
  return z;
}

complejo crearNComplejoPol(float r,float ang){
  complejo z=NULL;
  z=(complejo)malloc(sizeof(tComplejo));
  if(z==NULL){
    printf("Error al asignar memoria en crearNComplejoPol\n");
    return NULL;
  }
  z->magnitud=r;
  z->fase=ang;
  z->real= r*cosf(ang);
  z->imag=r*sinf(ang);
  return z;
}

void destruirComplejo(complejo c){
  if(c!=NULL){
    free(c);
  }
}

void sumarComplejo(complejo cC,complejo cA,complejo cB){
  if(cC==NULL || cA==NULL || cB==NULL){
    printf("No se puede realizar la operacion especificada\n");
    return;
  }
  cC->real = cA->real + cB->real;
  cC->imag = cA->imag + cB-> imag;
  cC->magnitud = sqrtf(pow(cC->real,2.0)+pow(cC->imag,2.0));
  cC->fase = atan2f(cC->imag,cC->real);
}

void mulComplejo(complejo cC,complejo cA,complejo cB){
  if(cC==NULL || cA==NULL || cB==NULL){
    printf("No se puede realizar la operacion especificada\n");
    return;
  }
  cC->magnitud=cA->magnitud*cB->magnitud;
  cC->fase=cA->fase+cB->fase;
  cC->real= cC->magnitud * cosf(cC->fase);
  cC->imag= cC->magnitud * sinf(cC->fase);
}

void desplegarNComplejo(complejo z){
  if(z==NULL){
    return;
  }
  printf("%f %s%fi\t",z->real,(z->imag<0)?(""):("+"),z->imag);
}

void desplegarPolarComplejo(complejo z){
  if(z==NULL){
    return;
  }
  printf("%f e^(i%f)\n",z->magnitud,z->fase);
}

complejo *crearArrayComplejo(int N){
  complejo *arr=NULL;
  int k;
  arr=(complejo*)malloc(sizeof(complejo)*N);
  if(arr==NULL){
    printf("Error al asignar memoria en array\n");
    return NULL;
  }
  for(k=0;k<N;k++){
    arr[k]=crearNComplejoCar(0.0,0.0);
  }
  return arr;
}

void destruirArrComplejo(complejo *arr,int N){
  int k;
  if(arr!=NULL){
    for(k=0;k<N;k++){
      destruirComplejo(arr[k]);
    }
    free(arr);
  }
}

void calcularRaicesUn(complejo *root,complejo z,int N){
  int k=0;
  float fase,rebanada;
  if(root==NULL||z==NULL){
    printf("Error en calcularRaicesUn\n");
    return;
  }
  rebanada= (2.0*M_PI+(z->fase))/N;
  for(k=0;k<N;k++){
    if(root[k]==NULL){
      printf("Error al calcularRaicesUn\n");
      return;
    }
    fase=rebanada*k;
    initComplejoPol(root[k],z->magnitud,fase);
    desplegarNComplejo(root[k]);
    desplegarPolarComplejo(root[k]);
  }
}

void initComplejoCar(complejo z,float x,float y){
  if(z==NULL){
    printf("Error en initComplejoCar\n");
    return;
  }
  z->real=x;
  z->imag=y;
  z->magnitud=sqrtf((x*x)+(y*y));
  z->fase=atan2f(y,x);
}

void initComplejoPol(complejo z,float r,float ang){
  if(z==NULL){
    printf("Error en initComplejoCar\n");
    return;
  }
  z->magnitud=r;
  z->fase=ang;
  z->real= r*cosf(ang);
  z->imag=r*sinf(ang);
}
