#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from base import Base
import sys
import colorama
from colorama import Fore

if __name__ == '__main__':
    colorama.init(autoreset=True)
    singleton = Base()

    def isOK(num, numBase:int, newBase:int):
        flag = True
        if not(newBase <= singleton.size and newBase >= 2 and numBase >= 2 and numBase <= singleton.size):
            flag = False
            print(f'{Fore.RED}Por favor ingrese una base entre [0-{singleton.size}]')
        elif(newBase != 10 and numBase != 10):
            flag = False
            print(f'{Fore.RED}Al menos una de las bases debe ser 10')

        else:
            abc = '.'
            abc += singleton.alphabet[:numBase]
            for item in str(num):
                if item not in abc:
                    flag = False
                    print(f'{Fore.RED}Por favor ingrese un numero correcto')
                    break
        return flag

    try:
        print(f'{Fore.LIGHTYELLOW_EX}\nPrograma para convertir numeros de cualquier base a decimal o viceversa')
        num = input(Fore.GREEN + 'Ingrese un numero\n')
        numBase = int(input(Fore.GREEN + 'Ingrese su base\n'))
        newBase = int(input(Fore.GREEN + 'Por favor ingrese la base a la que desee convertir\n'))
        assert (isOK(num, numBase, newBase))
    except AssertionError:
        print(f'{Fore.RED}Por favor ingrese los valores nuevamente')
    except:
        print(f'{Fore.RED}Unexpected error: {sys.exc_info()[0]}')
    else:
        if newBase == 10:
            singleton.toDecimal(num, numBase)
        else:
            singleton.toBase(num, newBase)
        print(f'{Fore.MAGENTA}{singleton.newBase}')