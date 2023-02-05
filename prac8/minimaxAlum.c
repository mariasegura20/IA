#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"
#include "minimaxAlum.h"

int valormin(tNodo * t);
int valormax(tNodo * t);

tNodo * jugadaAdversario(tNodo * t)
{
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
      
      t = aplicaJugada(t,-1,jugada);
      
      return t;
}


tNodo * minimax(tNodo * t, int jugador)
{
      int max = -100000, max_actual, jugada, mejorjugada;
      tNodo * intento = (tNodo *) malloc (sizeof(tNodo));

      for (jugada = 0 ; jugada < N ; jugada++)
      {
            if(esValida(t,jugada))
            {
                  intento = aplicaJugada(t,jugador,jugada);
                  max_actual = valormin(intento);
                  if(max_actual > max)
                  {
                        max = max_actual;
                        mejorjugada = jugada;
                  }
            }
      }

      t = aplicaJugada(t,jugador,mejorjugada);
      
      return t;
}

int valormin(tNodo * t)
{
      int valor_min, jugada, jugador=-1;

      if (terminal(t) || t->vacias==0)
            valor_min = terminal(t);
      else{
            if (t->profundidad == LIMITE)
                  valor_min=heuristica(t);
            else{
                  valor_min=100000;
                  for(jugada=0;jugada<N;jugada++)
                  {
                        if(esValida(t,jugada))
                              valor_min=min(valor_min,valormax(aplicaJugada(t,jugador,jugada)));
                  }
            }
      }

      return valor_min;
}

int valormax(tNodo * t)
{
      int valor_max,jugada,jugador=1;

      if(terminal(t) || t->vacias==0)
            valor_max = terminal(t);
      else if (t->profundidad == LIMITE){
            valor_max = heuristica(t);
      }
      else {
            valor_max = -100000;
            for(jugada = 0 ; jugada < N ; jugada++)
            {
                  if(esValida(t,jugada))
                        valor_max = max(valor_max,valormin(aplicaJugada(t,jugador,jugada)));
            }
      }

      return valor_max;
}