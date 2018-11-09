#include <stdio.h>
#include <stdlib.h>
#include "gramatica.h"


int
main(void)
{
 char cadena[100];
 printf("Introduce la cadena");
 scanf("%s",cadena); 
 FILE * archivo; 
 archivo = fopen("deri.txt","w");
 if(archivo == NULL)
 {
  printf("No se pudo abrir el archivo...\n");
  return -1;
 }
 derivar_cadena(cadena,archivo);
 return 0;
}
