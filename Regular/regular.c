#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regular.h"
#include "../biblioteca.h"

char *
concatenar_cadenas (char *s1, char *s2)
  {
    char *concatenada = NULL;
    int l1, l2;
    l1 = (int) strlen (s1);
    l2 = (int) strlen (s2);
    concatenada = (char *) malloc (sizeof (char) * (l1 + l2 + 1));
    if (concatenada == NULL)
      {
	printf ("Error al reservar memoria para la concatenada\n");
	return NULL;
      }
    concatenada[l1 + l2] = '\0';
    strcpy (concatenada, s1);
    strcat (concatenada, s2);
    return concatenada;
  }

char *
potenciar_cadena (char *cadena, int potencia)
{
    char *potenciada = NULL;
    if (potencia <= 0)
      {
	potenciada = (char *) malloc (sizeof (char));
	if (potenciada == NULL)
	  {
	    printf ("No se pudo reservar espacio para la potenciada...\n");
	    return NULL;
	  }
	potenciada[0] = '\0';
	return potenciada;
      }
    int longitud = strlen (cadena);
    int espacios = longitud * potencia;
    potenciada = (char *) malloc (sizeof (char) * (espacios + 1));
    if (potenciada == NULL)
      {
	printf ("No se pudo reservar espacio para la potenciada...\n");
	return NULL;
      }
    potenciada[espacios] = '\0';
    strcpy (potenciada, cadena);
    int i;
    for (i = 1; i < potencia; i++)
      {
	strcat (potenciada, cadena);
      }
    return potenciada;
}

char *
cerradura_kleene()
{
 
 return NULL;
}

char * 
generar_valida()
{
  int limite = 100;
  int repeticiones;
  char *cadena = NULL;
  if(aleatorio(1))
  {
   /* 0(11)^*( ( 00 + 01 )^* + ( e + 0 + 00 )^* )^* */
   cadena = potenciar_cadena("0",1);
   char * temporal = potenciar_cadena("",0);
   char * vin;
   if(aleatorio(1))
   {
    /* (11)^* */
    temporal = potenciar_cadena("11",aleatorio(limite)+1);
   };
   vin = cadena;
   cadena = concatenar_cadenas(vin,temporal);
   free(vin);
   free(temporal);
   if(aleatorio(1))
   {
     /* ( ( 00 + 01 )^* + ( e + 0 + 00 )^* )^* */
     int subrepeticiones;
     repeticiones = aleatorio(limite) + 1;
     while(repeticiones)
     {
	subrepeticiones = aleatorio(limite) + 1;
	if(aleatorio(1))
	{
	   /* (00 + 01)^* */
	   while(subrepeticiones)
	   {
	      switch(aleatorio(1))
	      {
		case 0:
		temporal = potenciar_cadena("00",1);
		break;
		case 1:
		temporal = potenciar_cadena("01",1);
		break;
	      }
	      vin = cadena;
	      cadena = concatenar_cadenas(vin,temporal);
	      free(vin);
	      free(temporal);
	      subrepeticiones--;
	   }
	}else
	{
 	   /* (e + 0 + 01)^* */ 
	   while(subrepeticiones)
	   {
	      switch(aleatorio(2))
	      {
		case 0:
		temporal = potenciar_cadena("",0);
		break;
		case 1:
		temporal = potenciar_cadena("0",1);
		break;
		case 2:
		temporal = potenciar_cadena("01",1);
		break;
	      }
	      vin = cadena;
	      cadena = concatenar_cadenas(vin,temporal);
	      free(vin);
	      free(temporal);
	      subrepeticiones--;
	   }

	}
	repeticiones--;
     }
 
   };

  }else
  {
   cadena = potenciar_cadena("00",1);
  } 
 return cadena;
}
