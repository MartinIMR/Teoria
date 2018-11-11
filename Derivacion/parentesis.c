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

 do
 {
 printf("Escoge una opcion:\n");
 printf("1.-Generar cadena\n"); 
 printf("2.-Introducir cadena\n"); 
 printf("3.-Salir\n"); 
   scanf("%d",&opcion);
   if(opcion == 1)
   {
     cadena = generar_cadena(aleatorio(1000));
   }else if(opcion == 2)
   {
     printf("Introduce el tamanio de la cadena\n");
     int k;
     scanf("%d",&k);
     cadena = (char *) malloc(sizeof(char)*(k+1));
     if(cadena == NULL)
     {
	printf("Error al reservar espacio para la cadena");
        return -1;
     }
     cadena[k]='\0';
     printf("Introduce la cadena\n");
     scanf("%s",cadena);
   }else
   {
     printf("Saliendo...\n");
     opcion = 3;
   }
   
   if(opcion != 3)
   {
    derivar_cadena(cadena,archivo);
    fprintf(archivo,"\n ---------------- \n");
   }

 }while(opcion != 3);
 
 return 0;
}
