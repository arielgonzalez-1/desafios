#include <iostream>
using namespace std;

struct nodo_listase{
    int dato;
    struct nodo_listase* link;
};
typedef struct nodo_listase NListaSE;

void listase_agregar_final (NListaSE* &listase, int *_vec, int _tam){
    for(int i=0; i<_tam; i++){
		int ndato = _vec[i];
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
}

void listase_mostrar(NListaSE* listase){
    cout << "Lista Simplemente Enlazada:\n\nL -> ";
	while (listase != NULL){
        cout << listase->dato << " --> ";
		listase = listase->link;
	}
    cout << "NULL\n";
	cout << endl;
	cout << endl;
}

void listase_doble(NListaSE* listase){
    while (listase != NULL){
        listase->dato = listase->dato*2;
        listase = listase->link;
    }
}

int main(){
    NListaSE* L = NULL;
    int v[] = {4, 1, 3, 5};
	int tam = sizeof(v)/sizeof(int);
	listase_agregar_final(L, v, tam);
    listase_mostrar(L);
    listase_doble(L);
	listase_mostrar(L);
    return 0;
}