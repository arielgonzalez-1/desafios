#include <iostream>
using namespace std;

struct nodo_grafo{
	int id_nodo;
	struct nodo_arco* lista_arco;
	struct nodo_grafo* link;
};
typedef struct nodo_grafo NGrafo;

struct nodo_arco{
	int id_arco;
	struct nodo_grafo* destino;
	struct nodo_arco* link;
};
typedef struct nodo_arco NArco;

void grafo_mostrar (NGrafo* lista_n){
	cout << "Grafo:\n\n";
	while (lista_n != NULL){
		cout << "Nodo " << lista_n->id_nodo << ":" << endl;
		NArco* aux_la = lista_n->lista_arco;
		while (aux_la != NULL){
			cout << "  Arco " << aux_la->id_arco << " -> Nodo " << aux_la->destino->id_nodo << endl;
			aux_la = aux_la->link;
		}
		lista_n = lista_n->link;
	}
	cout << endl;
	cout << endl;
}

int cantidad_arcos (NGrafo* lista_n){
    int cant=0;
    while (lista_n != NULL){
        NArco* aux_la = lista_n->lista_arco;
        while (aux_la != NULL){
            aux_la = aux_la->link;
            cant++;
        }
        lista_n = lista_n->link;
    }
    return cant;
}

int contarNodos(NGrafo* lista_n){
    int cont=0;
    while (lista_n != NULL){
        cont++;
        lista_n = lista_n->link;
    }
    return cont;
}

