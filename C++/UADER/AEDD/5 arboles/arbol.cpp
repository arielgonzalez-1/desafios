#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

using namespace std;

struct nodo_arbol_binario{
	int dato;
	struct nodo_arbol_binario* iz;
	struct nodo_arbol_binario* de;
};
typedef struct nodo_arbol_binario NABinario;

// "tope" se corresponde con la posici�n donde realizar� la pr�xima inserci�n.
// Cuando la pila esta vacia tope = 0.
struct pila_estatica{
	NABinario* dato[MAX];
	int tamanio;
	int tope;
};
typedef struct pila_estatica PilaE;

bool pila_vacia (PilaE);
void pila_agregar (PilaE &, NABinario*);
NABinario* pila_sacar (PilaE &);
void menu_opcion1 (NABinario* arbol);
void menu_opcion2 (NABinario* &arbol);
void menu_opcion3 (NABinario* arbol);
void menu_opcion4 (NABinario* arbol);
void abinario_mostrar_recursivo (NABinario* arbol, int tabulado = 0);
void abinariob_alta_recursivo (NABinario* &arbol, int nuevo_dato);
void abinario_preorden_recursivo (NABinario* arbol);
void abinario_preorden_iterativo (NABinario* arbol);
void abinario_mostrar_recursivo2(NABinario* arbol, int n=0);

int main (void){
	NABinario* arbol = NULL;
	int opcion = 0;
	do {
		cout << "************Menu de Opciones************\n";
		cout << endl;
		cout << "****** Lista Simplemente Enlazada ******\n";
		cout << endl;
		cout << "1- Mostrar.\n";
		cout << "2- Insertar N elementos.\n";
		cout << "3- Preorden recursivo.\n";
		cout << "4- Preorden iterativo.\n";
		cout << endl;
		cout << "    0- Salir\n";
		cout << endl;
		cout << "                        Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		cout << endl;
		
		switch(opcion)
		{
		case 1:
			menu_opcion1 (arbol);
			break;
		case 2:
			menu_opcion2 (arbol);
			break;
		case 3:
			menu_opcion3 (arbol);
			break;
		case 4:
			menu_opcion4 (arbol);
			break;
		}
	} while ( opcion != 0);
	
	return 0;
}


void menu_opcion1 (NABinario* arbol){
	cout << "Arbol:" << endl << endl;
//	abinario_mostrar_recursivo (arbol);
	abinario_mostrar_recursivo2 (arbol);
	cout << endl << endl << endl;
}

void menu_opcion2 (NABinario* &arbol){
	int nuevo_dato, cantidad;
	cout << "Cuantos datos aleatorios desea cargar?: ";
	cin >> cantidad;
	cout << endl;
	cout << "Lista de datos cargados:\n";
	cout << endl;
	for (int i=0; i<cantidad; i++){
		nuevo_dato = (rand () % 100) + 1;
		abinariob_alta_recursivo (arbol, nuevo_dato);
		cout << nuevo_dato << "  ";
	}
	cout << endl << endl << endl;
}

void menu_opcion3 (NABinario* arbol){
	cout << "Recorrido en PRE-Orden Recursivo:" << endl << endl;
	abinario_preorden_recursivo (arbol);
	cout << endl << endl << endl;
}

void menu_opcion4 (NABinario* arbol)
{
	cout << "Recorrido en PRE-Orden Iterativo:" << endl << endl;
	abinario_preorden_iterativo (arbol);
	cout << endl << endl << endl;
}

bool pila_vacia (PilaE pila)
{
// Agregue aqui su codigo
	return false;
}

void pila_agregar (PilaE &pila, NABinario* nodo)
{
	// Agregue aqui su codigo
}

NABinario* pila_sacar (PilaE &pila)
{
	// Agregue aqui su codigo
	return NULL;
}

void abinario_mostrar_recursivo (NABinario* arbol, int tabulado){
	if (arbol != NULL){
		cout << string (tabulado, '\t');
		cout << "Nodo: " << arbol->dato << " | " << "Iz-> ";
		if (arbol->iz != NULL)
			cout << arbol->iz->dato;
		else
			cout << "NULL";
		cout << "  " << "De-> ";
		if (arbol->de != NULL)
			cout << arbol->de->dato;
		else
			cout << "NULL";
		cout << endl;
		tabulado++;
		abinario_mostrar_recursivo (arbol->iz, tabulado);
		abinario_mostrar_recursivo (arbol->de, tabulado);
	}
}

void abinario_mostrar_recursivo2 (NABinario* arbol, int n){
	if (arbol == NULL)
		return;
	abinario_mostrar_recursivo2 (arbol->de, n+1);
	cout << string (n, '\t') << arbol->dato << endl;
	abinario_mostrar_recursivo2(arbol->iz, n+1);
}

void abinariob_alta_recursivo (NABinario* &arbol, int nuevo_dato){
	if (arbol == NULL){
		arbol = new (NABinario);
		arbol->iz = NULL; arbol->de = NULL;
		arbol->dato = nuevo_dato;
	}else if (nuevo_dato < arbol->dato)
		abinariob_alta_recursivo (arbol->iz, nuevo_dato);
	else if (nuevo_dato > arbol->dato)
		abinariob_alta_recursivo (arbol->de, nuevo_dato);
}

void abinario_preorden_recursivo (NABinario* arbol){
	if (arbol != NULL){
		cout << arbol->dato << "  ";
		abinario_preorden_recursivo (arbol->iz);
		abinario_preorden_recursivo (arbol->de);
	}
}

void abinario_preorden_iterativo (NABinario* arbol){
	NABinario* aux;
	PilaE pila; pila.tamanio = MAX; pila.tope = 0;
	if (arbol != NULL)
		pila_agregar (pila, arbol);
	while (!pila_vacia (pila)){
		aux = pila_sacar (pila);
		cout << aux->dato << "  ";
		if (aux->de != NULL)
			pila_agregar (pila, aux->de);
		if (aux->iz != NULL)
			pila_agregar (pila, aux->iz);
	}
}
