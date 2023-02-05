#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"
#include "poda.h"

int valorMin_ab(tNodo * t, int prof, int alfa, int beta);
int valorMax_ab(tNodo * t, int prof, int alfa, int beta);

tNodo * poda_ab(tNodo * t)
{
      int alfa=-100000, beta=100000;
      int max_actual, jugada = 0, mejorJugada = 0, prof = 0, v;
      tNodo * intento = (tNodo *) malloc (sizeof(tNodo));

      while (jugada < N) 
      {
            if (esValida(t, jugada))
            {
                  intento = aplicaJugada(t, MAX, jugada);
                  v = valorMin_ab(intento, prof+1, alfa, beta);
                  if (v > alfa){
                        alfa = v;
                        mejorJugada = jugada;
                  }
            }
            
            jugada++;
      }
      
      t = aplicaJugada(t,MAX,mejorJugada);

      return t;
}

int valorMin_ab(tNodo * t, int prof, int alfa, int beta)
{
      int vmin, jugada=0;
      tNodo * intento = (tNodo *) malloc (sizeof(tNodo));

      if (terminal(t) || lleno(t))
            vmin = terminal(t);
      else{
            if (prof == LIMITE)
                  vmin = heuristica(t);
            else{
                  while (jugada < N && alfa < beta){
                        if (esValida(t, jugada)){
                              intento = aplicaJugada(t, MIN, jugada);
                              beta = min(beta, valorMax_ab(intento,prof+1, alfa, beta));
                        }

                        jugada++;
                  }

                  vmin = beta;
            }
      }

      return vmin;
}

int valorMax_ab(tNodo * t, int prof, int alfa, int beta)
{
      int vmax, jugada=0;
      tNodo *intento=malloc(sizeof(tNodo));

      if (terminal(t) || lleno(t))
            vmax = terminal(t);
      else{
            if (prof == LIMITE)
                  vmax = heuristica(t);
            else{
                  while (jugada < N && alfa < beta){
                        if (esValida(t, jugada)){
                              intento=aplicaJugada(t, MAX, jugada);
                              alfa=max(alfa, valorMin_ab(intento,prof+1, alfa, beta));
                        }

                        jugada++;
                  }

                  vmax = alfa;
            }
      }

      return vmax;
}