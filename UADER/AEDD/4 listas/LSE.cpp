//agregar método para ordenar una lista
//agregar typedef int DATO //corregir tipo de dato

#include <iostream>
using namespace std;

struct nodo_listase{
	int dato;
	struct nodo_listase* link;
};
typedef struct nodo_listase NListaSE;

int contador_nodos(NListaSE* listase){
    int cant_nodos = 0;
	while (listase != NULL){
        cant_nodos += 1;
		listase = listase->link;
    }
    return cant_nodos;
}

void listase_mostrar (NListaSE* listase){
	cout << "Lista Simplemente Enlazada:\n\nL -> ";
	while (listase != NULL){
		cout << listase->dato << " -> ";
		listase = listase->link;
	}
	cout << "NULL\n\n\n";
}

void listase_agregar_final (NListaSE* &listase, int ndato){
	NListaSE* aux_lse = listase;
	NListaSE* nuevo_nodo = new (NListaSE);
	nuevo_nodo->dato = ndato;
	nuevo_nodo->link = NULL;
	if (aux_lse == NULL)
		listase = nuevo_nodo;
	else{
		while (aux_lse->link != NULL)
			aux_lse = aux_lse->link;
		aux_lse->link = nuevo_nodo;
	}	
}

void listase_agregar_posicion (NListaSE* &listase, int _dato, int _pos){
	NListaSE* aux1 = listase;
	NListaSE* aux2= aux1->link;
	NListaSE* nuevo_nodo = new (NListaSE);
	nuevo_nodo->dato = _dato;
	int cont_pos = 1;
	if (_pos < 1 or _pos > contador_nodos(listase)+1){
		cout << "error, posicion invalida\n\n";
        return;
	}
	while (aux1 != NULL ){
		cont_pos ++;
		if (_pos == 1){
			nuevo_nodo->link=aux1;
			listase = nuevo_nodo;
			aux1 = NULL;
		}else if (cont_pos == _pos){
			nuevo_nodo->link=aux2;
			aux1->link = nuevo_nodo;
			aux1 = NULL;
		}else {
			aux1 = aux1->link;
			aux2 = aux2->link;
		}
	}
}

void listase_agregar_ordenado (NListaSE* &listase, int ndato){
	NListaSE* actual = listase;
	NListaSE* anterior = NULL;
	NListaSE* nuevo_nodo = new (NListaSE);
	nuevo_nodo->dato = ndato;
	while (actual != NULL && actual->dato < ndato){
		anterior = actual;
		actual = actual->link;
	}
	if (anterior == NULL){
		nuevo_nodo->link = listase;
		listase = nuevo_nodo;
	} else{
		nuevo_nodo->link = anterior->link;
		anterior->link = nuevo_nodo;
	}
}

int listase_obtener_ultimo(NListaSE* lista){
	while (lista->link != NULL){
		lista = lista->link;
	}
    int dato = lista->dato;
    return dato;
}

int listase_obtener_primero(NListaSE* lista){
    int dato = lista->dato;
    NListaSE* aux = lista;
    return dato;
}

int listase_obtener_ultimo_destructiva(NListaSE* &lista){ //CUIDADO CORREGIR
	while (lista->link != NULL){
		lista = lista->link;
	}
    int dato = lista->dato;
	NListaSE* aux = lista;
	delete aux;
    return dato;
}

int listase_obtener_primero_destructiva(NListaSE* &lista){
    int dato = lista->dato;
    NListaSE* aux = lista;
    lista = lista->link;
    delete aux;
    return dato;
}

bool listase_eliminar_ocurrencia (NListaSE* &listase, int datoe){
	NListaSE* actual = listase;
	NListaSE* anterior = NULL;
	NListaSE* aux = NULL;
	while ((actual != NULL) and (actual->dato != datoe)){
		anterior = actual;
		actual = actual->link;
	}
	if ((actual != NULL) and (anterior == NULL)){
		aux = actual;
		listase = listase->link;
		free(aux);
		return true;
	}else if ((actual != NULL) and (anterior != NULL)){
		aux = actual;
		anterior->link = actual->link;
		free(aux);
		return true;		
	}
	return false;
}

void listase_eliminar_ocurrencias (NListaSE* &listase, int datoe){
	while(listase_eliminar_ocurrencia(listase, datoe));
}

int main (void){
	NListaSE* L = NULL;
	return 0;
}