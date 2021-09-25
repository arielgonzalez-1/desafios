#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
1) - Crear un módulo que lea un número flotante por teclado y que determine si es negativo. Es caso de ser negativo que se muestre por pantalla un aviso de tal situación. Guardar el archivo del módulo con el nombre ejercicio1.py. 
flotante = float(input("Ingrese numero flotante: "))
if flotante < 0:
    print("Es negativo\n" + "=" * 164 + "\n\n")
"""

"""
2) - Crear otro módulo que lea un número flotante por teclado y que determine si es positivo. Es caso de ser positivo que se muestre por pantalla un aviso de tal situación. Guardar el archivo del módulo con el nombre ejercicio2.py.
flotante = float(input("Ingrese numero flotante: "))
if flotante > 0:
    print("Es positivo\n")
print("=" * 164 + "\n\n")
"""

"""
3) - Hacer un módulo que lea la edad de dos personas y determine quien es más joven. Considerar la situación que ambas personas pueden tener la misma edad. En cada situación se deberá mostrar un mensaje. Guardar el archivo del módulo con el nombre ejercicio3.py.
edad1 = int(input("Ingrese edad de persona 1: "))
edad2 = int(input("Ingrese edad de persona 2: "))
if edad1 < edad2:
    print("Pesona 1")
elif edad1 > edad2:
    print("Pesona 2")
else:
    print("Ninguna es menor")
print("=" * 164 + "\n\n")
"""

"""
4) - Realizar un módulo que, dado un número entero determine si es par o impar. Para cualquier caso se le pide mostrar un mensaje de la situación. Recuerde que para saber si un número es par el resto de la división por (2) dos debe dar (0) cero. Guardar el archivo del módulo con el nombre ejercicio4.py
num = int(input("Ingrese numero entero: "))
if num % 2 == 0:
    print("Par")
else:
    print("Impar")
print("=" * 164 + "\n\n")
"""

"""
5) - Programar un nuevo módulo para presentar un menú de al menos (3) tres opciones. El programa debe mostrar mostrar un mensaje de la opción seleccionada. Tener en cuenta que la opción seleccionada puede no ser ninguna de las opciones disponibles. Guardar el archivo con el nombre ejercicio6.py
print('-' * 40)
print('Menú de opciones')
print('-' * 40)
print('1) Determinar si un número flotante es negativo')
print('2) Determinar si un número flotante es positivo')
print('3) Determinar cual de dos personas es mayor')
print('4) Determinar si un número es par o impar')
print('-' * 40)
opcion = int(input('Ingrese la opción:'))
if opcion == 1:
    print("Opcion 1\n")
elif opcion == 2:
    print("Opcion 2\n")
elif opcion == 3:
    print("Opcion 3\n")
elif opcion == 4:
    print("Opcion 4\n")
else:
    print('La opción elegida no es correcta ...\n')
print("=" * 164 + "\n\n")
"""

"""
6) - Codificar un nuevo módulo para encontrar los primeros (100) cien números pares e impares. Guardar el archivo con el nombre ejercicio6.py
pares = []
impares = []
for i in range(100):
    if i % 2 == 0:
        pares.append(i)

for i in range(100):
    if i % 2 != 0:
        impares.append(i)

print(pares, impares, sep="\n\n")
print("=" * 164 + "\n\n")
"""

"""
7) - Crear un módulo que muestre todos los números potencias de 2 entre 2^0 hasta 2^20. Guardar el archivo con el nombre ejercicio7.py.
for x in range(21):
    print("2**{} =".format(x), 2**x, end="\n\n")
print("=" * 164 + "\n\n")
"""

"""
8) - Programar un módulo que realice la suma de los 100 primeros números enteros. Guardar el archivo con el nombre ejercicio8.py
sum = 0
for x in range(1, 101):
    sum += x
print(sum)
print("=" * 164 + "\n\n")
"""

"""
9) - Crear un módulo donde se defina y utilice una función que haga el calculo de la media entre dos valores que les pasa como parámetro. Luego hacer uso de la función con distintos valores y mostrar en pantalla los resultados. Guardar el archivo con el nombre ejercicio9.py.
def media(x, y):
    return (x + y)/2

print(media(0, 0))
print(media(1, 1))
print(media(6, 6))
print(media(4, 9))
print("=" * 164 + "\n\n")
"""

"""
10) - Programar un módulo donde se definan dos funciones, una para calcular el cuadrado de un número y otra para calcular el cubo. Utilizar las funciones con algunos ejemplos. Guardar el archivo con el nombre ejercicio10.py.
def cubo(x):
    return x**3

def cuadrado(x):
    return x**2

print(cuadrado(4))
print(cubo(3))
print("=" * 164 + "\n\n")
"""

"""
11) - Desarrollar un módulo que defina y use una función para convertir grados Fahrenheit a grados centígrados. Para llevar a cabo la conversión se debe restar (32) treinta y dos a los grados Fahrenheit y luego multiplicar el resultado por (5/9) cinco novenos. Guardar el archivo con el nombre ejercicio11.py.
def far_to_cent(grados):
    return (grados - 32) * 5/9


temperaturas_grados = [34, 56, 66, 16, 23, 96, 52, 18, 32, 99, 0]

for i in temperaturas_grados:
    print('{} °F es equivalente a {:.4f} °C'.format(i, far_to_cent(i)))
print("=" * 164 + "\n\n")
"""

"""
12) - Crear un módulo nuevo que defina y use una función para convertir grados |centígrados a grados Fahrenheit. Guardar el módulo con el nombre ejercicio12.py. La conversión se realiza multiplicando los grados centígrados por (9/5) nueve quintos y luego se le suma (32) treinta y dos.
def cent_to_far(grados):
    return grados * 9/5 + 32


temperaturas_grados = [34, 56, 66, 16, 23, 96, 52, 18, 32, 99, 0]

for i in temperaturas_grados:
    print('{} °C es equivalente a {:.4f} °F'.format(i, cent_to_far(i)))
print("=" * 164 + "\n\n")
"""