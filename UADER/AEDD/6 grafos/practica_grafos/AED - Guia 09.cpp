#include <iostream>
using namespace std;

//Estructura Nodo Grafo
struct nodo_grafo{
	int id_nodo;
	struct nodo_arco* lista_arco;
	struct nodo_grafo* link;
};
typedef struct nodo_grafo NGrafo;
//Estructura Nodo Arco
struct nodo_arco{
	int id_arco;
	struct nodo_grafo* destino;
	struct nodo_arco* link;
};
typedef struct nodo_arco NArco;
//Funcion Agregar Nodo
void grafo_agregar_nodo (NGrafo* &lista_n, int id_nodo){
	NGrafo* aux = lista_n;
	
	// Verificamos si que no exista ya el id_nodo.
	while (aux != NULL)
	{
		if (aux->id_nodo == id_nodo)
		{
			cout << "!!! Error: Ya existe un nodo con ese id_nodo." << endl;
			return;
		}
		aux = aux->link;
	}
	
	aux = new (NGrafo);
	aux->id_nodo = id_nodo;
	aux->lista_arco = NULL;
	aux->link = lista_n;
	lista_n = aux;
}
	

//Funcion Agregar Arco	
void grafo_agregar_arco (NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino){
	NGrafo* nodo_origen = lista_n;
	NGrafo* nodo_destino = lista_n;
	
	while (nodo_origen != NULL && nodo_origen->id_nodo != id_nodo_origen)
		nodo_origen = nodo_origen->link;
	
	while (nodo_destino != NULL && nodo_destino->id_nodo != id_nodo_destino)
		nodo_destino = nodo_destino->link;
	
	// Verificamos si existen id_nodo_origen y id_nodo_destino.
	if (nodo_origen == NULL || nodo_destino == NULL)
	{
		cout << "!!! Error: Alguno de los nodos no existe." << endl;
		return;
	}
	
	// Verificamos que no exista ya el id_arco.
	// Tarea :) Ponga aqu? su c?digo.
	
	NArco* aux = new (NArco);
	aux->id_arco = id_arco;
	aux->destino = nodo_destino;
	aux->link = nodo_origen->lista_arco;
	nodo_origen->lista_arco = aux;
}	

/* Ejercicio 5 */
//Funcion Cuenta Nodos	
int grafo_cuenta_nodos(NGrafo* lista_n){
	NGrafo* aux = lista_n;
	int cont=0;
	while(aux!=NULL){
		cont++;
		aux=aux->link;
	}
	return cont;
}
	

/* Ejercicio 6 */
//Funcion Cuenta Arcos
int grafo_cuenta_arcos(NGrafo* lista_n){
	NGrafo* aux = lista_n;
	int cont=0;
	while(aux!=NULL){
		NArco* aux2 = aux->lista_arco;
		while(aux2!=NULL){
			cont++;
			aux2=aux2->link;
		}
		aux=aux->link;
	}
	return cont;
}


/* Ejercicio 2 */
//Funcion Eliminar Arco
void grafo_eliminar_arco(NGrafo* &grafo, int id_nodo_origen, int id_nodo_destino){
	NGrafo* aux = grafo;
	while(aux!=NULL){
		if(aux->id_nodo==id_nodo_origen){
			NArco* aux2 = aux->lista_arco;
			NArco* ant = NULL;
			while(aux2!=NULL&&aux2->destino->id_nodo!=id_nodo_destino){
				ant=aux2;
				aux2=aux2->link;
			}
			if(aux2==NULL){
				cout<<"No se ha encontrado el arco "<<id_nodo_origen<<"->"<<id_nodo_destino<<endl;
				return;
			}
			else{
				if(ant==NULL){
					aux->lista_arco=aux->lista_arco->link;
				}
				else{
					ant->link=aux2->link;
				}
				cout<<"Se ha eliminado el arco "<<aux2->id_arco<<endl;
				delete aux2;
				return;
			}
		}
		aux=aux->link;
	}
	cout<<"No se ha encontrado nodo origen";
	return;
}
	
	
	

