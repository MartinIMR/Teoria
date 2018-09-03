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
 lenguaje_universal(sigma,k);
 return 0;
};
