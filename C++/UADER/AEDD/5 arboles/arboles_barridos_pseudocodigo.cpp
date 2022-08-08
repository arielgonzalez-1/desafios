Notas:
* El identado delimita los bloques.
* Si la estructura de control "si" tiene solo una línea, no requiere el delimitador de bloque finSi.
* La variable "arbol" es recibida como parámetro, apunta a la raíz del árbol.
* La expresión pila <- arbol agrega arbol a la pila.
* La expresión aux <- pila saca un elemento de la pila y lo guarda en aux.
* La función procesar (aux) hace lo que sea que queramos hacer con cada nodo del árbol, para estos ejemplos asumamos que "muestra el valor del nodo por pantalla".
* La función derecho (aux) retorna el hijo derecho del nodo aux.
* La función izquierdo (aux) retorna el hijo izquierdo del nodo aux.


PREORDEN

si (arbol != NULL)
	pila <- arbol
mientras (!pila_vacia (pila))
	aux <- pila
	procesar (aux)
	si (derecho (aux) != NULL)
		pila <- derecho (aux)
	si (izquierdo (aux) != NULL)
		pila <- izquierdo (aux)
finMientras


INORDEN

si (arbol != NULL)
	pila <- (arbol, 1)
mientras (!pila_vacia (pila))
	(aux, bandera) <- pila
	si (bandera == 1)
		pila <- (aux, 2)
		si (izquierda (aux) != NULL)
			pila <- (izquierda (aux), 1)
	sino
		procesar (aux)
		si (derecha (aux) != NULL)
			pila <- (derecha (aux), 1)
	finSi
finMientras


POSTORDEN

si (arbol != NULL)
	pila <- (arbol, 1)
mientras (!pila_vacia (pila))
	(aux, bandera) <- pila_sacar (pila)
	si (bandera == 1)
		pila <- (aux, 2)
		si (izquierdo (aux) != NULL)
			pila <- (izquierdo (aux), 1)
	finSi
	si (bandera == 2)
		pila <- (aux, 3)
		si (derecho (aux) != NULL)
			pila <- (derecho (aux), 1)
	finSi
	si (bandera == 3)
		procesar (aux)
finMientras


Notas:
* La expresión cola <- aux agrega aux a la cola.
* La expresión aux <- cola saca un elemento de la cola y lo guarda en aux.

PORNIVELES

cola <- arbol
while (!cola_vacia (cola))
	aux <- cola
	procesar (aux)
	si (izquierdo (aux) != NULL)
		cola <- izquierdo (aux);
	si (derecho (aux) != NULL)
		cola <- derecho (aux);
finMientras
