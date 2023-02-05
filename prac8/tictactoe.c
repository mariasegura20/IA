#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"

// char marca (int i)
// i: jugador MAX o MIN
// devuelve el carácter correspondiente al jugador
char marca(int i);

tNodo * crearNodo(int celdas[N])
{
    tNodo * Nodo = (tNodo *) malloc (sizeof(tNodo));
    int c;
    Nodo->vacias=0;
    for (int i = 0 ; i < N ; i++)
    {
        c = celdas[i];
        Nodo->celdas[i] = c;
        if (c == 0)
	        Nodo->vacias = Nodo->vacias + 1;
    }

    return Nodo;
}

tNodo * estadoInicial()
{
   return crearNodo(tablero_inicial);
}

tNodo * aplicaJugada(tNodo * t, int jugador, int jugada)
{
    tNodo * nuevo = (tNodo *) malloc (sizeof(tNodo));
    memcpy(nuevo,t,sizeof(tNodo));
    
    nuevo->celdas[jugada] = jugador;
    nuevo->vacias--;
    nuevo->profundidad++;

    return nuevo;
}

int esValida(tNodo * t, int jugada)
{
    return (jugada >= 0 && jugada < N && t->celdas[jugada] == 0);
}

int terminal(tNodo * t)
{
    unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i=0, res=0;

    while (res == 0 && i < 8)
    {
        if(t->celdas[opciones[i][0]] != 0 &&
            t->celdas[opciones[i][0]] == t->celdas[opciones[i][1]] &&
            t->celdas[opciones[i][0]] == t->celdas[opciones[i][2]])
        
        res = t->celdas[opciones[i][2]];
        i++;
    }
    
    return res * 100;
}

int lleno(tNodo * t)
{
    return (t->vacias == 0);
}

int opuesto( int jugador)
{
    return (jugador * -1);
}

int min (int a, int b)
{
      int min;
      if(a<b)
            min = a;
      else
            min = b;
      return min;
}

int max (int a, int b)
{
      int max;
      if (a>b)
            max = a;
      else
            max = b;
      return max;
}

int heuristica (tNodo * t)
{
    int hX = 0, hO = 0;
    unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
      
    for (int i = 0 ; i < 8 ; i++)
    {     
        int flagX = 0, flagO = 0;

        for (int j = 0 ; j < 3 ; j++)
        {
            if (t->celdas[opciones[i][j]] == -1)
                flagO++;
                if (t->celdas[opciones[i][j]] == 1)
                    flagX++;
        }

        if (flagX > 0 && flagO == 0)
            hX++;
        if (flagX == 0 && flagO > 0)
            hO++;
    }

    return (hX-hO);
}

void dispNodo(tNodo *b)
{
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",marca(b->celdas[0]),marca(b->celdas[1]),marca(b->celdas[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",marca(b->celdas[3]),marca(b->celdas[4]),marca(b->celdas[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",marca(b->celdas[6]),marca(b->celdas[7]),marca(b->celdas[8]));
    printf("---+---+---\n\n");
}

char marca(int i)
{
    switch(i)
    {
        case 1: return 'X';
        case 0: return ' ';
        case -1: return 'O';
        default: return ' ';
    }
}