/* Ejercicio 3 */
//Función Mostrar Grafo
void grafo_mostrar(NGrafo* grafo){
	NGrafo* auxG = grafo;
	while(auxG!=NULL){
		cout<<"Nodo "<<auxG->id_nodo<<":"<<endl;
		NArco* auxA = auxG->lista_arco;
		while(auxA!=NULL){
			cout<<"\tArco "<<auxA->id_arco<<" -> "<<"Nodo "<<auxA->destino->id_nodo<<endl;
			auxA=auxA->link;
		}
		auxG=auxG->link;
	}
}
	


/* Ejercicio 4 */
//Función Eliminar Nodo
void grafo_eliminar_nodo(NGrafo* &grafo, int id_nodo){
	NGrafo* auxG = grafo;
	NGrafo* ant = NULL;
	while(auxG!=NULL&&auxG->id_nodo!=id_nodo){
		ant=auxG;
		auxG=auxG->link;
	}
	if(auxG==NULL){
		cout<<"No se ha encontrado el nodo "<<id_nodo<<endl;
		return;
	}
	else{
		NGrafo* aux = grafo;
		while(aux!=NULL){
			grafo_eliminar_arco(grafo, aux->id_nodo, id_nodo);
			aux=aux->link;
		}
		
		if(ant==NULL){
			grafo=grafo->link;
		}
		else{
			ant->link=auxG->link;
		}
		delete auxG;
		cout<<"Se ha eliminado el nodo "<<id_nodo<<endl;
	}
}

