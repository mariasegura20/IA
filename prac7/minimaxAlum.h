/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

//tNodo *jugadaAdversario(tNodo *t)
//t: nodo que contiene el tablero
//Funcion que devuelve la jugada del adversario 
//devuelve: nodo que contiene el tablero con la jugada realizada
tNodo *jugadaAdversario(tNodo *t);

//tNodo *PSEUDOminimax(tNodo *Nodo)
//t: nodo que contiene el tablero
//Funcion que calcula la mejor jugada
//devuelve: no que contiene el tablero con la jugada implementada
tNodo *PSEUDOminimax(tNodo *Nodo);

tNodo *minimax(tNodo *t, int jugador);
int valormin(tNodo *t);
int valormax(tNodo *t);
int min (int a, int b);
int max (int a, int b);