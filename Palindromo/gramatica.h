/* Produccion P */
struct PP
{
 const char * epsilon; 
 const char * cero;
 const char * uno; 
 const char * cero_p_cero;
 const char * uno_p_uno;
};


void derivar_cadena(int,FILE *);
char * agregar_derivacion(char *,const char *);
char * derivacion_inicial(const char *);
int aleatorio(int);
void imprimir_reglas(FILE *);
