#include "automatalex.h"
#include <string.h>

int
automata_lexico(char * cadena)
{
 int i = 0;
 enum estados estado = q0;
  while(cadena[i] != '\0')
  {
      switch(estado)
      {
	case q0:
	
	break;
	case q1:
	
	break;
	case q2:
	
	break;
	case q3:
	
	break;
	case q4:
	
	break;
	case q5:
	
	break;

      } 
  }

}




int 
quick_automata(char * cadena,int reservadas[32])
{
 
 switch(cadena[0])
 {
   case 'a':
	if(!strcmp(cadena,"auto"))
	{
	  reservadas[0]++;
	  return 1;
	}
	return 0;
   break;
   case 'b':
	if(!strcmp(cadena,"break"))
	{
	 reservadas[1]++;
	 return 1;
	}
	return 0;
   break;
   case 'c':
	if(!strcmp(cadena,"case"))
	{
	 reservadas[2]++;
	 return 1;
	}else if(!strcmp(cadena,"char")){
	 reservadas[3]++;
	 return 1;
	}else if(!strcmp(cadena,"const")){
	 reservadas[4]++;
         return 1;
	}else if(!strcmp(cadena,"continue")){
	 reservadas[5]++;
	 return 1;
	}
	return 0;
   break;
   case 'd':
	if(strcmp(cadena,"default") == 0)
	{
	 reservadas[6]++;
	 return 1;
	}else if(strcmp(cadena,"do") == 0){
	 reservadas[7]++;
	 return 1;
	}else if(strcmp(cadena,"double") == 0){
	 reservadas[8]++;
	 return 1;
	}
	return 0;
   break;
   case 'e': 
	if(strcmp(cadena,"else") == 0)
	{
	 reservadas[9]++;
	 return 1;
	}else if(strcmp(cadena,"enum") == 0){
	 reservadas[10]++;
	 return 1;
	}else if(strcmp(cadena,"extern") == 0){
	 reservadas[11]++;
	 return 1;
	}
	return 0;
   break;
   case 'f':
	if(strcmp(cadena,"float") == 0)
	{
	 reservadas[12]++;
	 return 1;
	}else if(strcmp(cadena,"for") == 0){
	 reservadas[13]++;
	 return 1;
	}
	return 0;
   break;
   case 'g':
	if(strcmp(cadena,"goto") == 0)
	{
	 reservadas[14]++;
	 return 1;
	}
	return 0;
   break;
   case 'i':
	if(strcmp(cadena,"if") == 0)
	{
	 reservadas[15]++;
	 return 1;
	}else if(strcmp(cadena,"int") == 0){
	 reservadas[16]++;
	 return 1;
	}
	return 0;
   break;
   case 'l':
	if(strcmp(cadena,"long") == 0)
	{
	 reservadas[17]++;
	 return 1;
	}
	return 0;
   break;
   case 'r':
	if(strcmp(cadena,"register") == 0)
	{
	 reservadas[18]++;
	 return 1;
	}else if(strcmp(cadena,"return") == 0){
	 reservadas[19]++;
	 return 1;
	}
	return 0;
   break;
   case 's':
	if(strcmp(cadena,"short") == 0)
	{
	 reservadas[20]++;
	 return 1;
	}else if(strcmp(cadena,"signed") == 0){
	 reservadas[21]++;
	 return 1;
	}else if(strcmp(cadena,"sizeof") == 0){
	 reservadas[22]++;
	 return 1;
	}else if(strcmp(cadena,"static") == 0){
	 reservadas[23]++;
	 return 1;
	}else if(strcmp(cadena,"struct") == 0){
	 reservadas[24]++;
	 return 1;
	}else if(strcmp(cadena,"switch") == 0){
	 reservadas[25]++;
	 return 1;
	}
	return 0;
   break;
   case 't':
	if(strcmp(cadena,"typedef") == 0)
	{
	 reservadas[26]++;
	 return 1;
	}
	return 0;
   break;
   case 'u':
	if(strcmp(cadena,"union") == 0)
	{
	 reservadas[27]++;
	 return 1;
	}else if(strcmp(cadena,"unsigned") == 0){
	 reservadas[28]++;
	 return 1;
	}
	return 0;
   break;
   case 'v':
	if(strcmp(cadena,"volatile") == 0)
	{
	 reservadas[29]++;
	 return 1;
	}else if(strcmp(cadena,"void") == 0){
	 reservadas[30]++;
	 return 1;
	}
	return 0;
   break;
   case 'w':
	if(strcmp(cadena,"while") == 0)
	{
	 reservadas[31]++;
	 return 1;
	}
	return 0;
   break;
   default:
   return 0;
   break;
 }

}

