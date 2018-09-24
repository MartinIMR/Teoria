#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca.h"
#include "automatano.h"
#define MAX 252

int
main(int argc,char * argv[])
{
 FILE * archivo;
 archivo = fopen("rutas.txt","w+");
 if(archivo == NULL)
 {
  printf("No se pudo abrir el archivo\n Saliendo...\n");
  return -1;
 }
 char * cadena = NULL;
 int opcion;
 do{
  printf("Selecciona una opcion\n");
  printf("1.-Ingresar una cadena\n");
  printf("2.-Generar una cadena\n");
  printf("3.-Mostrar diagrama de estados\n");
  printf("4.-Salir\n");
  scanf("%d",&opcion); 
  switch(opcion)
  {
    case 1:
    printf("Introduce la cadena\n");
    char buffer[MAX];
    scanf("%s",buffer);
    evaluar_cadena(archivo,buffer);
    break;
    case 2:
    cadena = generar_cadena(aleatorio(MAX));
    printf("La cadena generada por el sistema es:\n");
    printf("%s\n",cadena);
    evaluar_cadena(archivo,cadena);
    free(cadena);
    break;
    case 3:
    printf("En construccion...\n");
    break;
    default:
    printf("Saliendo...\n");
    opcion = 4;
    break;
  }
 }while(opcion != 4);

 return 0;
}
