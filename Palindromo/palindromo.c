#include <stdio.h>
#include <stdlib.h>
#include "gramatica.h"


int
main(void)
{
 int opcion;
 char * cadena;
 FILE * archivo;
 archivo = fopen("derivacion.txt","w");
 if(archivo == NULL)
 {
  printf("No se pudo abrir el archivo...\n");
  return -1;
 }
 imprimir_reglas(archivo);
 do
 {
 printf("Escoge una opcion:\n");
 printf("1.-Automatico\n"); 
 printf("2.-Introducir longitud de palindromo\n"); 
 printf("3.-Salir\n"); 
 scanf("%d",&opcion);
 int k;
   if(opcion == 1)
   {
     k = aleatorio(100);
   }else if(opcion == 2)
   {
     printf("Introduce la longitud de la cadena\n");
     scanf("%d",&k);
   }else
   {
     printf("Saliendo...\n");
     opcion = 3;
   }
   
   if(opcion != 3)
   {
    derivar_cadena(k,archivo);
    fprintf(archivo,"\n ---------------- \n");
   }

 }while(opcion != 3);
 
 return 0;
}