/* Ejercicio 7 */
//Funcion Nodos Adyacentes
void grafo_nodos_adyacentes(NGrafo* &grafo, int id_nodo){
	NGrafo* auxG = grafo;
	NGrafo* adyacentes = NULL;
	NGrafo* aux = NULL;
	while(auxG!=NULL){
		NArco* auxA = auxG->lista_arco;
		if(auxG->id_nodo==id_nodo){
			while(auxA!=NULL){
				cout<<"Recorriendo nodo 121..."<<endl;
				aux=adyacentes;
				while(aux!=NULL&&aux->id_nodo!=auxA->destino->id_nodo){
					aux=aux->link;
				}
				if(aux==NULL){
					cout<<"1- Encontrado adyacente "<<auxA->destino->id_nodo<<endl;
					grafo_agregar_nodo(adyacentes, auxA->destino->id_nodo);
				}
				auxA=auxA->link;
			}
		}
		else{
			while(auxA!=NULL){
				cout<<"Recorriendo nodo "<<auxG->id_nodo<<"..."<<endl;
				if(auxA->destino->id_nodo==id_nodo){
					aux=adyacentes;
					while(aux!=NULL&&aux->id_nodo!=auxG->id_nodo){
						aux=aux->link;
					}
					if(aux==NULL){
						cout<<"2- Encontrado adyacente "<<auxG->id_nodo<<endl;
						grafo_agregar_nodo(adyacentes, auxG->id_nodo);
					}
				}
				auxA=auxA->link;
			}
		}
		auxG=auxG->link;
	}
	aux = adyacentes;
	cout<<"Nodos adyacentes a "<<id_nodo<<": ";
	while(aux!=NULL){
		cout<<aux->id_nodo<<" ";
		aux=aux->link;
	}
}
/* Ejercicio 8 */
//Funcion Conjunto Derecho
void grafo_conjunto_derecho(NGrafo* &grafo, int id_nodo){
	NGrafo* auxG = grafo;
	NGrafo* right = NULL;
	while(auxG!=NULL){
		if(auxG->id_nodo==id_nodo){
			NArco* auxA = auxG->lista_arco;
			while(auxA!=NULL){
				grafo_agregar_nodo(right, auxA->destino->id_nodo);
				/* 
				NGrafo* nuevo = new NGrafo;
				nuevo->id_nodo=auxA->destino->id_nodo;
				nuevo->link=right;
				nuevo->lista_arco=NULL;
				right = nuevo;
				*/
				auxA=auxA->link;
			}
		}
		auxG=auxG->link;
	}
	auxG = right;
	cout<<"Conjunto derecho: "<<endl;
	while(auxG!=NULL){
		cout<<auxG->id_nodo<<"\t";
		auxG=auxG->link;
	}
}
/* Ejercicio 9 */
//Funcion Conjunto Izquierdo
void grafo_conjunto_izquierdo(NGrafo* &grafo, int id_nodo){
	NGrafo* auxG = grafo;
	NGrafo* left=NULL;
	while(auxG!=NULL){
		NArco* auxA = auxG->lista_arco;
		while(auxA!=NULL){
			if(auxA->destino->id_nodo==id_nodo){
				grafo_agregar_nodo(left, auxG->id_nodo);
			}
			auxA=auxA->link;
		}
		auxG=auxG->link;
	}
	auxG = left;
	cout<<"Conjunto izquierdo: "<<endl;
	while(auxG!=NULL){
		cout<<auxG->id_nodo<<"\t";
		auxG=auxG->link;
	}
}
/* Ejercicio 10 */
//Funcion Conjunto Ideal Izquierdo
void grafo_ideal_izquierdo(NGrafo* grafo, int id_nodo, NGrafo* &idIzq){
	NGrafo* auxG = grafo;
	while(auxG!=NULL){
		NArco* auxA = auxG->lista_arco;
		while(auxA!=NULL){
			if(auxA->destino->id_nodo==id_nodo){
				cout<<"Este arco lleva al nodo "<<id_nodo<<endl;
				NGrafo* auxI = idIzq;
				while(auxI!=NULL&&auxI->id_nodo!=auxG->id_nodo){
					auxI=auxI->link;
				}
				if(auxI==NULL){
					grafo_agregar_nodo(idIzq, auxG->id_nodo);
					grafo_ideal_izquierdo(grafo, auxG->id_nodo, idIzq);
					cout<<"Agregado nodo "<<auxG->id_nodo<<endl;
				}
			}
			auxA=auxA->link;
		}
		auxG=auxG->link;
	}
}
/* Ejercicio 11 */
//Funcion Maximal
void grafo_conjunto_maximal(NGrafo* &grafo){
	NGrafo* aux = grafo;
	NGrafo* maximal = NULL;
	while(aux!=NULL){
		if(aux->lista_arco==NULL){
			grafo_agregar_nodo(maximal, aux->id_nodo);
		}
		aux=aux->link;
	}
	aux=maximal;
	cout<<"Conjunto maximal: "<<endl;
	while(aux!=NULL){
		cout<<aux->id_nodo<<"   ";
		aux=aux->link;
	}
}
/* Ejercicio 12 */
//Funcion Minimal	
void grafo_conjunto_minimal(NGrafo* &grafo){
	NGrafo* auxG1 = grafo;
	NGrafo* minimal = NULL;
	int llegadas=0;
	while(auxG1!=NULL){
		NGrafo* auxG2 = grafo;
		while(auxG2!=NULL){
			NArco* auxA = auxG2->lista_arco;
			while(auxA!=NULL){
				if(auxA->destino->id_nodo==auxG1->id_nodo){
					llegadas++;
				}
				auxA=auxA->link;
			}
			auxG2=auxG2->link;
		}
		if(llegadas==0){
			grafo_agregar_nodo(minimal, auxG1->id_nodo);
		}
		auxG1=auxG1->link;
		llegadas=0;
	}
	cout<<"Conjunto minimal: "<<endl;
	auxG1 = minimal;
	while(auxG1!=NULL){
		cout<<auxG1->id_nodo<<"  ";
		auxG1=auxG1->link;
	}
}
/* Ejercicio 14 */
//Funcion Conjunto Ideal Derecho
void grafo_ideal_derecho(NGrafo* grafo, int id_nodo, NGrafo* &idDer){
	cout<<"Analizando nodo "<<id_nodo<<endl;
	NGrafo* auxG = grafo;
	while(auxG!=NULL){
		cout<<"Buscando en nodo "<<auxG->id_nodo<<endl;
		if(auxG->id_nodo==id_nodo){
			cout<<"Este es el nodo, entremos"<<endl;
			NArco* auxA = auxG->lista_arco;
			while(auxA!=NULL){
				cout<<"Buscando en arco "<<auxG->id_nodo<<"->"<<auxA->destino->id_nodo<<endl;
				NGrafo* auxI = idDer;
				while(auxI!=NULL&&auxI->id_nodo!=auxA->destino->id_nodo){
					auxI=auxI->link;
				}
				if(auxI==NULL){
					grafo_agregar_nodo(idDer, auxA->destino->id_nodo);
					grafo_ideal_derecho(grafo, auxA->destino->id_nodo, idDer);
				}
				auxA=auxA->link;
				
			}
		}
		auxG=auxG->link;
	}
}

