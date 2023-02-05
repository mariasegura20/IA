#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaia.h"
#include "busqueda.h"

int main()
{
    int seleccion;
    printf("Algoritmos de busqueda disponibles: \n 1) Anchura \n 2) Profundidad \n 3) Anchura con control de estado repetido \n 4) Profundidad con control de estado repetido \nSeleccion: ");
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
    }
    
    return 0;
}
