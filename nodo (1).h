#include <stdlib.h>
typedef struct nodo{
	struct nodo *izq;
    int hijosIzq;
    struct nodo *padre;
    int dato;
    int hijosDer;
    struct nodo *der; 
    int factorEQ;
}Nodo;

Nodo* crearNodo(int dato){
	Nodo *aux=(Nodo*) malloc(sizeof(Nodo));
    aux->izq=NULL;
    aux->padre=NULL;
    aux->der=NULL;
    aux->hijosIzq=0;
    aux->hijosDer=0;
    aux->dato=dato;
    aux->factorEQ=0;
    return aux;
}
