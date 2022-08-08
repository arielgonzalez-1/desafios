#include <iostream>
#define MAX 10
using namespace std;

struct NPilaE{
    int tamanio;
    int dato[MAX];
    int tope;
};

void inicializar(NPilaE &pila, int maximo=MAX){
	pila.tamanio = maximo;
    pila.tope = 0;	
}

bool vacia(NPilaE pila){
    return pila.tope != 0;
}

void alta(NPilaE &pila, int ndato){ //agregar
    if(pila.tope < pila.tamanio){
    pila.dato[pila.tope] = ndato;
    pila.tope += 1;
	}
}

int baja(NPilaE &pila){ //obtener
    int dato=0;
    if(!vacia(pila)){
        pila.tope -= 1;
        dato = pila.dato[pila.tope];
    }
    return dato;
}

int main(){	
	NPilaE pila;
    inicializar(pila);
    
	return 0;
}