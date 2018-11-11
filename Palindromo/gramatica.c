#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gramatica.h"
 
struct PP p = {"","0","1","0P0","1P1"};

void 
derivar_cadena(int longitud,FILE * archivo)
{
  char * derivada;
  fprintf(archivo,"Longitud de la cadena:%d\nGeneracion:\n",longitud);
  if(!longitud) 
  {
   fprintf(archivo,"e\tDerivacion inicial\n");
   return;
  }

  if(aleatorio(1))
  {
   derivada = derivacion_inicial(p.uno_p_uno);
  }else
  {
   derivada = derivacion_inicial(p.cero_p_cero);
  }
  fprintf(archivo,"%s\t  Derivacion inicial\n",derivada);
  int repeticiones = (int)(longitud/2);
  for(int i=0;i < (repeticiones-1);i++)
  {
    if(aleatorio(1))
    {
      derivada = agregar_derivacion(derivada,p.uno_p_uno);
      fprintf(archivo,"%s\t  Regla 5\n",derivada);
    }else
    {
      derivada = agregar_derivacion(derivada,p.cero_p_cero);
      fprintf(archivo,"%s\t Regla 4\n",derivada);
    }
  }

  if(longitud%2)
  {
    if(aleatorio(1))
    {
      derivada = agregar_derivacion(derivada,p.uno);
      fprintf(archivo,"%s\t Regla 3\n",derivada);
    }else
    {
      derivada = agregar_derivacion(derivada,p.cero);
      fprintf(archivo,"%s\t Regla 2\n",derivada);
    }
  }else
  {
    derivada = agregar_derivacion(derivada,p.epsilon);
    fprintf(archivo,"%s\t Regla 1\n",derivada);
  }
 
  free(derivada);

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
 /* Contar cuantos caracteres hay antes de P*/
 while(derivada[i] != 'P')
 {
    i++;
 }
 /* Copiar los caracteres antes de P*/
 nueva_derivada = strncpy(nueva_derivada,derivada,i);
 nueva_derivada[i] = '\0';
 /* Concatenar la produccion */
 nueva_derivada = strcat(nueva_derivada,derivacion);
 /* Concatenar los caracteres despues de P*/
 nueva_derivada = strcat(nueva_derivada,derivada+i+1); 
 free(derivada);
 return nueva_derivada; 
}

char *
derivacion_inicial(const char * inicial)
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
 cadena[tamanio]='\0';
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

void 
imprimir_reglas(FILE * archivo)
{
 fprintf(archivo,"Las reglas de produccion son:\n");
 fprintf(archivo,"Regla 1: P -> e\n");
 fprintf(archivo,"Regla 2: P -> 0\n");
 fprintf(archivo,"Regla 3: P -> 1\n");
 fprintf(archivo,"Regla 4: P -> 0P0\n");
 fprintf(archivo,"Regla 5: P -> 1P1\n");
 fprintf(archivo," ------------------\n");
}

