#include <stdio.h>
#include <stdlib.h>
#define PAR -2
#define VACIO -47
#define LLENO -49

int Colocar_Reina(char [][8], int, char, int, int);
void Imprimir_Tablero(char [][8]);
void Imprimir_Tablero2(char [][8]);
void Limpiar_Tablero(char [][8]);
void Poner_Reina(char [][8], int, int, char);
void Marcar_Rango(char [][8], int, int, char);
void Imprimir_Posicion_Reina(char [][8]);
void Limpiar_Rango(char [][8], int, int, char);
void Rango_Centro_Norte(char [][8], int, int, char);
void Rango_Centro_NE(char [][8], int, int, char);
void Rango_Centro_Este(char [][8], int, int, char);
void Rango_Centro_SE(char [][8], int, int, char);
void Rango_Centro_Sur(char [][8], int, int, char);
void Rango_Centro_SO(char [][8], int, int, char);
void Rango_Centro_Oeste(char [][8], int, int, char);
void Rango_Centro_NO(char [][8], int, int, char);
int Verificar_Casilla(char [][8], int, int);
int Verificar_Casilla_Par(int, int);

int main(int argc, char *argv[]){
  char tablero[8][8];
  char reina= 'A';
  int col=0, nR=0, nsol=0, sol=0;

  Limpiar_Tablero(tablero);
  nsol= Colocar_Reina(tablero, col, reina, nR, nsol);
  printf("\n\nEs todo... Solo existen %d soluciones al problema de las 8 reinas", nsol);

  return 0;
}

int Colocar_Reina(char tablero [][8], int col, char reina, int nR, int nsol){
  int j=0, swloc=0;
  char queen= 'A';
  system("cls");
  printf("\n 8 REINAS: ");
  Imprimir_Tablero(tablero);
  if(nR==8){
    nsol++;
    printf("\nSolucion: %d", nsol);
    Imprimir_Posicion_Reina(tablero);
    getchar();
    return(nsol);
  }

  for(j=0; j<8; j++){
    if (tablero[nR][j]==' '){
      tablero[nR][j]= reina;
      queen= reina-16;
      printf("\ncasilla: %d %d, reina: %c", nR, j, tablero[nR][j]);
      Marcar_Rango(tablero, nR, j, queen);
      queen= reina+1;
      //getchar();
      nsol= Colocar_Reina(tablero, j+1, queen, nR+1, nsol);
      queen= reina-16;
      Limpiar_Rango(tablero, nR, j, queen);
    }
  }
  return(nsol);
}

void Limpiar_Tablero(char tablero[][8]){
  int i=0, j=0;
  for (i=0; i<8; i++)
    for (j=0; j<8; j++)
      tablero[i][j]=' ';
}

void Imprimir_Tablero(char tablero[][8]){
  int i=0, j=0, swpar=0;
  printf("\n\n");
  for(i=0; i<8; i++)
    for(j=0; j<8; j++){
      if(((tablero[i][j]>='1') && (tablero[i][j]<='8')) || (tablero[i][j]==' ')){
	   /*swpar= Verificar_Casilla_Par(i, j);
	   if (swpar==PAR)
	     printf("f");
	   else
	     printf(" ");*/
	      printf(". ");
      }
      if((tablero[i][j]>='A') && (tablero[i][j]<='H'))
      printf("x ");
      if(j==7)
      printf("\n");
    }
}

void Imprimir_Posicion_Reina(char tablero[][8]){
  int i=0, j=0;
  for(i=0; i<8; i++)
    for(j=0; j<8; j++){
      if((tablero[i][j]>='A') && (tablero[i][j]<='H'))
        printf("\nColocar reina en la fila %d columna %d", i, j);
      }
}

void Poner_Reina(char tablero[][8], int i, int j, char reina){
  tablero[i][j]= reina;
}

void Marcar_Rango(char tablero[][8], int fil, int col, char marca){
  int i=0, j=0;
  i= fil;
  j= col;
  if(i!=0)
    Rango_Centro_Norte(tablero, i, j, marca);
  if((i!=0) && (j!=7))
    Rango_Centro_NE(tablero, i, j, marca);
  if(j!=7)
    Rango_Centro_Este(tablero, i, j, marca);
  if((i!=7) && (j!=7))
    Rango_Centro_SE(tablero, i, j, marca);
  if(i!=7)
    Rango_Centro_Sur(tablero, i, j, marca);
  if((i!=7) && (j!=0))
    Rango_Centro_SO(tablero, i, j, marca);
  if(j!=0)
    Rango_Centro_Oeste(tablero, i, j, marca);
  if((i!=0) && (j!=0))
    Rango_Centro_NO(tablero, i, j, marca);
}

void Rango_Centro_Norte(char tablero[][8], int fil, int col, char marca){
  int i=fil, j=col;
  for(i=fil-1; i>=0; i--)
    if (tablero[i][j]==' ')
      tablero[i][j]= marca;
}

void Rango_Centro_Sur(char tablero[][8], int fil, int col, char marca){
  int i=fil, j=col;
  for (i=fil+1; i<=7; i++)
    if (tablero[i][j]==' ')
      tablero[i][j]= marca;
}

void Rango_Centro_Este(char tablero[][8], int fil, int col, char marca){
  int i=fil, j=col;
  for(j=col+1; j<=7; j++)
    if(tablero[i][j]==' ')
      tablero[i][j]= marca;
}

void Rango_Centro_Oeste(char tablero[][8], int fil, int col, char marca){
  int i=fil, j=col;
  for(j=col-1; j>=0; j--)
    if(tablero[i][j]==' ')
      tablero[i][j]= marca;
}

void Rango_Centro_NE(char tablero[][8], int i, int j, char marca){
  while(1){
    i--;
    j++;
    if(tablero[i][j]==' ')
      tablero[i][j]= marca;
    if((i==0)||(j==7))
      break;
  }
}

void Rango_Centro_SE(char tablero[][8], int i, int j, char marca){
  while(1){
    i++;
    j++;
    if(tablero[i][j]==' ')
      tablero[i][j]= marca;
    if((i==7) || (j==7))
      break;
  }
}

void Rango_Centro_SO(char tablero[][8], int i, int j, char marca){
  while(1){
    i++;
    j--;
    if(tablero[i][j]==' ')
      tablero[i][j]= marca;
    if((i==7) || (j==0))
      break;
  }
}

void Rango_Centro_NO(char tablero[][8], int i, int j, char marca){
  while(1){
    i--;
    j--;
    if(tablero[i][j]==' ')
      tablero[i][j]= marca;
    if((i==0) || (j==0))
      break;
  }
}

int Verificar_Casilla(char tablero[][8], int fil, int col){
  if(tablero[fil][col]==' ')
    return(VACIO);
  return(LLENO);
}

void Limpiar_Rango(char tablero[][8], int fil, int col, char marca){
  int i=0, j=0;
  tablero[fil][col]=' ';
  for(i=0;i<8;i++)
    for (j=0;j<8;j++){
      if(tablero[i][j]==marca)
        tablero[i][j]=' ';
    }
}

int Verificar_Casilla_Par(int fil, int col){
  if((fil+col)%2==0)
    return(PAR);
}

void Imprimir_Tablero2(char tablero[][8]){
  int i=0, j=0;
  printf("\n");
  for(i=0; i<8; i++)
    for(j=0; j<8; j++){
      printf("%c", tablero[i][j]);
      if(j==7)
      printf("\n");
    }
}
