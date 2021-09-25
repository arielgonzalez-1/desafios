#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def contador_caracteres(PATH):
    cont = 0
    with open(PATH) as f:
        for line in f :
            cont += len(line) #con espacios
            #cont += len(line.replace(' ', '')) #sin espacios
    return cont

print(contador_caracteres("hello.txt"))