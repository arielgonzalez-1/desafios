#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Para su uso se debe instalar colorama:
pip3 install colorama
"""

import os
import sys
import colorama
from colorama import Fore

class Euclides:
    def __init__(self):
        self.clear = lambda: os.system('cls' if os.name in ('nt', 'dos') else 'clear')
        self.color = Fore.YELLOW
        self.msg = Fore.CYAN
        self.error = Fore.RED
        self.str_resto = ''
        self.str_divisor = ''
        self.mcd = 0
        self.mcm = 0
        self.coprimos = False

    def division(self, a:int, b:int):
        "Realiza el algoritmo de la division"
        dividendo = max(a, b)
        divisor = min(a, b)
        self.mcm = a * b
        self.mcd = divisor
        resto = 1
        while(resto > 0):
            cociente = dividendo // divisor
            resto = dividendo % divisor
            if resto != 0:
                self.str_resto += f'{self.color}{resto} = {dividendo} + {divisor}({(-1)*cociente})\n'
                self.mcd = resto
            self.str_divisor += f'{self.color}{dividendo} = {divisor}({cociente}) + {resto}\n'
            dividendo = divisor
            divisor = resto
        self.mcm //= self.mcd
        if self.mcd == 1:
            self.coprimos = True

if __name__ == '__main__':
    colorama.init(autoreset=True)
    obj = Euclides()
    obj.clear()

    try:
        n1 = int(input(obj.msg + 'Ingrese dividendo:\n'))
        n2 = int(input(obj.msg + 'Ingrese divisor:\n'))
        assert (isinstance(n1, int) and isinstance(n2, int))
    except AssertionError:
        print(f'{obj.error}Por favor ingrese los valores nuevamente')
    except:
        print(f'{obj.error}Unexpected error: {sys.exc_info()[0]}')
    else:
        obj.division(n1, n2)
        print(f'{obj.msg}Algoritmo de la División:')
        print(f'{obj.color}{obj.str_divisor}')
        print(f'{obj.msg}Ordenando los restos:')
        print(f'{obj.color}{obj.str_resto}')
        print(f'{obj.msg}Maximo Comun Divisor: {obj.mcd}')
        print(f'{obj.msg}Minimo Comun Multiplo: {obj.mcm}')
        print(f'{obj.msg}Coprimos o Primos Relativos: {obj.coprimos}')