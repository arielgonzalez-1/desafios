#include <iostream>
using namespace std;

struct nodo_cola{
    int dato;
    struct nodo_cola * link;
};
typedef struct nodo_cola NCola;

bool vacia(NCola * frente) {
    return frente == NULL;
}

 void alta(NCola* & frente, NCola* &fondo, int ndato){ //agregar
    NCola* nuevo;  
    nuevo = (NCola*) new(NCola);
    nuevo->dato = ndato;
    nuevo->link = NULL;
    if(vacia(frente))
        frente = nuevo;
    else
        fondo->link = nuevo;
    fondo = nuevo;
}

int baja(NCola * & frente, NCola * &fondo){ //obtener
    if(! vacia(frente)){
        NCola *aux = frente;
        int ndato = aux->dato;
        frente = frente->link;
        delete aux;
        if(vacia(frente))
            fondo = NULL;
        return ndato;
    }else
        return -10; //error
}

int main(){
    NCola * frente = NULL;
    NCola * fondo = NULL;

    return 0;
}
