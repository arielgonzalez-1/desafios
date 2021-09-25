#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from base import Base
import sys

if __name__ == '__main__':
    singleton = Base()

    def isOK(num, numBase, newBase):
        flag = True
        if not(newBase <= singleton.size and newBase >= 2 and numBase >= 2 and numBase <= singleton.size):
            flag = False
            print(f'Por favor ingrese una base entre [0-{singleton.size}]')
        else:
            abc = '.'
            abc += singleton.alphabet[:numBase]
            for item in str(num):
                if item not in abc:
                    flag = False
                    print(f'Por favor ingrese un numero correcto')
                    break
        return flag

    try:
        num = input("Ingrese un numero\n")
        numBase = int(input("Ingrese su base\n"))
        newBase = int(input("Por favor ingrese la base a la que desee convertir\n"))
        print('\n'*2)
        assert (isOK(num, numBase, newBase))
    except AssertionError:
        print('\nPor favor ingrese los valores nuevamente\n')
    except:
        print(f"Unexpected error: {sys.exc_info()[0]}")
    else:
        if newBase == 10:
            singleton.toDecimal(num, numBase)
        else:
            singleton.toBase(num, newBase)
        print('\n'*2)
        print(singleton.newBase)