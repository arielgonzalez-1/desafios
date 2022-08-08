//solucion de Roxana
#include <iostream>
#include <iomanip>
#include <cstdlib>

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

void listase_agregar_final (NListaSE* &listase, int _dato){
    NListaSE* aux_lse = listase;
    NListaSE* nuevo_nodo = new (NListaSE);
    nuevo_nodo->dato = _dato;
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
		cout << "error, posicion invalida\n";
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

int main (){
	NListaSE* listase = NULL;
    int num, pos;
    listase_agregar_final(listase, 9);
    listase_agregar_final(listase, 1);
    listase_mostrar(listase);
    do{
        cout << "Ingrese numero y posicion respectivamente\n";
        cin >> num >> pos;
        listase_agregar_posicion(listase, num, pos);
        cout << "Nuevo=" << num << " y pos=" << pos << endl;
        listase_mostrar(listase);

    }while(pos != -1);
	return 0;	
}