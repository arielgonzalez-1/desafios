#include <iostream>
using namespace std;

struct nodo_pila{
    int dato;
    struct nodo_pila* link;
};
typedef struct nodo_pila nPila;

bool is_capicua(int n);
int pila_obtener(nPila* &pila);
bool pila_vacia(nPila* pila);
void pila_agregar(nPila* &pila, int nuevo_dato);

int main(){
    cout << is_capicua(5321235);
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

int  pila_obtener(nPila* &pila){
    int dato = pila->dato;
    nPila* aux = pila;
    pila = pila->link;
    delete aux;
    return dato;
}

bool is_capicua(int n){
    nPila* pila = NULL;
    bool capicua = true;
    int num = n;
    while(num > 0){
        pila_agregar(pila, num%10);
        num /= 10;
    }
    num = n; 
    while(num > 0){
        if(num%10 != pila_obtener(pila))
            capicua = false;
        num /= 10;
    }
    return capicua;
}
