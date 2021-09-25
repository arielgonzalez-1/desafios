#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def escribir_archivo(FILE, PATH):
    with open(PATH, 'w') as wf:
        wf.write(FILE)

def leer_archivo(PATH):
    with open(PATH) as f: #por defecto el modo es r (read)
        return f.read()

def convertir_mayusculas(PATH, TO):
    f = leer_archivo(PATH)
    f = f.upper()
    escribir_archivo(f, TO)
    return f

convertir_mayusculas("hello.txt", "HELLO.txt")