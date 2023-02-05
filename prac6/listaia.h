#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VACIA NULL

typedef struct ListaNodos {
    struct ListaNodos *next;
    int nodo[];
}ListaNodos;

typedef struct ListaNodos *LISTA;

/* Comprueba si la lista esta vacia.
   Devuelve 1 si la lista esta vacia y 0 en cualquier otro caso. */
int esVacia(LISTA c);

/* Inserta el nodo al principio de la lista. */
void InsertarPrimero(LISTA *c, void *n, int size);

/* Copia el primer nodo de la lista en el nodo. */
void ExtraerPrimero(LISTA c, void *n, int size);

/* Elimina el primer nodo de la lista. */
void EliminarPrimero(LISTA *c);

/* Inserta el nodo al final de la lista. */
void InsertarUltimo(LISTA *c, void *n, int size);

/* Concatena ambas listas.
   Devuelve la lista resultante. */
LISTA Concatenar(LISTA l1,LISTA l2);