
/* Construccion opcional: 

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



static struct PB
{
 const char * prb; 
 const char * epsilon;
} p_b = {"(RB",""};

static struct PR
{
 const char * p;
 const char * prr;
} p_r = {")","(RR"};


void derivar_cadena(char *,FILE *);
char * agregar_derivacion(char *,const char *);
char * derivacion_inicial(char *);
