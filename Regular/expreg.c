#include <stdio.h>
#include <stdlib.h>
#include "regular.h"

int 
main(void)
{
 int i; 
 printf("Imprimiendo 10 cadenas\n"); 
 char * generada;
 for(i = 0; i < 10;i++)
 {
  generada = generar_valida();
  printf("Cadena %d: %s\n",i+1,generada);
  free(generada);
 }
 return 0;
}
