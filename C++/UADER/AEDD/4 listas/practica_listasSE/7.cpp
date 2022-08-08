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

double listase_avg(NListaSE* listase){
    int cont = 0;
    int acum = 0;
	while (listase != NULL){
        cont += 1;
        acum += listase->dato;
		listase = listase->link;
	}
    if(cont != 0)
        return double(acum) / double(cont);
    else
        return 0;
}

void listase_mostrar(NListaSE* listase, double _avg){
    cout << "Lista Simplemente Enlazada:\n\nL -> ";
    while(listase != NULL){
        if(listase->dato > _avg)
            cout << listase->dato << " -> ";
        listase = listase->link;
    }
    cout << "NULL\n\n\n";
}

int main(){
    NListaSE* L = NULL;
    int v[] = {9, 1, 3, 2, 8, 7, 6};
	int tam = sizeof(v)/sizeof(int);
	listase_agregar_final(L, v, tam);
	double avg = listase_avg(L);
    cout << "AVG\t" << avg << endl;
    listase_mostrar(L, avg);
    return 0;
}