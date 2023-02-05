#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"
#include "minimaxAlum.h"
#include "poda.h"

int main(){
   int jugador;
   int sel, primero, ganador;
   tNodo * juego = crearNodo(tablero_inicial);

   printf("Posibles algoritmos a utilizar: \n 1) Minimax \n 2) Poda alfa-beta \nSelección: ");
   scanf("%d", &sel);
   printf("\n");
   
   dispNodo(juego);

   printf("El Agente Inteligente juega con X \nEl Jugador Humano con O \nElige el turno 1:Primero o 2:Segundo ");
   scanf("%d", &primero);
   printf("\n");
   
   if (primero == 1)
      jugador = MIN;
   else
      jugador = MAX;

   ganador = terminal(juego);

   while(!lleno(juego) && ganador == 0)
   {
      if (jugador == MAX)
         switch (sel)
         {
            case 1: juego = minimax(juego, MAX); break;
            case 2: juego = poda_ab(juego); break;
            default: juego = poda_ab(juego); break;
         }
      else
         juego = jugadaAdversario(juego);

      dispNodo(juego);
      ganador = terminal(juego);
      jugador = opuesto(jugador);
   }
   
   switch(ganador)
   {
      case 100: printf("\nHE GANADOOOO\n"); break;
      case 0: printf("\nEMPATE, vaya tienes que practicar mas para poder ganarme ... \n"); break;
      case -100: printf("\nIncreible pero has ganado tu :(( \n"); break;
      default: printf("\nAlgo ha salido mal en el juego...\n");
   }

   system("pause");
   return 0;
}
