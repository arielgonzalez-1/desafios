#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sympy import *


"""Aprendiendo a diferenciar e integrar con sympy"""
x, y, z = symbols("x y z")

expr = x**2 + 1
y1 = expr.diff(x)
y2 = y1.diff(x)
pprint(expr)
pprint(y1)

pprint(y1.subs(x, 5))
pprint(y1.subs(x, y))
pprint(y2)

y = Integral(sqrt(1/x), x)
pprint(y)
y = 3*x
pprint(integrate(y,(x,5,7)))

expr = Limit(sin(x)/x, x, 0)
pprint(expr)
pprint(expr.doit())

str_expr = "x**2 + 3*x - 1/2"
expr = sympify(str_expr)
pprint(expr)
pprint(simplify((x**3 + x**2 - x - 1)/(x**2 + 2*x + 1)))

pprint(expand((x + 1)**2))
pprint(factor(x**3 - x**2 + x - 1))
pprint(cancel((x**2 + 2*x + 1)/(x**2 + x)))

M = Matrix([[1, -1], [3, 4], [0, 2]])
pprint(M)
print(shape(M))
pprint(eye(3))
pprint(zeros(2, 3))
pprint(ones(2, 3))
M = Matrix([[1, 0, 1], [2, -1, 3], [4, 3, 2]])
print(M.det())
M = Matrix([[1, 0, 1, 3], [2, 3, 4, 7], [-1, -3, -3, -4]])
pprint(M.rref())

print(pi.evalf(1000))

# init_session()