void grafo_agregar_nodo (NGrafo* &lista_n, int id_nodo){
	NGrafo* aux = lista_n;
	while (aux != NULL){
		if (aux->id_nodo == id_nodo){
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

void grafo_agregar_arco (NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino){
	NGrafo* nodo_origen = lista_n;
	NGrafo* nodo_destino = lista_n;
    NGrafo* aux = lista_n;

	while (nodo_origen != NULL && nodo_origen->id_nodo != id_nodo_origen)
	    nodo_origen = nodo_origen->link;
	while (nodo_destino != NULL && nodo_destino->id_nodo != id_nodo_destino)
		nodo_destino = nodo_destino->link;
	if (nodo_origen == NULL || nodo_destino == NULL){
		cout << "!!! Error: Alguno de los nodos no existe." << endl;
		return;
	}
    while (aux!=NULL) {
        NArco* aux2 = aux->lista_arco;
        while(aux2 != NULL){
            if(aux2->id_arco == id_arco)
                return;
            aux2 = aux2->link;
        }
        aux = aux->link;
    }
    NArco* nuevo_arco = new (NArco);
    nuevo_arco->id_arco = id_arco;
    nuevo_arco->destino = nodo_destino;
    nuevo_arco->link = nodo_origen->lista_arco;
    nodo_origen->lista_arco = nuevo_arco;
}

void grafo_eliminar_arco ( NGrafo* lista_n, int id_nodo_origen, int id_nodo_destino){
    NGrafo* nodo_origen = lista_n;
    while (nodo_origen != NULL && nodo_origen->id_nodo != id_nodo_origen)
        nodo_origen = nodo_origen->link;
    if (nodo_origen == NULL )
    {
        throw -1;       // Origen Inexistente
        return;
    }
    NArco*  anterior    = NULL;
    NArco*  actual    = nodo_origen->lista_arco;
    while (actual != NULL && actual->destino->id_nodo != id_nodo_destino) {
        anterior = actual;
        actual = actual->link;
    }
    if (actual == NULL) {
        throw -2;       // Arco Inexistente
    } else {                                       // actual != NULL hay nodo a borrar
        if (anterior == NULL && actual != NULL) {    // quiere decir que es el 1er arco, hay que actualizar el puntero del nodo
            nodo_origen->lista_arco = actual->link;
        } else {    // es un arco intermedio o el ultimo
            anterior->link = actual->link;
        }
        delete actual;
    }
}

void eliminarNodoGrafo(NGrafo* &lista_n, int id_nodo){
    NGrafo* auxLista = lista_n;
    NGrafo* antNodoLista = NULL;
    NGrafo* aux2 ;
    NArco* arcoAnt;
    NArco* arcoActual;
    while(auxLista != NULL ){
            arcoActual = auxLista->lista_arco;
            arcoAnt=NULL;
            while(arcoActual != NULL && arcoActual->destino->id_nodo != id_nodo){
                arcoAnt = arcoActual;
                arcoActual = arcoActual->link;
            }
            if(arcoActual != NULL && arcoActual->destino->id_nodo == id_nodo){
                if(arcoAnt != NULL){
                    arcoAnt->link = arcoActual->link;
                    delete arcoActual;
                }else{
                    auxLista->lista_arco = NULL;
                    delete arcoActual;
                }
            }
        auxLista = auxLista->link;
    }
    auxLista = lista_n;
    while(auxLista != NULL && auxLista->id_nodo != id_nodo){
        antNodoLista = auxLista;
        auxLista = auxLista->link;
    }
    if(auxLista != NULL && auxLista->id_nodo == id_nodo ){
        arcoActual = auxLista->lista_arco;
        while(arcoActual != NULL){
            arcoAnt = arcoActual;
            arcoActual = arcoActual->link;
            delete arcoAnt;
        }
        if(antNodoLista == NULL){
            aux2 = auxLista;
            auxLista = auxLista->link;
            delete aux2;
        }else{
            antNodoLista->link = auxLista->link;
            aux2 = auxLista;
            auxLista = auxLista->link;
            delete aux2;
        }
    }
}

int* addLoop(int* loops, int id_nodo, int cantidadLoops){
    int* aux = new int[cantidadLoops+1];
    for(int i=0; i<cantidadLoops; i++){
        aux[i] = loops[i];
    }
    aux[cantidadLoops] = id_nodo;
    delete loops;
    return aux;
}

int* getLoops(NGrafo* lista_n){
    NGrafo* auxNodo = lista_n;
    NArco * auxArco;
    int* loops, cantidadLoops=0;
    loops = new int[cantidadLoops];

    while (auxNodo != NULL){
        auxArco = auxNodo->lista_arco;
        while(auxArco != NULL){
            if(auxArco->destino->id_nodo == auxNodo->id_nodo){
               loops = addLoop(loops,auxNodo->id_nodo, cantidadLoops);
               cantidadLoops++;
            }
            auxArco = auxArco->link;
        }
        auxNodo = auxNodo->link;
    }
    return loops;
}

int getCantLoops(NGrafo* lista_n){
    NGrafo* auxNodo = lista_n;
    NArco * auxArco;
    int cantidadLoops=0;
    while (auxNodo != NULL){
        auxArco = auxNodo->lista_arco;
        while(auxArco != NULL){
            if(auxArco->destino->id_nodo == auxNodo->id_nodo){
               cantidadLoops++;
            }
            auxArco = auxArco->link;
        }
        auxNodo = auxNodo->link;
    }
    return cantidadLoops;
}

void left(NGrafo* lista_n, int id_nodo){
    NGrafo* aux = lista_n;
    NArco* aux2 ;
    while(aux != NULL){
        aux2 = aux->lista_arco;
            while(aux2 != NULL){
                if(aux2->destino->id_nodo == id_nodo){
                    cout<<aux->id_nodo<<" ";
                }
               aux2 = aux2->link;
            }
        aux = aux->link;
    }
}

void right(NGrafo* lista_n, int id_nodo){
    NGrafo* aux = lista_n;
    NArco* aux2 ;
    while(aux != NULL && aux->id_nodo != id_nodo){
        aux = aux->link;
    }
    if(aux == NULL)
        return;
    aux2 = aux->lista_arco;
    while(aux2!=NULL){
        cout<< aux2->destino->id_nodo<<" ";
        aux2 = aux2->link;
    }
}

int getCantLeft(NGrafo* lista_n, int id_nodo){
    NGrafo* aux = lista_n;
    NArco* aux2 ;
    int cant=0;
    while(aux != NULL){
        aux2 = aux->lista_arco;
            while(aux2 != NULL){
                if(aux2->destino->id_nodo == id_nodo){
                    cant++;
                }
               aux2 = aux2->link;
            }
        aux = aux->link;
    }
    return cant;
}

void minimal(NGrafo* lista_n){
    cout<<"Conjunto minimal: { ";
    NGrafo* aux = lista_n;
    int cantLefts;
    while(aux!=NULL){
        cantLefts = getCantLeft(lista_n,aux->id_nodo);
        if(cantLefts == 0){
            cout<<aux->id_nodo<<" ";
        }
        aux=aux->link;
    }
    cout<<"} "<<endl;
}

int minimo(NGrafo* lista_n){
    NGrafo* aux = lista_n;
    int cantLefts,minimo,contMinimo=0;
    while(aux!=NULL){
        cantLefts = getCantLeft(lista_n,aux->id_nodo);
        if(cantLefts == 0){
            minimo = aux->id_nodo;
            contMinimo++;
        }
        aux=aux->link;
    }
    if(contMinimo != 1){
        throw "No tiene minimo";
    }else{
        return minimo;
    }
}

void maximal(NGrafo* lista_n){
    cout<<"Conjunto maximal: { ";
    while (lista_n!=NULL)
    {
        if (lista_n->lista_arco==NULL)
        {
            cout<<lista_n->id_nodo<<" ";
        }
        lista_n=lista_n->link;
    }
    cout<<"} "<<endl;
}

int maximo(NGrafo* lista_n){
    int cont=0, maximo;
    while (lista_n!=NULL){
        if (lista_n->lista_arco==NULL){
            maximo = lista_n->id_nodo;
            cont++;
        }
        lista_n=lista_n->link;
    }
    return cont != 1 ? throw "No tiene maximo": maximo ;
}

int main (){
	NGrafo* lista_n = NULL;

	return 0;
}
