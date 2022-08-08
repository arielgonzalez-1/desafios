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

void listase_mostrar (NListaSE* listase){
	cout << "Lista Simplemente Enlazada:\n\nL -> ";
	while (listase != NULL){
		cout << listase->dato << " -> ";
		listase = listase->link;
	}
	cout << "NULL\n";
	cout << endl;
	cout << endl;
}

int listase_minimo (NListaSE* listase){
    int minimo = 9999;
	while (listase != NULL){
        if(listase->dato < minimo)
            minimo = listase->dato;
		listase = listase->link;
	}
    return minimo;
}

int listase_maximo (NListaSE* listase){
    int maximo = -9999;
	while (listase != NULL){
        if(listase->dato > maximo)
            maximo = listase->dato;
		listase = listase->link;
	}
    return maximo;
}

//corregir
int listase_maximo_recursiva(NListaSE* listase){
    int maximo = listase->dato;
	if(listase != NULL){
        if(listase->dato > maximo)
            maximo = listase->dato;
		listase = listase->link;
        return listase_maximo_recursiva(listase);
	}else
        return maximo;
}

int main(){
    NListaSE* L = NULL;
    int v[] = {9, 1, 3, 2, 8, 7, 6};
	int tam = sizeof(v)/sizeof(int);
	listase_agregar_final(L, v, tam);
	listase_mostrar(L);
    cout << "MIN/MAX\t" << listase_minimo(L) << "/" << listase_maximo(L) << endl;
    cout << listase_maximo_recursiva(L) << endl;
    return 0;
}