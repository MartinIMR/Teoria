
enum ESTADO_CEROUNO{q0,q1,q2};

struct data
{
 FILE * file;
 char * string;
 int length;
 int state;
 int columns;
};

void *
hilo(void *);

void 
evaluar_cadena(FILE *,char *);



