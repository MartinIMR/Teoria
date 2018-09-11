#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca.h"

int 
main(void)
{
 char alfabeto[3]={'0','1','\0'};
 char ** sigma = NULL;
 sigma = convertir_AL(alfabeto);
 int k;
 printf("Introduce la potencia\n");
 scanf("%d",&k);
 FILE * archivo_universal = NULL;
 FILE * archivo_datos = NULL;
 archivo_universal = fopen("universal.txt","w");
 archivo_datos = fopen("./Grafica/datos.txt","w");
 if(archivo_universal == NULL || archivo_datos == NULL)
 {
  printf("Un archivo no pudo ser abierto...\n");
  return -1;
 }
 lenguaje_universal(archivo_universal,archivo_datos,sigma,k);
 fclose(archivo_universal);
 fclose(archivo_datos);
 free(sigma);
 return 0;
};
