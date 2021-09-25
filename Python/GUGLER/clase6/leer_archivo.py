#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys

def leer_archivo(PATH):
    with open(PATH) as f: #por defecto el modo es r (read)
        return f.read()

#print(leer_archivo("hello.txt"))

""" Codigo Alexis, el archivo es pasado de la forma: python leer_archivo.py hello.txt
def leer_lineas(archivo):
    if os.path.exists(archivo):
        with open(archivo) as f:
            return f.readlines()
    return None


if __name__ == '__main__':
    for f in sys.argv[1:]:
        print(leer_lineas(f))
"""