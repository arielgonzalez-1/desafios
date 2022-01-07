#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math

"""Aprendiendo fracciones"""
# from fractions import Fraction

# a = Fraction(24, 42)
# b = Fraction(-1, 2)
# c = Fraction('0.5')
# d = Fraction('3.14159265359').limit_denominator(10)
# e = Fraction(25, 64)
# f = Fraction(8)
# print(a)
# print(b)
# print(c)
# print(d)
# print(f.denominator)
# print(a.numerator)
# print(a.denominator)
# print(Fraction(math.sqrt(e)))
# print(Fraction(b+c))
# print(Fraction(b*c))
# print(Fraction(e/f))

"""Aprendiendo a manipular decimales con precision"""
# from decimal import *

# print(getcontext())
# getcontext().prec = 6
# print(getcontext())
# print(Decimal(math.pi)
# d1 = Decimal('3.14')
# d2 = Decimal(3.14)
# # print(d1)
# # print(d2)
# print(Decimal('3.1415926535') + Decimal('2.7182818285'))
# getcontext().rounding = ROUND_UP
# print(Decimal('3.1415926535') + Decimal('2.7182818285'))
# data = list(map(Decimal, '1.34 1.87 3.45 2.35 1.00 0.03 9.25'.split()))
# print(max(data))
#quantize() redondea un número a un exponente fijo.
# print(Decimal('7.325').quantize(Decimal('.01'), rounding=ROUND_DOWN))
# print(Decimal('7.325').quantize(Decimal('1.'), rounding=ROUND_UP))
# myothercontext = Context(prec=60, rounding=ROUND_HALF_DOWN)
# setcontext(myothercontext)
# print(getcontext())
# getcontext().clear_flags()
# print(getcontext())

"""Aprendiendo a diferenciar e integrar con sympy"""
# from sympy import *
# x, y, z = symbols("x y z")

# expr = x**2 + 1
# y1 = expr.diff(x)
# y2 = y1.diff(x)
# pprint(expr)
# pprint(y1)


# pprint(y1.subs(x, 5))
# pprint(y1.subs(x, y))
# pprint(y2)

# y = Integral(sqrt(1/x), x)
# pprint(y)
# y = 3*x
# pprint(integrate(y,(x,5,7)))

# expr = Limit(sin(x)/x, x, 0)
# pprint(expr)
# pprint(expr.doit())

# str_expr = "x**2 + 3*x - 1/2"
# expr = sympify(str_expr)
# pprint(expr)
# pprint(simplify((x**3 + x**2 - x - 1)/(x**2 + 2*x + 1)))

# pprint(expand((x + 1)**2))
# pprint(factor(x**3 - x**2 + x - 1))
# pprint(cancel((x**2 + 2*x + 1)/(x**2 + x)))

# M = Matrix([[1, -1], [3, 4], [0, 2]])
# pprint(M)
# print(shape(M))
# pprint(eye(3))
# pprint(zeros(2, 3))
# pprint(ones(2, 3))
# M = Matrix([[1, 0, 1], [2, -1, 3], [4, 3, 2]])
# print(M.det())
# M = Matrix([[1, 0, 1, 3], [2, 3, 4, 7], [-1, -3, -3, -4]])
# pprint(M.rref())

# print(pi.evalf(1000))

# init_session()
