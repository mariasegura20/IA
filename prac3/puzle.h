#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
#define N 2

#ifndef _tEstado_
#define _tEstado_
typedef struct {
  int celdas[N][N];
  int fila, col;
} tEstado;
#endif

static int puzle_inicial[N][N]=
{
  {0,1},
  {3,2}
};

static int puzle_final[N][N]=
{
  {1,2},
  {0,3}
};

/* A partir de una configuracion de fichas construye un estado valido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[N][N]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();

/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador. */
void dispOperador(unsigned op);

/* Comprueba si es posible aplicar un operador a una configuracion determinada para el puzle.
  Devuelve 1 si el movimiento es valido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuracion concreta del puzle.
  Devuelve la nueva configuracion del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);