#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"
typedef struct arbol{
	int totalIzq;
    Nodo *raiz;
    int totalDer;
}Arbol;

Arbol* crearArbol(){
	Arbol *aux=(Arbol*)malloc(sizeof(Arbol));
    aux->totalIzq=0;
    aux->totalDer=0;
    aux->raiz=NULL;
    return aux;
}

int estaVacioElArbol(Arbol *a){
	if(a->raiz==NULL){
		return 1;
	}else{
		return 0;
	}
}



void preorden(Nodo *n){
	if(n!=NULL){
		printf(" %d ",n->dato);//1
		preorden(n->izq);//2
		preorden(n->der);//3
	}
}

void enorden(Nodo *n){
	if(n!=NULL){		
		enorden(n->izq);//1
		printf(" %d FE=%d \n",n->dato, n->factorEQ);//2
		enorden(n->der);//3
	}
}

void postorden(Nodo *n){
	if(n!=NULL){		
		postorden(n->izq);//1		
		postorden(n->der);//2
		printf("%d\n",n->dato);//3
	}
}

void imprimirPostorden(Arbol *a){
	if(!estaVacioElArbol(a)){
		postorden(a->raiz);
	}
}

void imprimirPreorden(Arbol *a){
	if(!estaVacioElArbol(a)){
		preorden(a->raiz);
	}
}

void imprimirEnorden(Arbol *a){
	if(!estaVacioElArbol(a)){
		enorden(a->raiz);
	}
}

Nodo* buscarNodo (Arbol *a,int valor){
	Nodo *aux=NULL;
    if(!estaVacioElArbol(a)){
		aux=a->raiz;
        while(aux!=NULL && aux->dato!=valor){   
			if(valor < aux->dato){
				aux=aux->izq;
            }else{
                aux=aux->der;
            }
        }  
    }
    return aux;
}

Nodo * hijoNoNullDelNodo(Nodo *nodo){
	if(nodo->izq!=NULL){
		return nodo->izq;
	}else{
		return nodo->der;
	}
}



int alturaNodo(Nodo *n){
	if(n!=NULL){
		int hi=alturaNodo(n->izq);
		int hd=alturaNodo(n->der);
		if(hi>hd){
			return hi+1;
		}else{
			return hd + 1;
		}	
	}else{
		return 0;
	}
}

int factorEquilibrio(Nodo *nodo){
	return alturaNodo(nodo->der) - alturaNodo(nodo->izq);
}

void rotacionIzquierda(Arbol *a,Nodo *n){
	Nodo *aux,*p,*q;
	aux=n->der;
	q=aux->izq;
	p=n->padre;
	
	n->der=q;
	aux->izq=n;
	
	if(q!=NULL){
		q->padre=n;
	}
	n->padre=aux;
	if(p==NULL){ //la raiz del arbol
		a->raiz=aux;
	}else{
		aux->padre=p;
		if(aux->dato > p->dato){
			p->der=aux;
		}else{
			p->izq=aux;
		}
	}	
	aux->factorEQ=factorEquilibrio(aux);
	n->factorEQ=factorEquilibrio(n);
}

void rotacionDerecha(Arbol *a,Nodo *n){
	Nodo *aux,*p,*q;
	aux=n->izq;
	q=aux->der;
	p=n->padre;
	
	n->izq=q;
	aux->der=n;
	
	if(q!=NULL){
		q->padre=n;
	}
	n->padre=aux;
	if(p==NULL){ //la raiz del arbol
		a->raiz=aux;
	}else{
		aux->padre=p;
		if(aux->dato > p->dato){
			p->der=aux;
		}else{
			p->izq=aux;
		}
	}	
	aux->factorEQ=factorEquilibrio(aux);
	n->factorEQ=factorEquilibrio(n);
}

void rotacionDobleIzquierda(Arbol *a, Nodo *n){	
	rotacionDerecha(a,n->der);
	rotacionIzquierda(a,n);
}

void rotacionDobleDerecha(Arbol *a, Nodo *n){	
	rotacionIzquierda(a,n->izq);
	rotacionDerecha(a,n);
	
}

void balancear(Arbol *a, Nodo *p){
	Nodo *padre;
	if(p!=NULL){
		padre=p->padre;
		p->factorEQ=factorEquilibrio(p);
		if(p->factorEQ>1){ //desbalanceo derecho
			if(factorEquilibrio(p->der)<0){
				rotacionDobleIzquierda(a,p);
			}else{
				rotacionIzquierda(a,p);
			}			
		}else if(p->factorEQ<-1){ //desbalanceo izquierda
			if(factorEquilibrio(p->izq)>0){
				rotacionDobleDerecha(a,p);
			}else{
				rotacionDerecha(a,p);
			}
		}
		balancear(a,padre);
	}
}


void insertarNodo(Arbol *a,Nodo *n){
	Nodo *aux,*ant;
	if(estaVacioElArbol(a)){
		a->raiz=n;		
	}else{
		aux=a->raiz;
		while(aux!=NULL){
			ant=aux;
			if(n->dato > aux ->dato){
				aux=aux->der;
			}else{
				aux=aux->izq;
			}
		}
		n->padre=ant;
		if(n->dato > ant->dato){
			ant->der=n;			
		}else{
			ant->izq=n;			
		}
		balancear(a,ant);		
	}
}

void eliminarNodo(Arbol *a, int valor){
	Nodo *aux=buscarNodo(a,valor);
	Nodo *aux2;
	Nodo *padre;
	if(aux!= NULL){
		padre=aux->padre;
		if(aux->izq == NULL && aux->der==NULL){ //caso 1
			if (padre!=NULL){//no es la raiz
				if  ( aux->dato  < padre->dato){
					padre->izq=NULL;
				}else{
					padre->der=NULL;
				}
			}else{ 
				a->raiz=NULL;
		    }
            free (aux);
		}else if(aux->der==NULL || aux->izq==NULL){//caso 2 
			if (padre!=NULL){//no es la raiz
				if  ( aux->dato  < padre->dato){
					padre->izq=hijoNoNullDelNodo(aux);
					padre->izq->padre=padre;
				}else{
					padre->der=hijoNoNullDelNodo(aux);
					padre->der->padre=padre;
				}
			}else{ 
				a->raiz=hijoNoNullDelNodo(aux);
		    }
		    free (aux);
		}else{//caso 3
			aux2=aux->izq;			
			while(aux2->der !=NULL){
				aux2=aux2->der;
			}
			padre=aux2->padre;						
			if  ( aux2->dato  < padre->dato){
				padre->izq=aux2->izq;				
			}else{
				padre->der=aux2->izq;				
			}
			aux2->izq->padre=padre;
			aux->dato=aux2->dato;			
			free(aux2);
		}	
		balancear(a,padre);	
	}
}