/* Ejercicio 13 */
//Funcion Mínimo
void grafo_minimo(NGrafo* &grafo){
	NGrafo* auxG1 = grafo;
	NGrafo* minimal = NULL;
	int llegadas=0;
	int cant=0;
	while(auxG1!=NULL){
		NGrafo* auxG2 = grafo;
		while(auxG2!=NULL){
			NArco* auxA = auxG2->lista_arco;
			while(auxA!=NULL){
				if(auxA->destino->id_nodo==auxG1->id_nodo){
					llegadas++;
				}
				auxA=auxA->link;
			}
			auxG2=auxG2->link;
		}
		if(llegadas==0){
			grafo_agregar_nodo(minimal, auxG1->id_nodo);
			cant++;
		}
		auxG1=auxG1->link;
		llegadas=0;
	}
	if(cant==1){
		cout<<"El mínimo es el nodo "<<minimal->id_nodo<<endl;
	}
	else{
		cout<<"El grafo no posee mínimo."<<endl;
	}
	
}
/* Ejercicio 16 */
//Funcion EsArbolBinario
//bool grafo_esArbolBinario(struct grafoA* grafo){
//	int cantArcosTotal=0;
//	for(int i=0; i<M; i++){
//		int cantArcos=0;
//		for(j=0; j<M; j++){
//			if(grafo->matriz[i][j]==1){
//				cantArcos++;
//			}
//		}
//		if(!cantArcos<=2){
//			return false;
//		}
//		cantArcosTotal+=cantArcos;
//	}
//	for(int j=0; j<M; j++){
//		int cantArcos=0;
//		for(i=0; i<M; i++){
//			if(grafo->matriz[i][j]==1){
//				cantArcos++;
//			}
//		}
//		if(!cantArcos<=1){
//			return false;
//		}
//	}
//	if(M==(cantArcos-1)){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
/* Ejercicio 17 */
//Funcion Loops
void grafo_loops(NGrafo* &grafo, int id_nodo){
	NGrafo* auxG = grafo;
	while(auxG!=NULL&&auxG->id_nodo!=id_nodo){
		auxG=auxG->link;
	}
	if(auxG!=NULL){
		NArco* auxA = auxG->lista_arco;
		while(auxA!=NULL){
			if(auxA->destino->id_nodo==id_nodo){
				cout<<"El nodo "<<id_nodo<<" tiene loop."<<endl;
				return;
			}
			auxA=auxA->link;
		}
		cout<<"El nodo no tiene loop."<<endl;
	}
	else{
		cout<<"No se encuentra el nodo."<<endl;
	}
}
/* Ejercicio 18 */
//Funcion Busca Arco
void grafo_busca_arco(NGrafo* &grafo, int id_nodo_origen, int id_nodo_destino){
	NGrafo* auxG = grafo;
	while(auxG!=NULL&&auxG->id_nodo!=id_nodo_origen){
		auxG=auxG->link;
	}
	if(auxG!=NULL){
		NArco* auxA = auxG->lista_arco;
		while(auxA!=NULL){
			if(auxA->destino->id_nodo==id_nodo_destino){
				cout<<"Existe arco desde nodo "<<id_nodo_origen<<" hacia nodo "<<id_nodo_destino<<endl;
				return;
			}
			auxA=auxA->link;
		}
		cout<<"No existe arco."<<endl;
	}
	else{
		cout<<"No se encuentra el nodo de origen."<<endl;
	}
}
/* Ejercicio 19 */
//Funcion Busca Ciclo
bool grafo_busca_ciclo(NGrafo* grafo, int id_nodo, int nodo_llegada, NGrafo* &nodosPaso){
	NGrafo* auxG = grafo;
	while(auxG!=NULL){
		if(auxG->id_nodo==id_nodo){
			NArco* auxA = auxG->lista_arco;
			while(auxA!=NULL){
				if(auxA->destino->id_nodo!=id_nodo){
					if(auxA->destino->id_nodo==nodo_llegada){
						return true;
					}else{
						NGrafo* auxP=nodosPaso;
						while(auxP!=NULL&&auxP->id_nodo!=auxA->destino->id_nodo){
							auxP=auxP->link;
						}
						if(auxP==NULL){
							grafo_agregar_nodo(nodosPaso, auxA->destino->id_nodo);
							return grafo_busca_ciclo(grafo, auxA->destino->id_nodo, nodo_llegada, nodosPaso);
						}
					}
				}
			auxA=auxA->link;
			}
		}
		auxG=auxG->link;
	}
	return false;
}
/* Ejercicio 20 */
//Funcion Grafo Basico

