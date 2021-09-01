#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

class Base:
    """Contiene el alfabeto y convierte distintas bases"""
    def __init__(self):
        self.alphabet = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        self.newBase = ''
        self.size = len(self.alphabet)-1

    def toBase(self, quotient, base):
        """Algoritmo iterativo para convertir de decimal a cualquier base"""
        iquotient = int(quotient)
        fquotient = quotient - iquotient

        while(iquotient > 0):
            remainder = iquotient % base
            print(f'{iquotient} = {iquotient // base} * {base} + {self.alphabet[remainder]}')
            iquotient //= base
            self.newBase += self.alphabet[remainder]

        self.newBase = self.newBase[::-1]

        if fquotient != 0:
            print('\n'*2)
            counter = 0
            self.newBase += '.'
            while(fquotient != 0 and counter < 20):
                if(fquotient * base >= 1):
                    fquotient = fquotient - int(fquotient)
                    self.newBase += self.alphabet[int(fquotient * base)]
                else:
                    self.newBase += '0'
                print(f'{round(fquotient, 5)} * {base} = {round(fquotient * base, 4)}')
                fquotient *= base
                counter += 1

def main():
    singleton = Base()
    try:
        newQuotient = float(input("Por favor ingrese un numero en base 10\n"))
        newBase = int(input("Por favor ingrese una base\n"))
        print('\n'*2)
        assert (newBase <= singleton.size and newBase >= 2), 'Por favor ingrese una base correcta'
    except AssertionError:
        print(f'Por favor ingrese una base entre [0-{singleton.size}]')
    except:
        print(f"Unexpected error: {sys.exc_info()[0]}")
    else:
        singleton.toBase(newQuotient, newBase)
        print('\n'*2)
        print(singleton.newBase)

if __name__ == '__main__':
    main()
