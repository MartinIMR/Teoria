#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int
cardinalidad_lenguaje(char ** lenguaje)
{
 int i;
 for(i=0;lenguaje[i][0] != '\0';i++);
 return i;
};

char **
reservar_memoria(int filas,int columnas)
{
 char ** lenguaje;
 lenguaje = (char **) malloc(sizeof(char *) * filas);
 if(lenguaje == NULL)
 {
  printf("No se pudieron reservar las %d filas\n",filas);
  exit(-1);
 };

 for(int i=0;i<filas;i++)
 {
  lenguaje[i] = (char *) malloc(sizeof(char) * columnas);
  if(lenguaje[i] == NULL)
  {
    printf("No se pudieron reservar las %d columnas para la fila %d",columnas,i);
    exit(-1);
  };
 };
 return lenguaje;
};

char **
potenciar_lenguaje(char ** lenguaje);

char **
concatenar_lenguajes(char ** L1,char ** L2)
{
 
 char ** lenguaje_concatenacion;
 int CL1 = cardinalidad_lenguaje(L1);
 int CL2 = cardinalidad_lenguaje(L2);
 int numero_filas = (CL1 * CL2) + 1;
 lenguaje_concatenacion = (char **) malloc(sizeof(char *) * numero_filas);
 int k = 0; 
 for(int i = 0; i < CL1;i++)
 {
   int lcadena_1 = longitud_cadena(L1[i]);
   for(int j = 0; j < CL2;j++)
   {
   int lcadena_2 = longitud_cadena(L2[j]);
   int numero_columnas = lcadena_1 + lcadena_2 + 1;
   lenguaje_concatenacion[k] = (char *) malloc(sizeof(char) * numero_columnas);
   strcat(lenguaje_concatenacion[k],L1[i]);
   strcat(lenguaje_concatenacion[k],L2[j]);
   k++;
   };
 };
  printf("K vale %d\n",k);
  lenguaje_concatenacion[k] = (char *) malloc(sizeof(char)*2);
  lenguaje_concatenacion[k][0] = '\0';
  lenguaje_concatenacion[k][1] = '\0';
 return lenguaje_concatenacion;
};
 
int
longitud_cadena(char * cadena)
{
 int i;
 for(i = 0; cadena[i] != '\0';i++);
 return i;
};


char **
convertir_AL(char * alfabeto)
{
 int i=0;
  while(alfabeto[i] != '\0')
  {
   i++;
  };
 char ** lenguaje=NULL;
 i++;
 lenguaje = reservar_memoria(i,2);
 for(int j;j<i;j++)
 {
  lenguaje[j][0] = alfabeto[j];
  lenguaje[j][1] = '\0'; 
 };
 return lenguaje;
};


void
imprimir_lenguaje(char ** lenguaje)
{
 for(int i=0; lenguaje[i][0] != '\0';i++)
 {
  printf("La cadena %d del lenguaje es:%s\n",i,lenguaje[i]);
 };

};
