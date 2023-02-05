#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaia.h"
#include "busqueda.h"

int main()
{
    int seleccion, lim;
    printf("Posibles algoritmos para la solucion del puzle:\n 1) Busqueda en anchura \n 2) Busqueda en profundidad \n 3) Busqueda en anchura con control de estados repetidos \n 4) Busqueda en profundidad con control de estados repetidos \n 5) Busqueda con profundidad limitada \n 6) Busqueda con profundidad limitada iterativa \n 7) Busqueda voraz \n 8) Busqueda A* \nSeleccion: ");
    scanf("%d", &seleccion);
    switch (seleccion)
    {
        case 1:
            solucionFin(busqueda_anchura());
            break;
        case 2:
            solucionFin(busqueda_profundidad());
            break;
        case 3:
            solucionFin(busqueda_anchura_estado_repetido());
            break;
        case 4:
            solucionFin(busqueda_profundidad_estado_repetido());
            break;
        case 5:
            printf("Introduzca el limite de profundidad: ");
            scanf("%d", &lim);
            solucionFin(busqueda_profundidad_limitada(lim));
            break;
        case 6:
            solucionFin(busqueda_profundidad_limitada_iterativa());
            break;
        case 7:
            solucionFin(busqueda_voraz());
            break;
        case 8:
            solucionFin(busqueda_a());
    }
    
    return 0;
}