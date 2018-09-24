#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "automatano.h"


void *
hilo(void * parametros)
{
  struct data * args = (struct data *) parametros;
  char * cadena = args -> string;
  int i = 0;
  int j;
  while(cadena[i] != '\0')
  {
     switch(args->state)
     {
	case q0:
	    if(cadena[i] == '1')
	    {
		if(!(i == (args->length-1)))
		{
		fprintf(args->file,"%s\n","q0");
		}
	    }else
	    {
		args->columns += 2;
		fprintf(args->file,"%s %*s\n","q0",args->columns,"q1");
		struct data nargs = {args->file,(cadena+(i+1)),args->length,q1,args->columns};
		pthread_t id_nhilo;
		pthread_create(&id_nhilo,NULL,hilo,(void *)(&nargs));
		pthread_join(id_nhilo,NULL);
	    }
	break;

	case q1:
		
    	    if(cadena[i] == '1')
	    {
		fprintf(args->file,"%*s\n",args->columns+3,"q2");
		args->state = q2;
		args->string = (cadena+1);
	    }else
	    {
		fprintf(args->file,"%*s\n",args->columns+3,"X");
		return NULL;
	    }

	break;

	case q2:
	fprintf(args->file,"%*s\n",args->columns+3,"X");
	   return NULL;
	break;
     }
     i++;
  }
  if(args->state == q2)
  {
	printf("La cadena introducida fue aceptada\n");
	fprintf(args->file,"\n Cadena aceptada \n La ruta es:\n"); 
	for(j=0;j < ((args->length)-2);j++)
	{
	  fprintf(args->file,"%s -> ","q0");
	}
	fprintf(args->file,"%s -> %s\n","q1","q2");
  }
  
  return NULL;
}


void 
evaluar_cadena(FILE * archivo, char * cadena)
{
 int longitud = (int)strlen(cadena);
 fprintf(archivo,"La cadena a evaluar es:\n %s \n",cadena);
 struct data args = {archivo,cadena,longitud,q0,0};
 pthread_t inicial;
 pthread_create(&inicial,NULL,hilo,(void *)(&args));
 pthread_join(inicial,NULL); 
 
}


