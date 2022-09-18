#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Para su uso se debe instalar estas dependencias:
pip3 install colorama
pip3 install sympy
"""

import os
import sys
import colorama
from colorama import Fore


class Diofantica:
    def __init__(self):
        self.sust_atras = list()
        self.restos = dict()
        self.dividendos = dict()
        self.mcd = 0
        self.mcm = 0
        self.coprimos = False

    def division(self, a: int, b: int):
        "Realiza el algoritmo de la division"
        dividendo = max(a, b)
        divisor = min(a, b)
        self.mcm = a * b
        self.mcd = divisor
        resto = 1
        while (resto > 0):
            cociente = dividendo // divisor
            resto = dividendo % divisor
            if resto != 0:
                self.mcd = resto
                self.restos[str(resto)] = f'{dividendo} + {divisor} ({(-1)*cociente})'
            self.dividendos[str(dividendo)] = f'{divisor} ({cociente}) + {resto}'
            dividendo = divisor
            divisor = resto
        self.mcm //= self.mcd
        if self.mcd == 1:
            self.coprimos = True

    def sustitucion_atras(self):
        "Realiza una sustitucion hacia atras"
        self.sust_atras.append(f'{self.restos[str(self.mcd)]}')
        ultimo = self.sust_atras[-1].split()
        termino = ultimo[0]
        termino = f'[ {self.restos[termino]}] '
        ultimo[0] = termino
        termino = ultimo[2]
        termino = f' [{self.restos[termino]}] '
        ultimo[2] = termino
        ultimo = ''.join(ultimo[:])
        self.sust_atras.append(f'{str(ultimo)}')
        #usar regex

        
if __name__ == '__main__':
    color = Fore.YELLOW
    msg = Fore.CYAN
    error = Fore.RED
    colorama.init(autoreset=True)
    clear = lambda: os.system('cls' if os.name in ('nt', 'dos') else 'clear')
    obj = Diofantica()

    try:
        clear()
        print(f'{msg}Dada una ecuación de la forma A(X)+ B(Y) = C')
        a = int(input(msg + 'Ingrese A\n'))
        b = int(input(msg + 'Ingrese B\n'))
        c = int(input(msg + 'Ingrese C\n'))
    except:
        print(f'{error}Unexpected error: {sys.exc_info()[0]}')
    else:
        obj.division(a, b)

        print(f'{msg}\nAlgoritmo de la División')
        for key, value in obj.dividendos.items():
            print(f'{color}{key} = {value}')

        print(f'{msg}\nOrdenando los restos')
        for key, value in obj.restos.items():
            print(f'{color}{key} = {value}')

        print(f'{msg}\nMaximo Comun Divisor: {obj.mcd}')
        print(f'{msg}Minimo Comun Multiplo: {obj.mcm}')
        print(f'{msg}Coprimos o Primos Relativos: {obj.coprimos}')

        if c % obj.mcd == 0:
            obj.sustitucion_atras()
            print(f'{msg}\nSustitución hacia atrás')
            for sust in obj.sust_atras:
                print(f'{color}{sust}')

            print(f'{msg}\nSolucion Particular')
        else:
            print(f'{error}\nNo tiene solucion')