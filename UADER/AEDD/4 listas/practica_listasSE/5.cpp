#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct nodo_listase{
    int dato;
    struct nodo_listase* link;
};
typedef struct nodo_listase NListaSE;

void listase_generar(NListaSE* &listase, int _cant, int _min, int _max){
    srand(time(NULL));
    for(int i=0; i<_cant; i++){
		int ndato = _min + rand()%(_max+1 - _min);
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

int main(){
    NListaSE* L = NULL;
    int cant = 20;
    int min = 0;
    int max = 28;
	listase_generar(L, cant, min, max);
	listase_mostrar(L);
    cout << "MIN/MAX\t" << listase_minimo(L) << "/" << listase_maximo(L) << endl;
    return 0;
}