/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"
#include "minimaxAlum.h"



/*tNodo *PSEUDOminimax(tNodo *t) {
     int mejorJugada = -1;
     int puntos = -2;
     int i, temp;
     tNodo *intento=malloc(sizeof(tNodo));
     printf("\n Mi turno: \n");
     for(i = 0; i < 9; ++i){
      if (esValida(t,i)) {
            intento=aplicaJugada(t,1,i); //Intenta jugada
            temp =terminal(intento); // Calcula el valor minimax
            if(temp > puntos) {
              puntos = temp;
              mejorJugada = i;
            }
      }}//for
      t=aplicaJugada(t,1,mejorJugada);
      return t;
}*/

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}


tNodo *minimax(tNodo *t, int jugador)
{
      int max=-10000, max_actual, jugada, mejorjugada;
      tNodo *intento=malloc(sizeof(tNodo));

      for (jugada=0;jugada<N;jugada++)
      {
            if(esValida(t,jugada))
            {
                  intento = aplicaJugada(t,jugador,jugada);
                  max_actual = valormin(intento);
                  if(max_actual > max)
                  {
                        max=max_actual;
                        mejorjugada=jugada;
                  }
            }
      }

      t=aplicaJugada(t,jugador,mejorjugada);
      return t;
}

int valormin(tNodo *t)
{
      int valor_min, jugada, jugador=-1;

      if (terminal(t) || t->vacias==0)
            valor_min = terminal(t);
      else{
            valor_min=100000;
            for(jugada=0;jugada<N;jugada++)
            {
                  if(esValida(t,jugada))
                        valor_min=min(valor_min,valormax(aplicaJugada(t,jugador,jugada)));
            }
      }

      return valor_min;
}

int valormax(tNodo *t)
{
      int valor_max,jugada,jugador=1;

      if(terminal(t) || t->vacias==0)
            valor_max = terminal(t);
      else{
            valor_max=-100000;
            for(jugada=0;jugada<N;jugada++)
            {
                  if(esValida(t,jugada))
                        valor_max = max(valor_max,valormin(aplicaJugada(t,jugador,jugada)));
            }
      }

      return valor_max;
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