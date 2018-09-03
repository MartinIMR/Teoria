#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca.h"
#include "automatasp.h"


void 
filtrar(FILE * archivo,char ** datos,int cantidad)
{
 int i;
 for(i = 0; i < cantidad; i++)
 {
   int termino = automata_impares(datos[i]);
   if( termino == q1 || termino == q2 || termino == q3)
   {
    fprintf(archivo,"%s,",datos[i]);
   }
 }
  fprintf(archivo,"\b\n"); 
}

int
automata_impares(char * cadena)
{
 enum E_AF_IMPARES estado;
 int i = 0;
 estado = q0;
 while(cadena[i] != '\0')
 {
   switch(estado)
   {
     case q0:
	if(cadena[i] == '1')
	{
	 estado = q1; 
	}else
	{
	 estado = q2;
	}
     break;
     case q1: 
	if(cadena[i] == '1')
	{
	 estado = q0; 
	}else
	{
	 estado = q3;
	}
     break;
     case q2:
	if(cadena[i] == '1')
	{
	 estado = q3; 
	}else
	{
	 estado = q0;
	}
     break;
     case q3:
	if(cadena[i] == '1')
	{
	 estado = q2; 
	}else
	{
	 estado = q1;
	}
     break;
   }
  i++;
 }
 return estado;
}


char ** 
crear_datos(FILE * archivo,int n,int m)
{
 char ** datos = NULL;
 datos = (char **) malloc(sizeof(char *) * n);
 if(datos == NULL)
 {
  printf("No se pudo reservar espacio para las cadenas\n");
  return NULL;
 }
 int i; 
  for(i = 0; i < n; i++)
  {
    *(datos + i) = (char *) malloc(sizeof(char) * (m+1));
    if(datos[i] == NULL)
    {
      printf("No se pudo reservar espacio para la cadena %d\n",i+1);
    }else
    {
      datos[i][m] = '\0';
      int j;
      for(j = 0; j < m;j++)
      {
	datos[i][j] = (aleatorio(1) + '0');
      }
      fprintf(archivo,"%s,",datos[i]);
    }
  }
  fprintf(archivo,"\b\n");
 return datos; 
}

