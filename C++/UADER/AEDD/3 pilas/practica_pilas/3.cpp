#include <iostream>
using namespace std;

struct nodo_pila{
    char dato;
    struct nodo_pila* link;
};
typedef struct nodo_pila nPila;

int cont(char * str);
char pila_obtener(nPila* &pila);
bool pila_vacia(nPila* pila);
void pila_agregar(nPila* &pila, char nuevo_dato);
char *reverse(char *str);


int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = reverse(str);
    cout << aux << endl;
    return 0;
}

int cont(char * str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return ++i;
}

void pila_agregar(nPila* &pila, char nuevo_dato){
    nPila* aux = new nPila; //creo nuevo nodo dinamico
    aux->dato = nuevo_dato; // *(aux).dato = nuevo_dato
    aux->link = pila; //asigno a lo que antes valia pila
    pila = aux; //pila apunta al nuevo nodo
}

bool pila_vacia(nPila* pila){
    return pila == NULL;
}

char pila_obtener(nPila* &pila){
    char dato = pila->dato;
    nPila* aux = pila;
    pila = pila->link;
    delete aux;
    return dato;
}

char *reverse(char *str){
    nPila* pila = NULL;
    int size = cont(str);
    char *aux = new char[size];
    for(int i = 0; i < size; i++){
        pila_agregar(pila, str[i]);
    }
    pila_obtener(pila);
    for(int i = 0; i < size-1; i++){
        aux[i] = pila_obtener(pila);
    }
    aux[size-1] = '\0';
    delete [] str;
    return aux;
}
