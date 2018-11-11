#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gramatica.h"
 
struct PB b = {"(RB",""};
struct PR r = {")","(RR"};


void 
derivar_cadena(char * cadena,FILE * archivo)
{
  char * derivada;
  enum variables mas_izquierda = B;
  derivada = derivacion_inicial("B");
  fprintf(archivo,"%s\t  %s\t  Derivacion inicial\n",cadena,derivada);
  int i = 0;
  while(cadena[i] != '\0')
  {
    switch(cadena[i])
    {
	case '(':
	if(mas_izquierda == B)
	{
	   derivada = agregar_derivacion(derivada,b.prb);
	   fprintf(archivo,"%s\t  %s\t  Regla %d\n",cadena+i+1,derivada,1);
	   mas_izquierda = R;
	}else if(mas_izquierda == R)
	{
	   derivada = agregar_derivacion(derivada,r.prr);
	   fprintf(archivo,"%s\t  %s\t  Regla %d\n",cadena+i+1,derivada,4);
	   mas_izquierda = R;
	}else
	{
	 return;
	}
	break;
	case ')':
	if(mas_izquierda == R)
	{
	  derivada = agregar_derivacion(derivada,r.p);
	  if(cadena[i+1] == '\0')
	  {
	  fprintf(archivo,"%s\t  %s\t  Regla %d\n","e",derivada,3);
	  }else
	  {
	  fprintf(archivo,"%s\t  %s\t  Regla %d\n",cadena+i+1,derivada,3);
	  }
	  mas_izquierda = siguiente_variable(derivada,i);
	}else
	{
	 return;
	}
	break;
	default:
	return;
	break;
    }
   i++;
  }

  if(mas_izquierda == B)
  {
    derivada = agregar_derivacion(derivada,b.epsilon);
    fprintf(archivo,"%s\t  %s\t  Regla %d\n","e",derivada,2);
  }
  

}


int 
siguiente_variable(char * derivada,int posicion)
{
 if(derivada[posicion+1] == 'B')
 {
   return B;
 }else if(derivada[posicion+1] == 'R')
 {
   return R;
 }
 return B;
}

char *
agregar_derivacion(char * derivada,const char * derivacion)
{
 char * nueva_derivada;
 int tamanio_derivacion,tamanio_derivada;
 /* Tamanio de la produccion que se agregara */
 tamanio_derivacion = (int)strlen(derivacion);
 /* Tamanio de la cadena derivada hasta el momento */
 tamanio_derivada = ((int) strlen(derivada)) - 1;
 nueva_derivada  = (char *) malloc(sizeof(char) * (tamanio_derivada + tamanio_derivacion + 1));
 if(nueva_derivada == NULL)
 {
   printf("No se pudo reservar memoria para la nueva derivacion...\n");
   return NULL;
 }
 int i = 0;
 /* Contar cuantos caracteres hay antes de una B o R */
 while( !((derivada[i] == 'B') || (derivada[i] == 'R')) )
 {
    i++;
 }
 /* Copiar los caracteres antes de B o R */
 nueva_derivada = strncpy(nueva_derivada,derivada,i);
 nueva_derivada[i] = '\0';
 /* Concatenar la produccion */
 nueva_derivada = strcat(nueva_derivada,derivacion);
 /* Concatenar los caracteres despues de B o R */
 nueva_derivada = strcat(nueva_derivada,derivada+i+1); 
 free(derivada);
 return nueva_derivada; 
}

char *
derivacion_inicial(char * inicial)
{
 char * cadena;
 int tamanio = (int)strlen(inicial);
 cadena = (char *)malloc(sizeof(char)*(tamanio+1));
 if(cadena == NULL)
 {
  printf("No se pudo reservar memoria para la derivacion inicial\n");
  return NULL;
 }
 cadena = strcpy(cadena,inicial);
 return cadena;
}

int
aleatorio(int maximo)
{
 static int i = 0;
 if(!i)
 {
   time_t semilla;
   srand((unsigned)time(0));
   i++;
 }
 return (rand() % (maximo+1));
}

char *
generar_cadena(int longitud)
{
 char * cadena = NULL;
 if(longitud == 0 )
 {
  cadena = (char *) malloc(sizeof(char));
  if(cadena == NULL)
  {
   printf("La cadena no se pudo generar \n");
  }
  cadena[0] = '\0';
  return cadena;
 }
 cadena = (char *) malloc(sizeof(char) * (longitud+1));
 cadena[longitud] = '\0';
 for(int i=0; i < longitud;i++ )
 {
   if(aleatorio(1))
   {
     cadena[i] = '(';
   }else
   {
     cadena[i] = ')';
   }
 }

 return cadena;
}



