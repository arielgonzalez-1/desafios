#include <iostream>
using namespace std;

struct nodo_arbol_binario{
    int dato;
    struct nodo_arbol_binario*iz;
    struct nodo_arbol_binario*de;
};
typedef struct nodo_arbol_binario NABinario;

void abinario_preorden_recursivo (NABinario* arbol){
     if (arbol != NULL){
          cout << arbol->dato << " ";
          abinario_preorden_recursivo (arbol->iz);
          abinario_preorden_recursivo (arbol->de);
     }
}

void abinario_inorden_recursivo(NABinario* arbol){
        if(arbol != NULL){
            abinario_inorden_recursivo(arbol->iz);
            cout << arbol->dato << " ";
            abinario_inorden_recursivo(arbol->de);
        }
}

void abinario_postorden_recursivo(NABinario * arbol){
    if(arbol != NULL){
        abinario_postorden_recursivo(arbol->iz);
        abinario_postorden_recursivo(arbol->de);
        cout << arbol->dato << " ";
    }
}

int abinario_altura_iterativo (NABinario* arbol){
     int a = 1, b = 1;
     if(arbol == NULL) return 0;
     else{
        if (arbol->iz != NULL) a = 1 + abinario_altura_iterativo(arbol->iz);
        if (arbol->de != NULL) b = 1 + abinario_altura_iterativo(arbol->de);
        if (a>=b) return a;
        else return b;
     }
}

int arbol_contarNodos(NABinario* arbol, int cont=0){
    cont++;
    if(arbol->iz!=NULL) cont=arbol_contarNodos(arbol->iz, cont);
    if(arbol->de!=NULL) cont=arbol_contarNodos(arbol->de, cont);
    return cont;
}

int mostrarNodosHoja(NABinario * arbol,int &cont){
    if(arbol!=NULL){
        if(arbol->iz == NULL && arbol->de == NULL){
            cout << arbol->dato << " ";
            cont++;
        }
        mostrarNodosHoja(arbol->iz,cont);
        mostrarNodosHoja(arbol->de,cont);
    }
    return cont;
}

void abinario_mostrar_recursivo2 (NABinario* arbol, int n){
     if (arbol == NULL) return;

     abinario_mostrar_recursivo2 (arbol->de, n+1);
     cout << string (n, '\t') << arbol->dato << endl;
     abinario_mostrar_recursivo2(arbol->iz, n+1);
}

void abinario_alta_recursivo(NABinario*&arbol,int ndato,int &menor,int &mayor){
    if(ndato > mayor ) mayor=ndato;
    if(ndato < menor ) menor=ndato;
    if(arbol == NULL){
        arbol=new NABinario;
        arbol->de=NULL; arbol->iz=NULL;
        arbol->dato=ndato;
        menor=ndato;
    }
    if(ndato < arbol->dato) abinario_alta_recursivo(arbol->iz,ndato,menor,mayor);
    if(ndato > arbol->dato) abinario_alta_recursivo(arbol->de,ndato,menor,mayor);
}

int sumatoria(NABinario * arbol){
    if(arbol != NULL){
        int centro = arbol->dato;
        int izquierda = sumatoria(arbol->iz);
        int derecha = sumatoria(arbol->de);
        return centro+izquierda+derecha;
    }
    return 0;
}

float promedio(NABinario * arbol){
    int cant = sumatoria(arbol);
    int div = arbol_contarNodos(arbol);
    float result =  cant/div;
    return result;
}

void buscar (NABinario * arbol, int n){
    if(arbol == NULL) cout << "\nNodo no encontrado ... \n";
    else if(n == arbol->dato ) cout << "\n Dato encontrado \n";
    else if(n < arbol->dato ) buscar(arbol->iz,n);
    else if(n > arbol->dato ) buscar(arbol->de,n);
}
