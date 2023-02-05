#include "puzle.h"

#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;

#endif

/* Muestra si se ha llegado al objetivo. */
void solucionFin(int res);

/* Muestra el estado del nodo*/
void dispNodo(tNodo *nodo);

/* Muestra el recorrido del arbol desde el nodo inicial hasta el objetivo. */
void dispCamino(tNodo *nodo);

/* Muestra datos relevantes de la solucion final. */
void dispSolucion(tNodo *nodo);

/* Crea el nodo raiz. */
tNodo *nodoInicial();

/* Expande un nodo. */
LISTA expandir(tNodo *nodo);

/* Busqueda en anchura. */
int busqueda_anchura();

/* Busqueda en profundidad. */
int busqueda_profundidad();

/* Funcion auxiliar para las funciones con control de estado repetido. */
int buscaRepe(tNodo * actual, LISTA cerrados);

/* Busqueda en anchura con control de estado repetido. */
int busqueda_anchura_estado_repetido();

/* Busqueda en profundidad con control de estado repetido. */
int busqueda_profundidad_estado_repetido();

/* Busqueda con profundidad limitada. */
int busqueda_profundidad_limitada(int lim);

/* Busqueda con profundidad limitada iterativa. */
int busqueda_profundidad_limitada_iterativa();

/* Comparación de f = h de la busqueda voraz. */
int comparaV (tNodo *e, tNodo *nuevo);

/* Comparación de f = g + h de la busqueda A*. */
int comparaA (tNodo *e, tNodo *nuevo);

/* Insertar un nodo en una lista de forma ordenada. */
LISTA insertarOrdenado(LISTA c, tNodo *n, int tipo);

/* Ordena la lista de abiertos + sucesores. 
   Recibe los parametros Ab (lista de abiertos), q (lista de sucesores) y el
   entero tipo (0 para busqueda voraz y 1 para A*)
   Devuelve la lista Ab, ordenada en función del tipo de busqueda*/
LISTA ordenarLista(LISTA Ab, LISTA q, int tipo);

/* Funcion heuristica: Número de piezas mal colocadas. */
int heuristica_piezas (tEstado *e);

/* Funcion heuristica: Distancia de Manhattam. */
int heuristica_manhattan (tEstado *e);

/* Busqueda voraz. */
int busqueda_voraz ();

/* Busqueda A* */
int busqueda_a ();