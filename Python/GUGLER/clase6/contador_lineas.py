#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def contador_lineas(PATH):
    cont = 0
    with open(PATH) as f:
        for line in f :
            cont += 1
    return cont

print(contador_lineas("hello.txt"))
