#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"

// FUNCIONES DE ESTADO

tEstado *crearEstado(int puzle[N][N]) {
	tEstado * e = (tEstado *) malloc (sizeof(tEstado));
	int ficha;
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++) {
        	ficha=puzle[i][j];
        	e->celdas[i][j]=ficha;
          
        	if(ficha == 0){
            	e->fila=i;
				e->col=j;
         	}
		}
	}
	return e;
}

tEstado *estadoInicial() {
	return crearEstado(puzle_inicial);
}

tEstado *estadoObjetivo() {
	return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *e) {
	return 1;
}

// VISUALIZACION DE ESTADOS Y OPERADORES

void dispEstado(tEstado *e) {
   int i,j;

   for (i=0; i<N; i++){
		for (j=0; j<N; j++){
        	printf("%d",e->celdas[i][j]);
    	}
    	printf("\n");
   }
   printf("\n");
}

void dispOperador(unsigned op) {
	switch(op) {
      case ARRIBA: printf("Movimiento ARRIBA:\n"); break;
      case ABAJO: printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA: printf("Movimiento DERECHA:\n"); break;
	}
}

// FUNCIONES DE OPERADORES

int esValido(unsigned op, tEstado *estado) {
   int valido;

	switch (op) {
		case ARRIBA:
			valido = (estado->fila > 0);
         	break;
      	case ABAJO:
        	valido = (estado->fila < N-1);
         	break;
      	case IZQUIERDA:
        	valido = (estado->col > 0);
         	break;
      	case DERECHA: 
        	valido = (estado->col < N-1);
         	break;
   	}

	return valido;
}

tEstado *aplicaOperador(unsigned op, tEstado *e){
   tEstado * n= (tEstado *) malloc(sizeof(tEstado));
   memcpy(n, e,sizeof(tEstado));

   int c = n->col;
   int f = n->fila;

   switch (op) {
		case ARRIBA:
        	n->celdas[f][c] = n->celdas[f-1][c];
         	n->celdas[f-1][c] = 0;
        	n->fila--;
    		break;
      	case ABAJO:
        	n->celdas[f][c] = n->celdas[f+1][c];
        	n->celdas[f+1][c] = 0;
        	n->fila++;
    		break;
    	case IZQUIERDA:
        	n->celdas[f][c] = n->celdas[f][c-1];
        	n->celdas[f][c-1] = 0;
        	n->col--;
			break;
      	case DERECHA:
        	n->celdas[f][c] = n->celdas[f][c+1];
        	n->celdas[f][c+1] = 0;
        	n->col++;
    		break;
   }

   return n;
}

// FUNCIONES DE COMPARACION

int iguales(tEstado *s, tEstado *t) {
	int valido = 1;
	int i = 0, j = 0;

	while ((i < N) && valido) {
		while ((j < N) && valido){
			if (s->celdas[i][j] != t->celdas[i][j]){
				valido = 0;
			}
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

	while ((i < N) && (valido == 1)) {
		while ((j < N) && (valido == 1)){
			if (e->celdas[i][j] != puzle_final[i][j]){
        		valido = 0;
         	}
         	j++;
      	}
      	i++;
		j=0;
   }

   return valido;
}