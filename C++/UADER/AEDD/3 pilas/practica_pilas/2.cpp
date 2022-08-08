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
void pila_cargar(nPila* &pila, int vec[], int dimension);
void pila_decargar(nPila* &pila, int dimension);

int main(){
    nPila* pila = NULL;
    int v[] = {9, 1, 3};
    int dimension = sizeof(v)/sizeof(v[0]);
    pila_cargar(pila, v, dimension);
    pila_decargar(pila, dimension);
    cout << pila_vacia(pila) << endl;
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

void pila_cargar(nPila* &pila, int vec[], int dimension){
    for(int i = 0; i < dimension; i++){
        pila_agregar(pila, vec[i]);
    }
}

void pila_decargar(nPila* &pila, int dimension){
    for(int i = 0; i < dimension; i++){
        cout << pila_obtener(pila) << endl;
    }
}
