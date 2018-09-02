#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioteca.h"

/*Calculo del lenguaje universal para cadenas de hasta longitud k
  sin reservar espacio para almacenar todas las cadenas ya que se 
  requeriria demasiada memoria. Es decir solo imprime los resultados*/

int 
contar_unos(char * cadena)
{
  int numero_unos = 0;
  for(int i=0;cadena[i] != '\0';i++)
  {
    if(cadena[i] == '1')
    {
     numero_unos++; 
    };
  };
  return numero_unos;
};

char *
convertir_binario(int numero)
{
 int cociente,residuo;
 char caracter;
 char * cadena;
 static int i,n=0;
 cociente = (int)(numero/2);
 residuo = numero % 2;
 caracter = (int)(residuo + '0');
 n++;
 if(cociente == 0)
 {
  i = n;
  cadena = (char *) malloc(sizeof(char)*(n+1));
  if(cadena == NULL)
  {
    printf("No se pudo reservar memoria\n");
  }
  cadena[n] = '\0';
 }else
 {
 cadena = convertir_binario(cociente);
 }
 cadena[n-i] = caracter;
 i--;
 return cadena;
}

void
obtener_primos(int * lista,int * primos,char ** binarios,int cantidad)
{
 FILE * archivo_primos, * archivo_binarios, * archivo_grafica;
 archivo_primos = fopen("primos.txt","w");
 archivo_binarios = fopen("binarios.txt","w");
 if(archivo_primos == NULL || archivo_binarios == NULL  )
 {
  printf("Un archivo no pudo ser abierto...\n");
  return;
 }
 fprintf(archivo_primos,"Los primos son:\n{");
 fprintf(archivo_binarios,"Los primos en binario son:\n{");
 for(int i = 0, j = 0 ; i < cantidad ;i++)
 {
    while(lista[j++] == 0);
    j--;
    primos[i] = lista[j];
    *(binarios + i) = convertir_binario(primos[i]);
    fprintf(archivo_primos,"%d,",primos[i]);
    fprintf(archivo_binarios,"%s,",binarios[i]);
    j++;
 }
 fprintf(archivo_primos,"\b}");
 fprintf(archivo_binarios,"\b}");
 fprintf(archivo_primos,"\n");
 fprintf(archivo_binarios,"\n");
 fclose(archivo_primos);
 fclose(archivo_binarios);

}


void
lenguaje_universal(char ** alfabeto, int k)
{
 static int i = 0;
 static char ** lenguaje_actual=NULL;
 static FILE * archivo = NULL;
 static FILE * datos = NULL;

 if(datos == NULL)
 {
   datos = fopen("datos.txt","w");
   if(datos == NULL)
   {
    printf("Error no se pudo abrir el archivo\nSaliendo...\n");
    exit(-1);
   };
 };
 
 if( k > 19 )
 {
  if(archivo == NULL)
  {
    archivo = fopen("universal.txt","w");
   if(archivo == NULL)
   {
    printf("Error no se pudo abrir el archivo\nSaliendo...\n");
    exit(-1);
   };

  };
  
  if(i == 0)
  {
  lenguaje_actual = alfabeto;
  fprintf(archivo,"Para cadenas de hasta %d longitud el lenguaje universal sera:\n",k);
  fprintf(archivo,"Σ^* = {ε");
  };

  if(i == k)
  {
  fprintf(archivo,"}\n"); 
  }else
  {
  int l=0;
  for(int j=0;lenguaje_actual[j][0] != '\0';j++)
  {
   fprintf(archivo,",%s",lenguaje_actual[j]); 
   l += contar_unos(lenguaje_actual[j]);
  };
   fprintf(datos,"%d %d\n",i+1,l);
  lenguaje_actual = concatenar_lenguajes(lenguaje_actual,alfabeto);
  i++;
  lenguaje_universal(alfabeto,k);
  };


 }else
 {

  if(i == 0)
  {
  lenguaje_actual = alfabeto;
  printf("Para cadenas de hasta %d longitud el lenguaje universal sera:\n",k);
  printf("Σ^* = {ε");
  };

  if(i == k)
  {
   printf("}\n"); 
  }else
  {
  int l=0;
  for(int j=0;lenguaje_actual[j][0] != '\0';j++)
  {
   printf(",%s",lenguaje_actual[j]); 
   l += contar_unos(lenguaje_actual[j]);
  };
  fprintf(datos,"%d %d\n",i+1,l);
  lenguaje_actual = concatenar_lenguajes(lenguaje_actual,alfabeto);
  i++;
  lenguaje_universal(alfabeto,k);
  };

 };

};

