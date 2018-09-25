#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
 int i = 0;
 FILE * archivo;
 archivo = fopen("automatalex.h","w");
 fprintf(archivo,"enum estados{\n"); 
 char unidades[] = {'q','0','\0'};
 char decenas[] = {'q','1','0','\0'};
 char centenas[] = {'q','1','0','0','\0'};
 int j = 0;
 int k = 0;
 int l = 1;
 int m = 1;
 char un,de,ce;
 while(i<116)
 {
   switch(j)
   {
     case 0:
     un = k + '0';
     unidades[1] = un;
     fprintf(archivo,"%s,",unidades);
     i++;
     k++;
     if(i == 10)
     {
       k = 0;
       j++;
     }
     break;
     case 1:
     un = k + '0';
     de = l + '0';
     decenas[1] = de;
     decenas[2] = un;
     fprintf(archivo,"%s,",decenas);	
     i++;
     k++; 
     if( (i % 10) == 0 )
     {
	k = 0;
	l++;	
     }
     else if( i == 100 )
     {
	k = 0;
	l = 0;
        j++;
     }
     break;
     case 2:
     if(i==100)
     {
	k = 0;
	l = 0;
        m = 1;
     }
     un = k + '0';
     de = l + '0';
     ce = m + '0';
     centenas[1] = ce;
     centenas[2] = de;
     centenas[3] = un; 
     fprintf(archivo,"%s,",centenas);
     i++;
     k++; 
     if( (i % 10) == 0 )
     {
	k = 0;
	l++;
     }else if( (i % 100)  == 0 )
     {
        k = 0;
	l = 0;
	m++;
     }else if(i == 1000)
     {
	break;
     }

     break;
   }

 }
 fprintf(archivo,"%s}\n","116");  
 fclose(archivo);
 return 0;
}


