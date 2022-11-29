#include <stdio.h>
#include "arbol.h"

int main(){
	Arbol *a=crearArbol();		
	insertarNodo(a,crearNodo(100));	
	insertarNodo(a,crearNodo(150));	
	insertarNodo(a,crearNodo(90));	
	insertarNodo(a,crearNodo(160));
	insertarNodo(a,crearNodo(170));
	imprimirEnorden(a);
	eliminarNodo(a,150);
	imprimirEnorden(a);
	eliminarNodo(a,90);
	imprimirEnorden(a);
	return 0;
}

