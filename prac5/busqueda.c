#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaia.h"
#include "busqueda.h"

// VISUALIZACION DE LA SOLUCION

void solucionFin(int res)
{
   printf("\nFin de la busqueda\n");
    if (res)
      printf("Se ha llegado al objetivo\n");
   else
      printf("No se ha llegado al objetivo\n");
}

void dispNodo(tNodo *nodo)
{
    dispEstado(nodo->estado);
    printf("\n");
}

void dispCamino(tNodo *nodo)
{
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
         dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo)
{
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}

// FUNCIONES DE NODOS

tNodo *nodoInicial()
{
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}

LISTA expandir(tNodo *nodo)
{
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;

    for (op=1; op<=NUM_OPERADORES;op++)
    {
      if (esValido(op,nodo->estado)){
          s=aplicaOperador(op,nodo->estado);
          nuevo->estado=s;
          nuevo->padre=nodo;
          nuevo->operador=op;
          nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
          nuevo->profundidad=nodo->profundidad+1;
          nuevo->valHeuristica=heuristica(s);
          InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
        }
    }
    return sucesores;
}

// ALGORITMOS DE BUSQUEDA NO INFORMADA

int busqueda_anchura(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Abiertos,Sucesores);
        }
        visitados++;
   }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busqueda_profundidad(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Sucesores,Abiertos);
        }
        visitados++;
   }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int buscaRepe(tNodo * actual, LISTA cerrados)
{
    LISTA aux = cerrados;
    int rep=0;
    while (aux != VACIA && rep == 0)
    {   
        tNodo *a=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(aux, a, sizeof(tNodo));
        if (iguales(actual->estado, a->estado))
        {
            rep = 1;
        }
        aux = aux->next;

    }

    return rep;
}

int busqueda_anchura_estado_repetido(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados= VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo && !buscaRepe(Actual, Cerrados)){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Abiertos,Sucesores);
            InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
        }
        visitados++;
   }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busqueda_profundidad_estado_repetido(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados= VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo && !buscaRepe(Actual, Cerrados)){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Sucesores,Abiertos);
            InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
        }
        visitados++;
   }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busqueda_profundidad_limitada(int lim){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo && Actual->profundidad < lim){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Sucesores,Abiertos);
            InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
        }
        visitados++;
    }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busqueda_profundidad_limitada_iterativa(){
    int lim=0;
    
    while (!busqueda_profundidad_limitada(lim))
    {
        lim++;
    }
}

// ALGORITMOS DE BUSQUEDA INFORMADA

int comparaV (tNodo *e, tNodo *nuevo){
    return (e->valHeuristica < nuevo->valHeuristica);
}
int comparaA (tNodo *e, tNodo *nuevo){
    return (e->valHeuristica + e->costeCamino < nuevo->valHeuristica + nuevo->costeCamino);
}

int (*menor[])(tNodo *, tNodo*)={comparaV, comparaA};

LISTA insertarOrdenado(LISTA c, tNodo *n, int tipo)
{
    LISTA res=VACIA;
    tNodo *naux=calloc(1,sizeof(tNodo));

    if (esVacia(c))
        InsertarUltimo(&res,(tNodo*) n,sizeof(tNodo));
    else{
        ExtraerPrimero(c,naux,sizeof(tNodo));
        while ((menor[tipo](naux,n)) && (c!=NULL))
        {
            InsertarUltimo(&res,(tNodo*) naux,sizeof(tNodo));
            c=c->next;
            if (!(esVacia(c)))
                ExtraerPrimero(c,naux,sizeof(tNodo));
        }
        InsertarUltimo(&res,(tNodo*) n,sizeof(tNodo));
        if (!esVacia(c))
            res=Concatenar(res,c);
    }
    return res;
}

LISTA ordenarLista(LISTA Ab, LISTA q, int tipo)
{
    tNodo *n=calloc(1,sizeof(tNodo));
    while (!esVacia(q))
    {
        ExtraerPrimero(q,n,sizeof(tNodo));
        Ab=insertarOrdenado(Ab,n,tipo);
        q=q->next;
    }
    return(Ab);
}

int heuristica (tEstado *e)
{
    int h=0;
    tEstado * objetivo = (tEstado *) malloc (sizeof(tEstado));
    objetivo = estadoObjetivo();

    for (int i = 0 ; i < 2 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            if (e->celdas[i][j] != objetivo->celdas[i][j] && e->celdas[i][j] != 0)
                h++;
        }
    }

    return h;
}

int busqueda_voraz ()
{
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc (1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);

        if (!objetivo && !buscaRepe(Actual,Cerrados)) {
            Sucesores = expandir(Actual);
            Abiertos=ordenarLista(Abiertos,Sucesores,0);
            InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
        }
        visitados++;
    };

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busqueda_a()
{
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc (1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);

        if (!objetivo && !buscaRepe(Actual,Cerrados)) {
            Sucesores = expandir(Actual);
            Abiertos=ordenarLista(Abiertos,Sucesores,1);
            InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
        }
        visitados++;
    };

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}