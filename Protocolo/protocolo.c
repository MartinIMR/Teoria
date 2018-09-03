#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "automatasp.h"
#include "../biblioteca.h"

int 
main(void)
{
 FILE * archivo_cadenas, * archivo_aceptadas;
 char ** data = NULL; 
 int n = 10, m = 10, generacion = 1;
 archivo_cadenas = fopen("data.txt","w");
 archivo_aceptadas = fopen("accepted.txt","w");
 if(archivo_cadenas == NULL || archivo_aceptadas == NULL)
 {
  printf("Un archivo no pudo ser abierto\nSaliendo...\n");
  return -1;
 }
 while(aleatorio(1))
 {
  fprintf(archivo_cadenas,"------- Generacion %d -------\n",generacion); 
  data = crear_datos(archivo_cadenas,n,m);
  fprintf(archivo_cadenas,"------- Fin generacion %d -------\n",generacion); 
  #if defined(_WIN32) || defined(_WIN64)
   Sleep(2000);
  #else
   sleep(2000);
  #endif
  fprintf(archivo_aceptadas,"------- Filtradas %d -------\n",generacion);
  filtrar(archivo_aceptadas,data,n);
  fprintf(archivo_aceptadas,"------- Fin filtradas %d -------\n",generacion);
  free(data);
  generacion++;
 }
 fclose(archivo_cadenas);
 fclose(archivo_aceptadas);
 return 0;
}


