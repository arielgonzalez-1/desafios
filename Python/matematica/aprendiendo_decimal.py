#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
from decimal import Context, Decimal, getcontext, setcontext


"""Aprendiendo a manipular decimales con precision"""
print(getcontext())
getcontext().prec = 6
print(getcontext())
print(Decimal(math.pi))
d1 = Decimal('3.14')
d2 = Decimal(3.14)
print(d1)
print(d2)
print(Decimal('3.1415926535') + Decimal('2.7182818285'))
getcontext().rounding = 'ROUND_UP'
print(Decimal('3.1415926535') + Decimal('2.7182818285'))
data = list(map(Decimal, '1.34 1.87 3.45 2.35 1.00 0.03 9.25'.split()))
print(max(data))
#quantize() #redondea un número a un exponente fijo.
print(Decimal('7.325').quantize(Decimal('.01'), rounding='ROUND_DOWN'))
print(Decimal('7.325').quantize(Decimal('1.'), rounding='ROUND_UP'))
myothercontext = Context(prec=60, rounding='ROUND_HALF_DOWN')
setcontext(myothercontext)
print(getcontext())
getcontext().clear_flags()
print(getcontext())