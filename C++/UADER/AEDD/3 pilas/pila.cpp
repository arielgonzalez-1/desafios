#include <iostream>
using namespace std;

struct nodo_pila{
    int dato;
    struct nodo_pila* link;
};
typedef struct nodo_pila nPila;

bool vacia(nPila* pila){
    return pila == NULL;
}

void alta(nPila* &pila, int nuevo_dato){ //agregar
    nPila* aux = new nPila;
    aux->dato = nuevo_dato;
    aux->link = pila;
    pila = aux;
}

int baja(nPila* &pila){ //obtener
    int dato = pila->dato;
    nPila* aux = pila;
    pila = pila->link;
    delete aux;
    return dato;
}

int main(){
    nPila* pila = NULL;
    
    return 0;
}
