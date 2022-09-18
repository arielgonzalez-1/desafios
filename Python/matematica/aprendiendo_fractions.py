#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
from fractions import Fraction


"""Aprendiendo fracciones"""
a = Fraction(24, 42)
b = Fraction(-1, 2)
c = Fraction('0.5')
d = Fraction('3.14159265359').limit_denominator(10)
e = Fraction(25, 64)
f = Fraction(8)

print(a)
print(b)
print(c)
print(d)

print(f.denominator)
print(a.numerator)
print(a.denominator)

print(Fraction(math.sqrt(e)))
print(Fraction(b+c))
print(Fraction(b*c))
print(Fraction(e/f))