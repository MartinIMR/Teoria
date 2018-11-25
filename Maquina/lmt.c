#include <stdio.h>
#include <stdlib.h>
#include "MT.h"

int
main(void)
{
  FILE * salida;
  salida = fopen("datos.txt","w");
  if(salida == NULL)
  {
    printf("Error al crear el archivo de datos para animacion\n");
  }
  int n = 100;
  char buffer[n];
  buffer[n-1] = '\0';
  printf("Introduce la cadena:\n");
  scanf("%s",buffer);
  fprintf(salida,"%s\n",buffer);
  if(automata(buffer,salida) == q4)
  {
   printf("La cadena %s es aceptada\n",buffer);
   fprintf(salida,"aceptada\n");
  }else
  {
   printf("La cadena %s no es aceptada\n",buffer);
   fprintf(salida,"no aceptada\n");
  }
  fclose(salida);
  return 0;
}
