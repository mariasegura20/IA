#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle_3_piezas.h"

// FUNCIONES DE ESTADO

tEstado *crearEstado(int matriz[N][N])
{
	tEstado * e = (tEstado *) malloc (sizeof(tEstado));
    int flagA=0, flagB=0, flagC=0;

	for (int i = 0 ; i < N ; i++)
    {
		for (int j = 0 ; j < N ; j++)
        {
        	e->celdas[i][j] = matriz[i][j];

            if(matriz[i][j]==A && !flagA)
            {
                e->pos[0][A-1] = i+1;
                e->pos[1][A-1] = j;
                flagA = 1;
            }

            if(matriz[i][j]==B && !flagB)
            {
                e->pos[0][B-1] = i+1;
                e->pos[1][B-1] = j;
                flagB = 1;
            }

            if(matriz[i][j]==C && !flagC)
            {
                e->pos[0][C-1] = i+1;
                e->pos[1][C-1] = j;
                flagC = 1;
            }
		}
	}

	return e;
}

tEstado *estadoInicial()
{
	return crearEstado(matriz_inicial);
}

tEstado *estadoObjetivo()
{
	return crearEstado(matriz_objetivo);
}

int coste(unsigned op, tEstado *e)
{
    return 1;
}

// VISUALIZACION DE ESTADOS Y OPERADORES

void dispEstado(tEstado *e)
{
   for (int i = 0 ; i < N ; i++)
   {
		for (int j = 0 ; j < N ; j++)
        {
        	printf("%d",e->celdas[i][j]);
    	}
    	printf("\n");
   }
   printf("\n");
}

void dispOperador(unsigned op)
{
	switch(op)
    {
      case ARRIBA_A:    printf("Movimiento ARRIBA de A:\n");    break;
      case ABAJO_A:     printf("Movimiento ABAJO de A:\n");     break;
      case IZQUIERDA_A: printf("Movimiento IZQUIERDA de A:\n"); break;
      case DERECHA_A:   printf("Movimiento DERECHA de A:\n");   break;
      case ARRIBA_B:    printf("Movimiento ARRIBA de B:\n");    break;
      case ABAJO_B:     printf("Movimiento ABAJO de B:\n");     break;
      case IZQUIERDA_B: printf("Movimiento IZQUIERDA de B:\n"); break;
      case DERECHA_B:   printf("Movimiento DERECHA de B:\n");   break;
      case ARRIBA_C:    printf("Movimiento ARRIBA de C:\n");    break;
      case ABAJO_C:     printf("Movimiento ABAJO de C:\n");     break;
      case IZQUIERDA_C: printf("Movimiento IZQUIERDA de C:\n"); break;
      case DERECHA_C:   printf("Movimiento DERECHA de C:\n");   break;
	}
}

// FUNCIONES DE OPERADORES

int esValido(unsigned op, tEstado *e)
{
    int valido = 0;
    int filA = e->pos[0][A-1], colA = e->pos[1][A-1];
    int filB = e->pos[0][B-1], colB = e->pos[1][B-1];
    int filC = e->pos[0][C-1], colC = e->pos[1][C-1];

    switch (op)
    {
        case ARRIBA_A:
            valido = (filA - 2 >= 0 &&
                e->celdas[filA-1][colA-1] == V &&
                e->celdas[filA-2][colA] == V &&
                e->celdas[filA-1][colA+1] == V);
            break;
        case ABAJO_A:
            valido = (filA + 2 < N &&
                e->celdas[filA+1][colA-1] == V &&
                e->celdas[filA+2][colA] == V &&
                e->celdas[filA+1][colA+1] == V);
            break;
        case IZQUIERDA_A:
            valido = (colA - 2 >= 0 &&
                e->celdas[filA-1][colA-1] == V &&
                e->celdas[filA][colA-2] == V &&
                e->celdas[filA+1][colA-1] == V);
            break;
        case DERECHA_A:
            valido = (colA + 2 < N &&
                e->celdas[filA-1][colA+1] == V &&
                e->celdas[filA][colA+2] == V &&
                e->celdas[filA+1][colA+1] == V);
            break;
        case ARRIBA_B:
            valido = (filB - 2 >= 0 &&
                e->celdas[filB-1][colB-1] == V &&
                e->celdas[filB-2][colB] == V &&
                e->celdas[filB-1][colB+1] == V);
            break;
        case ABAJO_B:
            valido = (filB + 1 < N &&
                e->celdas[filB+1][colB-1] == V &&
                e->celdas[filB+1][colB] == V &&
                e->celdas[filB+1][colB+1] == V);
            break;
        case IZQUIERDA_B:
            valido = (colB - 2 >= 0 &&
                e->celdas[filB-1][colB-1] == V &&
                e->celdas[filB][colB-2] == V);
            break;
        case DERECHA_B:
            valido = (colB + 2 < N &&
                e->celdas[filB-1][colB+1] == V &&
                e->celdas[filB][colB+2] == V);
            break;
        case ARRIBA_C:
            valido = (filC - 2 >= 0 &&
                e->celdas[filC-2][colC] == V);
            break;
        case ABAJO_C:
            valido = (filC + 2 < N &&
                e->celdas[filC+2][colC] == V);
            break;
        case IZQUIERDA_C:
            valido = (colC - 1 >= 0 &&
                e->celdas[filC-1][colC-1] == V &&
                e->celdas[filC][colC-1] == V &&
                e->celdas[filC+1][colC-1] == V);
            break;
        case DERECHA_C:
            valido = (colC + 1 < N &&
                e->celdas[filC-1][colC+1] == V &&
                e->celdas[filC][colC+1] == V &&
                e->celdas[filC+1][colC+1] == V);
            break;
    }

	return valido;
}

