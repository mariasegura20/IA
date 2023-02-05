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