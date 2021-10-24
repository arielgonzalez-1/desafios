//lista simplemente enlazada

#include <iostream>
using namespace std;

struct nodo_lista{
    int dato;
    struct nodo_lista* link;
};
typedef struct nodo_lista nLista;

int lista_obtener(nLista* &lista);
bool lista_vacia(nLista* lista);
void lista_agregar_final(nLista* &lista, int nuevo_dato);

int main(){
    nLista* lista = NULL;

    return 0;
}

void lista_agregar_final (nLista* &lista, int dato){
	nLista* nodo=new nLista;
	nodo->dato=dato;
	nodo->link=NULL;
	if(lista==NULL){
		lista=nodo;
	}else{
		nLista* aux=lista;
		while(aux->link!=NULL){
			aux=aux->link;
		}
		aux->link=nodo;
	}
	nodo->link=lista;
}

bool lista_vacia(nLista* lista){
    return lista == NULL
}

int lista_obtener(nLista* &lista){
    int dato = lista->dato;
    nLista* aux = lista;
    lista = lista->link;
    delete aux;
    return dato;
}
