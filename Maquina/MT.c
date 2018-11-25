#include <stdlib.h>
#include <stdio.h>
#include "MT.h"


int 
automata(char * cadena,FILE * salida)
{
 char * cinta = crear_cinta(cadena);;
 enum estados actual = q0;
 char movimiento = 'R';
 int i = 1;
 printf("Estado:%d | Cinta:%s | Direccion:%c\n",actual,cinta,movimiento);
 fprintf(salida,"%d %s %d\n",actual,cinta,i);
 
 while(cinta[i] != '\0')
 {
   switch(actual)
   {
    case q0:
	if(cinta[i] == '0')
	{
		actual = q1;
		cinta[i] = 'X';
	        movimiento = 'R';
	}else if(cinta[i] == 'Y')
	{
		actual = q3;
		cinta[i] = 'Y';
	        movimiento = 'R';
	}else
	{
	  return actual;
	}
    break;
    case q1:
	if(cinta[i] == '0')
	{
		actual = q1;
		cinta[i] = '0';
		movimiento = 'R';
	}else if(cinta[i] == '1')
	{
		actual = q2;
		cinta[i] = 'Y';
		movimiento = 'L';

	}else if(cinta[i] == 'Y')
	{
		actual = q1;
		cinta[i] = 'Y';
		movimiento = 'R';
	}else 
	{
		return actual;
	}
    break;
    case q2:
	if(cinta[i] == '0')
	{
		actual = q2;
		cinta[i] = '0';
		movimiento = 'L';
	}else if(cinta[i] == 'Y')
	{
		actual = q2;
		cinta[i] = 'Y';
		movimiento = 'L';
	}else if(cinta[i] == 'X')
	{
		actual = q0;
		cinta[i] = 'X';
		movimiento = 'R';
	}else 
	{
		return actual;
	}
    break;
    case q3:
	if(cinta[i] == 'Y')
	{
		actual = q3;
		cinta[i] = 'Y';
		movimiento = 'R';
	}else if(cinta[i] == 'B')
	{
		actual = q4;
		cinta[i] = 'B';
		movimiento = 'R';
	}else 
	{
		return actual;
	}
    break;
    case q4:
	return actual;
    break;
   }

   if(movimiento == 'R')
   {
	i++;
   }else
   {
	i--;
   }
   printf("Estado:%d | Cinta:%s | Direccion:%c\n",actual,cinta,movimiento);
   fprintf(salida,"%d %s %d\n",actual,cinta,i);
   
 }
 free(cinta);
 return actual;
}


char *
crear_cinta(char * cadena)
{
  int tamanio = 0;
  while(cadena[tamanio] != '\0')
  {
    tamanio++;
  }
  printf("La cadena recibida es %s y tiene tamanio %d\n",cadena,tamanio);
  char * cinta = (char *) malloc(sizeof(char)*(tamanio+3));
  if(cinta == NULL)
  { 
    printf("No se pudo crear la cinta...");
    exit(-1);
    return NULL;
  }
  int i = 0;
  cinta[i]='B';
  for(i = 0;i<tamanio;i++)
  {
   cinta[i+1] = cadena[i];
  }
  i++;
  cinta[i]='B';
  i++;
  cinta[i]='\0';
 return cinta;
}

