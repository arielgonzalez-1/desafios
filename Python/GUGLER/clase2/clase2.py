#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
1) - Realice las siguientes operaciones desde la consola de Python:
>>> 2 + 2
>>> 3 – 2
>>> 4 * 3
>>> 12 / 2
>>> 18 % 4
>>> 2 ** 3
Registre los resultados obtenidos y realice las siguientes operaciones:
>>> 4 * 3 + 5
>>> 4 * 4 + 6 / 2
>>> 3 ** 3 + 5 – 4 * 2
>>> 3 ** 3 + (5 – 4) * 2
>>> 3 ** (3 + 5 – 4) * 2
Anote los resultados obtenidos.
2) - Obtener ayuda con el comando help() para las funciones id(), type() y dir().
3) - Obtener ayuda con el comando help() para las palabras reservadas is, import,
False, True, and, or, not e in.
4) - Salga del modo interactivo utilizando la combinación de teclas para tal fin.

5) - Crear un módulo nuevo indicando el shebang (#! /usr/bin/env python) y la
codificación en utf8. Guardar el archivo con el nombre ejercicio4.py.
6) - Crear un módulo nuevo. Declarar e inicializar variables con los siguientes
valores:
- Tipo entero: 2
- Tipo decimal: 3.5

entero = 2
decimal = 3.5
booleano = True
cadena = 'cadena de texto'
complejo = 2 + 3j

7) - Tomar como base el módulo del punto anterior para mostrar el valor y el tipo de variable por pantalla (haga uso de type()). Guardar el módulo con el nombre ejercicio6.py

print(type(entero))
print(type(decimal))
print(type(booleano))
print(type(cadena))
print(type(complejo))

8) - Agregar al módulo anterior la posibilidad de mostrar los métodos de cada tipo de dato utilizando la función integrada dir().

print(dir(entero), dir(decimal), dir(booleano), dir(cadena), dir(complejo), sep="\n\n", end="\n=====================================================================================================================================================================\n\n")

9) - Haga un nuevo módulo Python para representar el entero 27 en octal y hexadecimal. Guardar con el nombre ejercicio9.py.

print(oct(27), hex(27), bin(27), sep="\n\n", end="\n=====================================================================================================================================================================\n\n")

10) - Crear un nuevo módulo de nombre ejercicio10.py que almacene en una variable la cadena “Aprendiendo el lenguaje Python”. Utilizando los índices obtenga y muestre el primer carácter de cada palabra de la cadena de texto.

cadena = "Aprendiendo el lenguaje Python"
print(cadena, cadena[0], sep="\n\n", end="\n=====================================================================================================================================================================\n\n")

11) - Modifique el módulo anterior para obtener y mostrar mediante rebanadas (slices) cada una de las palabras de la cadena de texto.

print(cadena[0:11], cadena[12:14], cadena[15:23], cadena[24:30], sep="\n\n", end="\n=====================================================================================================================================================================\n\n")

12) - Trabaje con los operadores relacionales en el lenguaje Python. Cree un módulo nuevo (ejercicio12.py) con el siguiente código:

# Número entero cuatro
cuatro = 4
# Número entero cinco
cinco = 5
# Número entero seis
seis = 6
# Número entero siete
siete = 7
# Número entero ocho
ocho = 8
# Número entero nueve
nueve = 9

# Comparación igual ==
print('cinco == cinco es:', cinco == cinco)
# Comparación distinto !=
print('cuatro == seis es:', cuatro == seis)
# Comparación mayor >
print('cinco > cuatro es:', cinco > cuatro)
# Comparación menor <
print('nueve < siete es:', nueve < siete)
# Comparación igual <=
print('cinco <= ocho es:', cinco <= ocho)
# Comparación igual >=
print('cinco >= siete es:', cinco >= siete)

print("\n=====================================================================================================================================================================\n\n")

13) - Trabaje con los operadores lógicos en el lenguaje Python. Cree un módulo nuevo (ejercicio13.py) con el siguiente código:

# Operación lógica de conjunción
print('(cinco + ocho) > cuatro and cinco > siete es:',
      (cinco + ocho) > cuatro and cinco > siete)
# Operación lógica de disyunción
print('(cinco + ocho) > cuatro or nueve > siete es:',
      (cinco + ocho) > cuatro or nueve > siete)
# Operación lógica de negación
print('not(cuatro + cinco == nueve) es:', not(cuatro + cinco == nueve))

print("\n=====================================================================================================================================================================\n\n")

14) - Investigar y programar un módulo de Python donde se haga un incremento y decremento sobre una variable entera

x = 0
print(x, end="\n\n")
x -= 1
print(x, end="\n\n")
x += 1
x += 1
print(x, end="\n\n")

print("\n=====================================================================================================================================================================\n\n")

15) – Desarrolle un nuevo módulo que tenga como salida la tabla de multiplicar del8. A continuación un ejemplo del resultado esperado

number = 8
number_name = 'ocho'

title = 'Tabla de multiplicar del ' + str(number)

print('=' * len(title))
print(title)
print('=' * len(title))

number_aux = 1
number_aux_name = 'uno'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 2
number_aux_name = 'dos'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 3
number_aux_name = 'tres'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 4
number_aux_name = 'cuatro'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 5
number_aux_name = 'cinco'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 6
number_aux_name = 'seis'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 7
number_aux_name = 'siete'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 8
number_aux_name = 'ocho'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

number_aux = 9
number_aux_name = 'nueve'
print(number_aux_name, 'x', number_name, ':',  number_aux * number,
      ', octal:', oct(number_aux * number),
      ', hexadecimal:', hex(number_aux * number),
      ', binario:', bin(number_aux * number))

print('=' * len(title))

print("\n=====================================================================================================================================================================\n\n")

16) - Codifique y ejecute el siguiente módulo: 

entero = 10
otro_entero = 10
print(entero is otro_entero, end="\n\n")
print(id(entero), end="\n\n")
print(id(otro_entero))

Identifique alguna particularidad de la salida por pantalla del módulo. Guardar el archivo con el nombre ejercicio16.py
"""