int
cardinalidad_lenguaje(char ** lenguaje)
{
 int i;
 for(i=0;lenguaje[i][0] != '\0';i++);
 return i;
};

/* Modifica la lista dada dejando solo los numeros que son primos */

void 
criba_eratostenes(int * lista,int n)
{
 int raiz = (int) floor(sqrt(n));
 for(int i = 2; i <= raiz; i++ )
 {
   if(lista[i-2] != 0)
   {
	int primo = lista[i-2];
	int limite = (int) floor(n/primo);
	for(int j = 2 ; j <= limite ; j++)
	{
	  lista[(primo*j)-2] = 0;
	};
   };

 };

};


char **
reservar_memoria(int filas,int columnas)
{
 char ** lenguaje;
 lenguaje = (char **) malloc(sizeof(char *) * filas);
 if(lenguaje == NULL)
 {
  printf("No se pudieron reservar las %d filas\n",filas);
  exit(-1);
 };

 for(int i=0;i<filas;i++)
 {
  lenguaje[i] = (char *) malloc(sizeof(char) * columnas);
  if(lenguaje[i] == NULL)
  {
    printf("No se pudieron reservar las %d columnas para la fila %d",columnas,i);
    exit(-1);
  };
 };
 return lenguaje;
};

char **
potenciar_lenguaje(char ** lenguaje, int potencia)
{
 if(potencia == 1)
 {
  return lenguaje;
 };
 return concatenar_lenguajes(lenguaje,potenciar_lenguaje(lenguaje,potencia-1));
};

char **
concatenar_lenguajes(char ** L1,char ** L2)
{
 
 char ** lenguaje_concatenacion;
 int CL1 = cardinalidad_lenguaje(L1);
 int CL2 = cardinalidad_lenguaje(L2);
 int numero_filas = (CL1 * CL2) + 1;
 lenguaje_concatenacion = (char **) malloc(sizeof(char *) * numero_filas);
 int k = 0; 
 for(int i = 0; i < CL1;i++)
 {
   int lcadena_1 = longitud_cadena(L1[i]);
   for(int j = 0; j < CL2;j++)
   {
   int lcadena_2 = longitud_cadena(L2[j]);
   int numero_columnas = lcadena_1 + lcadena_2 + 1;
   lenguaje_concatenacion[k] = (char *) malloc(sizeof(char) * numero_columnas);
   strcat(lenguaje_concatenacion[k],L1[i]);
   strcat(lenguaje_concatenacion[k],L2[j]);
   k++;
   };
 };
  lenguaje_concatenacion[k] = (char *) malloc(sizeof(char)*2);
  lenguaje_concatenacion[k][0] = '\0';
  lenguaje_concatenacion[k][1] = '\0';
 return lenguaje_concatenacion;
};
 
int
longitud_cadena(char * cadena)
{
 int i;
 for(i = 0; cadena[i] != '\0';i++);
 return i;
};


char **
convertir_AL(char * alfabeto)
{
 int i=0;
  while(alfabeto[i] != '\0')
  {
   i++;
  };
 char ** lenguaje=NULL;
 i++;
 lenguaje = reservar_memoria(i,2);
 for(int j;j<i;j++)
 {
  lenguaje[j][0] = alfabeto[j];
  lenguaje[j][1] = '\0'; 
 };
 return lenguaje;
};


void
imprimir_lenguaje(char ** lenguaje)
{
 for(int i=0; lenguaje[i][0] != '\0';i++)
 {
  printf("La cadena %d del lenguaje es:%s\n",i,lenguaje[i]);
 };
};

