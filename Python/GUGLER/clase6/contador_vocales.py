#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def contador_vocales(PATH):
    vocales = ['a', 'e', 'i', 'o', 'u']
    cont = 0
    with open(PATH) as f:
        for line in f:
            for word in line:
                if word.lower() in vocales:
                    cont += 1
    return cont

print(contador_vocales("hello.txt"))