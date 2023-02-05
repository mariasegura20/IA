#define MIN -1
#define MAX 1
#define N 3*3
#define LIMITE 4

typedef struct tNodo {
        int celdas[N];
        int vacias;
        int profundidad;
} tNodo;

// Las posiciones serán numeradas de 0 a 8 de la siguiente forma:
// 0 1 2
// 3 4 5
// 6 7 8

static int tablero_inicial[N] ={0,0,0, 0,0,0, 0,0,0};

// tNodo * crearNodo(int celdas[N])
// celdas[N]: Vector de N posiciones que crea el tablero
// devuelve: El tablero creado
tNodo * crearNodo(int celdas[N]);

// tNodo * NodoInicial()
// Función que llama a la función crear nodo para crear el tablero inicial
// Devuelve el tablero inicial
tNodo * estadoInicial();

// tNodo * aplicaJugada(tNodo * t, int jugador, int jugada)
// t: Es el tablero actual
// jugador: La marca del jugador que tiene el turno
// jugada: Indica en qué posición del tablero pondrá la marca
// devuelve: El nuevo Nodo tras aplicar la jugada
tNodo * aplicaJugada(tNodo * t, int jugador, int jugada);

// int esValida(tNodo * t, int jugada)
// Función que determina si la jugada a realizar es valida
// t: tablero actual
// jugada: indica en que posición del tablero se pondra la marca
// devuelve: 1 si la jugada es valida y 0 si la jugada no se puede realizar
int esValida(tNodo * t, int jugada);

// int terminal(tNodo * t, int jugador)
// Función que determina si un nodo es terminal, ha ganado MAX o MIN
// t: tablero actual
// jugador: 1 si es Max -1 si es Min
// devuelve:  si ha gando MAX 100, si ha ganado MIN -100, empate 0
// si no es terminal también devuelve 0
int terminal(tNodo * t);

// int lleno(tNodo * t)
// Función que comprueba que el tablero esta lleno y no puedes colocar ninguna ficha mas
// t: tablero
// devuelve 0 si el tablero esta lleno
int lleno(tNodo * t);

// int opuesto( int jugador)
// Función que cambia el turno del jugador al opuesto
// jugador: numero correspondiente a cada jugador
// devuelve: jugador 1 o jugador -1
int opuesto(int jugador);

// int min (int a, int b)
// a, b: enteros
// devuelve el mínimo entre a y b
int min (int a, int b);

// int max (int a, int b)
// a, b: enteros
// devuelve el máximo entre a y b
int max (int a, int b);

// int heuristica (tNodo * t)
// Función heurística: nº columnas/filas/diagonales que tienen X pero no O -  nº columnas/filas/diagonales que tienen O pero no X
// t: tablero
// devuelve el valor de la heurística
int heuristica (tNodo * t);

// void dispNodo(tNodo * t)
// t: nodo actual a mostrar
// Muestra el nodo correspondiente por pantalla
void dispNodo(tNodo * t);