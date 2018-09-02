#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int 
main(void)
{
 printf("Introduce el numero para los primos anteriores a el\n");
 int n,m;
 scanf("%d",&n);
 int * lista = (int *) malloc(sizeof(int) * (n-1));
 if(lista == NULL)
 {
  printf("Error no se ha podido reservar memoria para la lista\n");
  return -1;
 }
 /*
 for(int i=2; i<= n; lista[i-2] = i++);
 */
 
 for(int i=2;i <= n ;i++)
 {
   lista[i-2] = i;
 }
 m = criba_eratostenes(lista,n);
 int * primos = (int *) malloc(sizeof(int) * m);
 char ** primos_binarios = (char **) malloc(sizeof(char *) * (m+1));
 if(primos == NULL || primos_binarios == NULL)
 {
   printf("Error no se ha podido reservar memoria para los primos\n");
   return -1;
 }

 *(primos_binarios + m) = (char *) malloc(sizeof(char) * 2);
 if(primos_binarios[m] == NULL)
 {
   printf("Error al intentar reservar el fin de cadena\n");
 }
 *(*(primos_binarios + m)) = '\0';
 *(*(primos_binarios + m) + 1) = '\0';
 obtener_primos(lista,primos,primos_binarios,m);
 return 0;
};

