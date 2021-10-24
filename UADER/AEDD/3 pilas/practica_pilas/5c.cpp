#include <iostream>
using namespace std;

struct nodo_pila{ //creo un tipo de dato
    int dato;
    struct nodo_pila* link;
};
typedef struct nodo_pila nPila; //asigno un "alias" a nuestro identificador del tipo de dato

int pila_obtener(nPila* &pila);
bool pila_vacia(nPila* pila);
void pila_agregar(nPila* &pila, int nuevo_dato);
int dec2bin(int nro);
int base2(int n);

int main(){
    cout << dec2bin(0);
    return 0;
}

void pila_agregar(nPila* &pila, int nuevo_dato){
    nPila* aux = new nPila; //creo nuevo nodo dinamico
    aux->dato = nuevo_dato; // *(aux).dato = nuevo_dato
    aux->link = pila; //asigno a lo que antes valia pila
    pila = aux; //pila apunta al nuevo nodo
}

bool pila_vacia(nPila* pila){
    //return pila == NULL
    if(pila == NULL)
        return true;
    else
        return false;
}

int pila_obtener(nPila* &pila){
    int dato = pila->dato;
    nPila* aux = pila;
    pila = pila->link;
    delete aux;
    return dato;
}

int dec2bin(int nro){
	nPila* pila=NULL;
	int bin=0;
	pila_agregar(pila, base2(nro));
	while(pila_vacia(pila) == false){
 		bin=bin*10;
 		bin=bin+pila_obtener(pila);
	}
	return bin;
}

int base2(int n){
    if (n!=0){
        base2(n/2);
        return n%2;
    }
    return 0;
}
