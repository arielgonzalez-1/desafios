#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def contador_palabras(PATH):
    cont = 0
    with open(PATH) as f:
        for line in f :
            cont += len(line.split(' '))
    return cont

print(contador_palabras("hello.txt"))