#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from calculadora import *

lista_numeros = [(34, 56), (66, 16), (23, 96), (52, 18)]
funciones = [suma, resta, producto, cociente, potencia]
for f in funciones:
    for i, j in lista_numeros:
        print('\t{} de {} y {} es: {}'.format(f.__name__, i, j, f(i, j)))

lista_numeros = [34, 56, 66, 16, 23, 96, 52, 18]
funciones = [raiz_cuadrada]
for f in funciones:
    for i in lista_numeros:
        print('\t{} de {} es: {}'.format(f.__name__, i, f(i)))