tEstado *aplicaOperador(unsigned op, tEstado *e){
    tEstado *n= (tEstado *) malloc(sizeof(tEstado));
    memcpy(n, e,sizeof(tEstado));
    int filA = n->pos[0][A-1], colA = n->pos[1][A-1];
    int filB = n->pos[0][B-1], colB = n->pos[1][B-1];
    int filC = n->pos[0][C-1], colC = n->pos[1][C-1];

    switch (op)
    {
        case ARRIBA_A:
            n->celdas[filA-1][colA-1] = A;
            n->celdas[filA-2][colA] = A;
            n->celdas[filA-1][colA+1] = A;
            n->celdas[filA][colA-1] = V;
            n->celdas[filA+1][colA] = V;
            n->celdas[filA][colA+1] = V;
            filA--;
            break;
        case ABAJO_A:
            n->celdas[filA+1][colA-1] = A;
            n->celdas[filA+2][colA] = A;
            n->celdas[filA+1][colA+1] = A;
            n->celdas[filA][colA-1] = V;
            n->celdas[filA-1][colA] = V;
            n->celdas[filA][colA+1] = V;
            filA++;
            break;
        case IZQUIERDA_A:
            n->celdas[filA-1][colA-1] = A;
            n->celdas[filA][colA-2] = A;
            n->celdas[filA+1][colA-1] = A;
            n->celdas[filA-1][colA] = V;
            n->celdas[filA][colA+1] = V;
            n->celdas[filA+1][colA] = V;
            colA--;
            break;
        case DERECHA_A:
            n->celdas[filA-1][colA+1] = A;
            n->celdas[filA][colA+2] = A;
            n->celdas[filA+1][colA+1] = A;
            n->celdas[filA-1][colA] = V;
            n->celdas[filA][colA-1] = V;
            n->celdas[filA+1][colA] = V;
            colA++;
            break;
        case ARRIBA_B:
            n->celdas[filB-1][colB-1] = B;
            n->celdas[filB-2][colB] = B;
            n->celdas[filB-1][colB+1] = B;
            n->celdas[filB][colB-1] = V;
            n->celdas[filB][colB] = V;
            n->celdas[filB][colB+1] = V;
            filB--;
            break;
        case ABAJO_B:
            n->celdas[filB+1][colB-1] = B;
            n->celdas[filB+1][colB] = B;
            n->celdas[filB+1][colB+1] = B;
            n->celdas[filB][colB-1] = V;
            n->celdas[filB-1][colB] = V;
            n->celdas[filB][colB+1] = V;
            filB++;
            break;
        case IZQUIERDA_B:
            n->celdas[filB-1][colB-1] = B;
            n->celdas[filB][colB-2] = B;
            n->celdas[filB-1][colB] = V;
            n->celdas[filB][colB+1] = V;
            colB--;
            break;
        case DERECHA_B:
            n->celdas[filB-1][colB+1] = B;
            n->celdas[filB][colB+2] = B;
            n->celdas[filB-1][colB] = V;
            n->celdas[filB][colB-1] = V;
            colB++;
            break;
        case ARRIBA_C:
            n->celdas[filC-2][colC] = C;
            n->celdas[filC+1][colC] = V;
            filC--;
            break;
        case ABAJO_C:
            n->celdas[filC+2][colC] = C;
            n->celdas[filC-1][colC] = V;
            filC++;
            break;
        case IZQUIERDA_C:
            n->celdas[filC-1][colC-1] = C;
            n->celdas[filC][colC-1] = C;
            n->celdas[filC+1][colC-1] = C;
            n->celdas[filC-1][colC] = V;
            n->celdas[filC][colC] = V;
            n->celdas[filC+1][colC] = V;
            colC--;
            break;
        case DERECHA_C:
            n->celdas[filC-1][colC+1] = C;
            n->celdas[filC][colC+1] = C;
            n->celdas[filC+1][colC+1] = C;
            n->celdas[filC-1][colC] = V;
            n->celdas[filC][colC] = V;
            n->celdas[filC+1][colC] = V;
            colC++;
            break;
    }

    n->pos[0][A-1] = filA;
    n->pos[1][A-1] = colA;
    n->pos[0][B-1] = filB;
    n->pos[1][B-1] = colB;
    n->pos[0][C-1] = filC;
    n->pos[1][C-1] = colC;

   return n;
}

// FUNCIONES DE COMPARACION

int iguales(tEstado *s, tEstado *t)
{
	int valido = 1;
	int i = 0, j = 0;

	while ((i < N) && valido)
	{
		while ((j < N) && valido)
		{
			if (s->celdas[i][j] != t->celdas[i][j])
				valido = 0;
        	j++;
		}
      	i++;
		j=0;
	}

	return valido;
}

int testObjetivo(tEstado *e) {
	int valido = 1;
	int i = 0, j = 0;

	while ((i < N) && valido)
    {
		while ((j < N) && valido)
        {
			if (e->celdas[i][j] != matriz_objetivo[i][j])
        		valido = 0;
         	j++;
      	}
      	i++;
		j=0;
   }

   return valido;
}