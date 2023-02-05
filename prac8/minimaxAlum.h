// tNodo * jugadaAdversario(tNodo * t)
// t: nodo que contiene el tablero
// Función que devuelve la jugada del adversario 
// devuelve el nodo que contiene el tablero con la jugada realizada
tNodo *jugadaAdversario(tNodo * t);

// tNodo * minimax(tNodo * t, int jugador)
// Funcion que calcula la mejor jugada
// t: nodo que contiene el tablero
// jugador: Jugador que tiene que hacer la siguiente jugada
// devuelve el número que contiene el tablero con la jugada implementada
tNodo * minimax(tNodo * t, int jugador);