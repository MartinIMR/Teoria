#include <stdio.h>
#include <stdlib.h>
#include "automatalex.h"

const char reserved[32][12] =
{
"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","volatile","void","while"
};


int
main(void)
{
 FILE * archivo = NULL, * resultado = NULL;
 char direccion[100];
 printf("Introduce la direccion del archivo\n");
 scanf("%s",direccion);
 archivo = fopen(direccion,"r");
 if(archivo == NULL)
 {
  printf("El archivo a analizar no pudo ser abierto\n");
  return -1;
 }
 resultado = fopen("resultado.txt","w");
 if(resultado == NULL)
 {
  printf("El archivo de resultados no pudo ser creado\n");
  return -1;
 }
 int linea,posicion;
 posicion = linea = 1;
 /*char buffer[1025];*/
 char leida[256];
 int reservadas[32];
 for(int j=0;j<32;j++)
 {
   reservadas[j] = 0;
 }

 while(feof(archivo) == 0)
 {
  fscanf(archivo,"%s",leida);
  int resultado = quick_automata(leida,reservadas);
  if(resultado)
  {
   printf("Palabra encontrada en posicion %d\n",posicion);
  }
  posicion++;
 }
 fprintf(resultado,"En el archivo pasado se encontraron:\n");
 fprintf(resultado,"Cadena |  Numero de incidencias \n");
 for(int j = 0;j<32 ; j++)
 {
   fprintf(resultado,"%s %d\n",reserved[j],reservadas[j]);
 }
 fclose(archivo);
 fclose(resultado);
 return 0;
}