//MAIN
int main(int argc, char *argv[]) {
	NGrafo* miGrafo = NULL;
	/* Ejercicio 1 */{
	grafo_agregar_nodo(miGrafo, 87);
	grafo_agregar_nodo(miGrafo, 32);
	grafo_agregar_nodo(miGrafo, 121);
	grafo_agregar_nodo(miGrafo, 4);
	grafo_agregar_nodo(miGrafo, 8);
	grafo_agregar_arco(miGrafo, 81, 87, 4);
	grafo_agregar_arco(miGrafo, 73, 121, 8);
	grafo_agregar_arco(miGrafo, 27, 32, 121);
	grafo_agregar_arco(miGrafo, 85, 121, 87);
	grafo_agregar_arco(miGrafo, 7, 4, 121);
	grafo_agregar_arco(miGrafo, 5, 8, 4);
	grafo_agregar_arco(miGrafo, 1, 4, 4);
	}
	cout<<endl<<"----------------------"<<endl;
	grafo_mostrar(miGrafo);
	cout<<endl<<"----------------------"<<endl;
	grafo_nodos_adyacentes(miGrafo, 4);
	//grafo_eliminar_nodo(miGrafo, 121);
	cout<<endl<<"----------------------"<<endl;
	cout<<"Cantidad de nodos: "<<grafo_cuenta_nodos(miGrafo)<<endl;
	cout<<"Cantidad de arcos: "<<grafo_cuenta_arcos(miGrafo)<<endl;
	cout<<endl<<"----------------------"<<endl;
	grafo_mostrar(miGrafo);
	cout<<endl<<"----------------------"<<endl;
	NGrafo* ideal = NULL;
	grafo_ideal_derecho(miGrafo, 121, ideal);
	NGrafo* aux = ideal;
	cout<<"Conjunto ideal derecho: ";
	while(aux!=NULL){
		cout<<aux->id_nodo<<"   ";
		aux=aux->link;
	}
	cout<<endl<<"----------------------"<<endl;
	grafo_conjunto_minimal(miGrafo);
	cout<<endl<<"----------------------"<<endl;
	grafo_minimo(miGrafo);
	cout<<endl<<"----------------------"<<endl;
	grafo_loops(miGrafo, 4);
	cout<<endl<<"----------------------"<<endl;
	grafo_busca_arco(miGrafo, 32, 4);
	cout<<endl<<"----------------------"<<endl;
	NGrafo* nodosPaso = NULL;
	if(grafo_busca_ciclo(miGrafo, 4, 4, nodosPaso)==true){
		cout<<"Hay ciclo"<<endl;
	}
	else{
		cout<<"No existe ciclo"<<endl;
	}
	return 0;
}

