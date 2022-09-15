#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import colorama
from colorama import Fore

class Euclides:
    def __init__(self):
        self.color = Fore.YELLOW
        self.msg = Fore.WHITE
        self.error = Fore.RED
        self.ordenar_resto = ''
        self.ordenar_divisor = ''

    def division(self, a:int, b:int):
        "Realiza el algoritmo de la division"
        dividendo = max(a, b)
        divisor = min(a, b)
        resto = 1
        while(resto > 0):
            cociente = dividendo // divisor
            resto = dividendo % divisor
            if resto != 0:
                self.ordenar_divisor += f'{self.color}{dividendo} = {divisor}({cociente}) + {resto}\n'
                self.ordenar_resto += f'{self.color}{resto} = {dividendo} + {divisor}({(-1)*cociente})\n'
            dividendo = divisor
            divisor = resto

if __name__ == '__main__':
    colorama.init(autoreset=True)
    obj = Euclides()

    try: #que pasa al ingresar 999 y 9
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
        print(obj.ordenar_divisor)
        print(f'{obj.msg}Ordenando los restos:')
        print(obj.ordenar_resto)