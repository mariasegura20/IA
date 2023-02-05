#define ARRIBA_A        1
#define ABAJO_A         2
#define IZQUIERDA_A     3
#define DERECHA_A       4
#define ARRIBA_B        5
#define ABAJO_B         6
#define IZQUIERDA_B     7
#define DERECHA_B       8
#define ARRIBA_C        9
#define ABAJO_C         10
#define IZQUIERDA_C     11
#define DERECHA_C       12
#define NUM_OPERADORES  12
#define N               6

#define V               0
#define A               1
#define B               2
#define C               3
#define Ob              4

#ifndef _tEstado_
#define _tEstado_
typedef struct {
  int celdas[N][N];
  int pos[2][3];
} tEstado;
#endif

static int matriz_inicial[N][N] = {
    {Ob,V,V,C,V,V},
    {Ob,V,V,C,V,V},
    {V,A,V,C,V,V},
    {A,A,A,Ob,B,V},
    {V,A,V,B,B,B},
    {V,V,V,V,V,V}
};

static int matriz_objetivo[N][N] = {
    {Ob,V,V,V,V,V},
    {Ob,V,V,V,V,V},
    {V,V,V,V,V,V},
    {V,A,V,Ob,V,C},
    {A,A,A,B,V,C},
    {V,A,B,B,B,C}
};


/* A partir de una configuracion de fichas construye un estado valido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int matriz[N][N]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();

/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *e);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *e);

/* Muestra el nombre de cada operador. */
void dispOperador(unsigned op);

/* Comprueba si es posible aplicar un operador a una configuracion determinada para el puzle.
  Devuelve 1 si el movimiento es valido y 0 en otro caso. */
int esValido(unsigned op, tEstado* e);

/* Aplica un operador a una configuracion concreta del puzle.
  Devuelve la nueva configuracion del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *e);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *e);