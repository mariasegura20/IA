#include <stdio.h>
#include <stdlib.h>

#include "puzle.h"

int main(int argc, const char * argv[]) {
    int op;
    tEstado *n, *a;
    a=estadoInicial();

    for (op=1 ; op <= NUM_OPERADORES ; op++)
    {
        if (esValido(op,a))
        {
            n=aplicaOperador(op,a);
            dispOperador(op);
            dispEstado(n);
        }
    }

    system("pause");
    return 0;
}
