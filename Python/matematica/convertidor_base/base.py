#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import colorama
from colorama import Fore
colorama.init(autoreset=True)
class Base:
    """Contiene el alfabeto y convierte distintas bases"""
    def __init__(self):
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
        print(f'{Fore.CYAN}{toString}')
        self.newBase = str(sum)

    def toBase(self, quotient, base):
        """Convierte decimal a cualquier base"""
        iquotient = int(float(quotient))
        fquotient = float(quotient) - iquotient
        counter = 0
        while(iquotient > 0):
            remainder = iquotient % base
            print(f'{Fore.LIGHTBLUE_EX}{iquotient} = {iquotient // base}({base}) + {self.alphabet[remainder]}')
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
                print(f'{Fore.LIGHTCYAN_EX}{round(fquotient, 5)}({base}) = {round(fquotient * base, 4)}')
                fquotient *= base
                counter += 1