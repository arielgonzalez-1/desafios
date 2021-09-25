#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#1) - Crear un módulo nuevo indicando el shebang (#! /usr/bin/env python) y la codificación en utf8. Guardar el archivo con el nombre ejercicio1.py. Dentro del módulo se debe crear una lista con las nueve primeras palabras claves del lenguaje Python (primera columna).
help('keywords')
keywords = [
    "False",
    "None",
    "True",
    "and",
    "as",
    "assert",
    "async",
    "await",
    "break"
]

print(keywords, len(keywords),end="\n=====================================================================================================================================================================\n\n")

#2) - Modificar el módulo del primer ejercicio y agregar las siguientes nueve palabras claves del lenguaje Python (segunda columna). Puede utilizar el método append() o extend().

keywords2 = [
    "class",
    "continue",
    "def",
    "del",
    "elif",
    "else",
    "except",
    "finally",
    "for"
]

keywords.extend(keywords2)
keywords2.clear() #vacio la lista
print(keywords, len(keywords), keywords2, len(keywords2),sep="\n", end="\n=====================================================================================================================================================================\n\n")
del keywords2 #libero memoria

#3) - Modificar el módulo del ejercicio anterior para ordenar la lista y luego mostrar la misma por pantalla.

keywords.sort() #sorted() genera una lista ordenada
print(keywords, end="\n=====================================================================================================================================================================\n\n")

#4) - Editar el módulo del ejercicio anterior para invertir los elementos de la lista. Luego mostrar por pantalla.

keywords.reverse() #invertir sin ordenar
#keywords[::-1] #invertir sin ordenar
#keywords.sort(reverse=True) #ordenar e invertir una lista
print(keywords, sep="\n\n", end="\n=====================================================================================================================================================================\n\n")

#5) - Editar el módulo del ejercicio anterior para obtener el número de índice de al menos tres palabras claves de la lista. Utilizar el método index().

#print(keywords.index("ass"))
print(keywords.index("class"), keywords.index("and"), keywords.index("as"), sep="\n", end="\n=====================================================================================================================================================================\n\n")

#6) - Nuevamente editar el módulo de ejercicio anterior para eliminar el último elemento de la lista. Mostrar el contenido de la lista. Luego volver a insertar el elemento a la lista. Mostrar la lista por pantalla.

keywords.pop() #por defecto quita el ultimo elemento
#del keywords[-1] #otra forma pero esta NO retorna un valor
print(keywords, end="\n")
keywords.append("include") #agrega elemento al final
print(keywords, end="\n")
keywords.remove("include") #si no es encontrado devuelve error
print(keywords, end="\n")
keywords.insert(0, "False") #inserta elemento en posicion asignada
print(keywords, end="\n=====================================================================================================================================================================\n\n")

#7) - Nuevamente modificar el módulo de ejercicio anterior para copiar la lista de palabras reservadas. Luego vaciar la lista original. Mostrar el contenido de las dos listas por pantalla. Finalmente, vuelva los elementos a la lista inicial de palabras claves.

newKeywords = keywords.copy()
print(newKeywords, end="\n")
keywords.clear()
#del keywords[:] #otra forma pero esta NO retorna un valor
print(keywords, end="\n")
keywords = newKeywords.copy()
print(keywords, end="\n")
del newKeywords
#print(newKeywords, end="\n\n")
print("=====================================================================================================================================================================\n\n")
del keywords

#8) - Crear un módulo nuevo indicando el shebang (#! /usr/bin/env python) y la codificación en utf8. Guardar el archivo con el nombre ejercicio8.py. Crear una tupla nueva con los siguientes elementos (0, 1, 2, 3, 4, 5, 6, 7, 8, 9).

tupla = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
print(tupla, end="\n=====================================================================================================================================================================\n\n")

#9) - Modificar el módulo del ejercicio 8 para mostrar algunos elementos individuales utilizando índices.

print(tupla[0], tupla[int(len(tupla)/2)], tupla[-1], end="\n=====================================================================================================================================================================\n\n")

#10) - Utilizar el módulo del ejercicio 8 para intentar eliminar algún elemento de la tupla. Mencione el resultado de hacer la operación mencionada.

#tupla.pop()
#print(tupla)
"""
try:
    del tupla[0]
except Exception as e:
    print('Se dispara la excepción:')
    print(e)
"""
#Ver help('tuple') recordar que son inmutables
del tupla

#11) - Crear un módulo nuevo indicando el shebang (#! /usr/bin/env python) y la codificación en utf8. Guardar el archivo con el nombre ejercicio11.py. Crear una tupla con los días de la semana. Mostrar el contenido de la tupla por pantalla. Agregar una nueva tupla que tenga como elemento el presente mes del año.

dias = ("lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo") #los parentesis no son necesarios
meses = 'julio', #para ser considerado una tupla debe tener ,
print(dias, meses, type(dias), type(meses), sep="\n",  end="\n=====================================================================================================================================================================\n\n")
del dias, meses

#12) - Codifique un nuevo módulo con el nombre ejercicio12.py. Cree dentro del módulo un diccionario con al menos diez códigos postales de localidades de la provincia Entre Ríos. Listado de localidades y códigos:

localidades = {
    3150: 'NOGOYA',
    3138: 'ALCARAZ',
    3142: 'BOVRIL',
    3116: 'CRESPO',
    3105: 'DIAMANTE',
    3206: 'FEDERACION',
    3164: 'GENERAL RAMIREZ',
    3281: 'PUEBLO LIEBIG',
    3107: 'SAN BENITO',
    3100: 'PARANA'
}
print(localidades,  end="\n=====================================================================================================================================================================\n\n")

#13) - Codifique el módulo del ejercicio anterior para mostrar en pantalla el listado de índices y el listados de valores del diccionario.

print(localidades.keys(), localidades.values(), sep="\n\n", end="\n=====================================================================================================================================================================\n\n")

#14) - Modifique el módulo del ejercicio anterior para agregar una nueva localidad (3114 ALDEA MARIA LUISA) en el diccionario.

#del localidades["3100"]
#localidades.pop(3100) #eliminar clave y valor
#localidades.popitem() #eliminar clave y valor del ultimo elemento
localidades[3114] = "ALDEA MARIA LUISA" #añadir clave y valor
print(localidades,  end="\n=====================================================================================================================================================================\n\n")

#15) - Modificar nuevamente el módulo del ejercicio anterior para crear un nuevo diccionario de localidades y códigos. A continuación los datos del diccionario nuevo: {3101:"ALDEA SALTO", 2826:"ALDEA SAN ANTONIO"} Después de crear el nuevo diccionario debe agregar el mismo al diccionario ya creado con las localidades anteriores. Puede utilizar el método update(). Finalmente, debe mostrar los elementos del diccionario.

newLocalidades = {3101: 'ALDEA SALTO', 2826: 'ALDEA SAN ANTONIO'}
localidades.update(newLocalidades)
#localidades.update({3101: 'ALDEA SALTO', 2826: 'ALDEA SAN ANTONIO'})
print(localidades,  end="\n=====================================================================================================================================================================\n\n")

#16) - Modificar nuevamente el módulo del ejercicio anterior para copiar el diccionario y luego borrar los elementos del diccionario original. Para terminar debe mostrar los elementos de ambos diccionarios.

newLocalidades = localidades.copy()
localidades.clear()
print(localidades, newLocalidades, sep="\n", end="\n=====================================================================================================================================================================\n\n")
del newLocalidades, localidades