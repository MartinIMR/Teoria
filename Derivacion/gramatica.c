#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.h"

void 
derivar_cadena(char * cadena,FILE * archivo)
{
  char * derivada;
  derivada = derivacion_inicial("B");
  derivada = agregar_derivacion(derivada,"B");
  fprintf(archivo,"Derivacion:%s\n",derivada);
  derivada = agregar_derivacion(derivada,p_b.epsilon);
  fprintf(archivo,"Derivacion:%s\n",derivada);

}

char *
agregar_derivacion(char * derivada,const char * derivacion)
{
 int tamanio_derivada;
 int tamanio_derivacion = (int)strlen(derivacion);
 printf("El tamanio de la derivacion es %d\n",tamanio_derivacion);

 if(derivada == NULL)
 {
   tamanio_derivada = 0;
 }else
 {
   tamanio_derivada = ( (int) strlen(derivada) ) - 1;
 }
 char * nueva_derivada;
 nueva_derivada  = (char *) malloc(sizeof(char) * (tamanio_derivada + tamanio_derivacion + 1));
 if(nueva_derivada == NULL)
 {
   printf("No se pudo reservar memoria para la nueva derivacion...\n");
   return NULL;
 }
 int i = 0;
 if( derivada != NULL )
 {
   while( !((derivada[i] == 'B') || (derivada[i] == 'R')) )
   {
	i++;
   }
   nueva_derivada = strncpy(nueva_derivada,derivada,i);
 }
 nueva_derivada = strcat(nueva_derivada,derivacion);
 if(derivada != NULL)
 {
 nueva_derivada = strcat(nueva_derivada,derivada+i+1); 
 free(derivada);
 }
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

