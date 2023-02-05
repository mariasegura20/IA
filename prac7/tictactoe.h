/*******************************************/
/* 		    tictactoe.h                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define N 3*3

typedef struct tNodo {
        int celdas[N];
        int vacias;
} tNodo;

typedef struct tJugada {
        int pos;  // para enumerar cada una de las posibles jugadas NO SE USA EN MINIMAX
} tJugada;   // POR SIMPLIFICAR NO SE USAR� AQU�, PERO ES NECESARIO EN OTROS JUEGOS

static int tablero_inicial[N] ={0,0,0, 0,0,0, 0,0,0};

// las posiciones ser�n numeradas de 0 a 8 de la siguiente forma:
//0 1 2
//3 4 5
//6 7 8


//tNodo *crearNodo(int celdas[N])
//celdas[N] : vector de N posiciones que crea el tablero
//devuelve: el tablero creado
tNodo *crearNodo(int celdas[N]);

//tNodo *NodoInicial()
//Funcion que llama a la funcion crear nodo para crear el tablero inicial
//Devuelve el tablero inicial
tNodo *NodoInicial();


/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qu� posici�n del tablero pondr� la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada);

//int esValida(tNodo *actual, int jugada)
//Funcion que determina si la jugada a realizar es valida
//actual: tablero actual
//jugada: indica en que posicion del tablero se pondra la marca
//devuelve: 1 si la jugada es valida y 0 si la jugada no se puede realizar
int esValida(tNodo *actual, int jugada);

//int terminal(tNodo *actual, int jugador)
// funcion que determina si un nodo es terminal, ha ganado MAX o MIN
// actual: tablero actual
// jugador: 1 si es Max -1 si es Min
//devuelve:  si ha gando MAX 100, si ha ganado MIN -100, empate 0
// si no es terminal tambi�n devuelve 0
int terminal(tNodo *actual);


//void dispNodo(tNodo *s)
//s: nodo actual a mostrar
//Muestra el nodo correspondiente por pantalla
void dispNodo(tNodo *s);

//int opuesto( int jugador)
//Funcion que cambia el turno del jugador al opuesto
//Jugador: numero correspondiente a cada jugador
// devuelve: jugador 1 o jugador -1
int opuesto( int jugador);

//int lleno(tNodo *s)
//Funcion que comprueba que el tablero esta lleno y
//no puedes colocar ninguna ficha mas
//s: tablero
//devuelve cero si el tablero esta lleno
int lleno(tNodo *s);




