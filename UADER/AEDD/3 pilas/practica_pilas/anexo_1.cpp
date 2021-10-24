/*
Se sabe que en una pila implementada dinamicamente (con celdas), se almacenaron alrededor de 50 valores numericos. El punto de acceso de dicha pila se denomina PUNT. Desarrollar un algoritmo que informe la cantidad de celdas en la pila y la sumatoria de los valores numericos.
*/

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

int main(){
    nPila* pila = NULL;
    int sumatoria = 0;
    int celdas = 0;
    for(int i=1; i<=50; i++){
        pila_agregar(pila, i);
    }

    while(pila != NULL){
        celdas += 1;
        sumatoria += pila_obtener(pila);
    }

    cout << "SUM/CELDAS\t" << sumatoria << "/" << celdas << endl;
    return 0;
}

void pila_agregar(nPila* &pila, int nuevo_dato){
    nPila* aux = new nPila; //creo nuevo nodo dinamico
    aux->dato = nuevo_dato; // *(aux).dato = nuevo_dato
    aux->link = pila; //asigno a lo que antes valia pila
    pila = aux; //pila apunta al nuevo nodo
}

bool pila_vacia(nPila* pila){
    return pila == NULL;
}

int pila_obtener(nPila* &pila){
    int dato = pila->dato;
    nPila* aux = pila;
    pila = pila->link;
    delete aux;
    return dato;
}
