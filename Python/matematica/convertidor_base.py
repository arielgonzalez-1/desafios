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

class Base:
    """Contiene el alfabeto y convierte distintas bases"""
    def __init__(self):
        self.clear = lambda: os.system('cls' if os.name in ('nt', 'dos') else 'clear')
        self.color = Fore.YELLOW
        self.msg = Fore.CYAN
        self.error = Fore.RED
        self.alphabet = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        self.newBase = ''
        self.size = len(self.alphabet)-1

    def toDecimal(self, number, base):
        """Convierte cualquier base a decimal"""
        toString = ''
        sum = 0
        number = str(number)
        point = number.find('.')
        if point == -1:
            index = len(str(number)) - 1
        else:
            index = point-1
        for num in number:
            if num != '.':
                num = self.alphabet.index(num)
                if (index == 0 and point == -1) or index == -1 * len(number[point+1:]):
                    toString += f'{self.alphabet[num]}({base}^{index})'
                else:
                    toString += f'{self.alphabet[num]}({base}^{index}) + '
                sum += (num * base**index)
                index -= 1
        print(f'{self.color}{toString}')
        self.newBase = str(sum)

    def toBase(self, quotient, base):
        """Convierte decimal a cualquier base"""
        iquotient = int(float(quotient))
        fquotient = float(quotient) - iquotient
        counter = 0
        while(iquotient > 0):
            remainder = iquotient % base
            print(f'{self.color}{iquotient} = {iquotient // base}({base}) + {self.alphabet[remainder]}')
            iquotient //= base
            self.newBase += self.alphabet[remainder]
            counter += 1
        self.newBase = self.newBase[::-1]
        if fquotient != 0:
            counter = 0
            self.newBase += '.'
            while(fquotient != 0 and counter < 20):
                if(fquotient * base >= 1):
                    fquotient -= int(fquotient)
                    self.newBase += self.alphabet[int(fquotient * base)]
                else:
                    self.newBase += '0'
                print(f'{self.color}{round(fquotient, 5)}({base}) = {round(fquotient * base, 4)}')
                fquotient *= base
                counter += 1

if __name__ == '__main__':
    colorama.init(autoreset=True)
    obj = Base()
    obj.clear()


    def isOK(num, numBase:int, newBase:int):
        flag = True
        if not(newBase <= obj.size and newBase >= 2 and numBase >= 2 and numBase <= obj.size):
            flag = False
            print(f'{obj.error}Por favor ingrese una base entre [0-{obj.size}]')
        elif(newBase != 10 and numBase != 10):
            flag = False
            print(f'{obj.error}Al menos una de las bases debe ser 10')
        else:
            abc = '.'
            abc += obj.alphabet[:numBase]
            for item in str(num):
                if item not in abc:
                    flag = False
                    print(f'{obj.error}Por favor ingrese un numero correcto')
                    break
        return flag

    try:
        print(f'{obj.msg}\nPrograma para convertir numeros de cualquier base a decimal o viceversa')
        num = input(obj.msg + 'Ingrese un numero\n')
        numBase = int(input(obj.msg + 'Ingrese su base\n'))
        newBase = int(input(obj.msg + 'Ingrese la base que desea obtener\n'))
        assert (isOK(num, numBase, newBase))
    except AssertionError:
        print(f'{obj.error}Por favor ingrese los valores nuevamente')
    except:
        print(f'{obj.error}Unexpected error: {sys.exc_info()[0]}')
    else:
        if newBase == 10:
            obj.toDecimal(num, numBase)
        else:
            obj.toBase(num, newBase)
        print(f'{obj.color}\n{obj.newBase}')