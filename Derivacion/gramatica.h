enum variables {B,R};
/* Produccion B */
struct PB
{
 const char * prb; 
 const char * epsilon;
};
/* Produccion R */
struct PR
{
 const char * p;
 const char * prr;
};


void derivar_cadena(char *,FILE *);
char * agregar_derivacion(char *,const char *);
char * derivacion_inicial(char *);
int siguiente_variable(char *,int);
char * generar_cadena(int);
int aleatorio(int);




/*  Declaracion opcional:

struct PB
{
 const char * prb; 
 const char * epsilon;
};

struct PB produccion_b = {"(RB",""};

struct PR
{
 const char * p;
 const char * prr;
};

const char * cadena1 = "(";
const char cadena2[]= "(RR";

struct PR produccion_r = {cadena1,cadena2};
 
*/
