#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from math import sqrt

class Factor:

    def __init__(self):
        self.factores = [2, 3, 5, 7, 11, 13, 17, 19]
    
    def es_primo(self, p):
        aux = self.factores[-1]
        while(aux < int(sqrt(p))):
            for x in self.factores:
                if p % x == 0:
                    return False
                else:
                        aux += 1

def main():
    num = 7
    es_primo()