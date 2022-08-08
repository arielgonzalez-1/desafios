#include <iostream>
#define MAX 10
using namespace std;

struct cola_circular{
    int cola[MAX];
    int tamanio; //limite maximo de elementos
    int frente; //posicion donde se insertan elementos
    int fondo; //posicion donde se extraen elementos
    bool llena; //si fondo alcanza a frente cola.llena = true
    bool vacia; //si frente alcanza a fondo cola.vacia = true
    int cantidad_elementos;
};
typedef struct cola_circular ColaCircular;

void inicializar(ColaCircular &cc, int maximo=MAX) {
    cc.tamanio = maximo;
    cc.frente = 0;
    cc.fondo = 0;
    cc.vacia = true;
    cc.llena = false;
    cc.cantidad_elementos = 0;
}

int alta(ColaCircular &cc, int ndato){ //agregar
    if(cc.llena)
        return -10;
    cc.vacia = false;
    cc.cola[cc.fondo] = ndato;
    cc.cantidad_elementos += 1;
    if(cc.fondo == cc.tamanio -1)
        cc.fondo = 0;
    else
        cc.fondo += 1;
    if(cc.fondo == cc.frente)
        cc.llena = true;
    return 0;
}

int baja(ColaCircular &cc,int &dato){ //obtener
    if(cc.vacia)
        return -10;
    cc.llena = false;
    dato = cc.cola[cc.frente];
    cc.cantidad_elementos -= 1;
    if(cc.frente == cc.tamanio -1)
        cc.frente = 0;
    else
        cc.frente += 1;
    if(cc.frente == cc.fondo)
        cc.vacia = true;
    return 0;

}

int main(){
    ColaCircular cc;
    inicializar(cc);
    return 0;
}