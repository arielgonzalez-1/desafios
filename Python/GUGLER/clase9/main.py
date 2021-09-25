#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from bombilla import Bombilla
from mate import Mate
from yerba import Yerba

def main():
    # b = Bombilla()
    # y = Yerba()
    m = Mate(3, "Marcos")

    # print(b)
    # print(y)
    # print(b.materiales)
    # print(y.tipos_yerba)

    print(m)
    print(m.duenio)
    m.cebar()
    print(m)
    m.beber()
    print(m)

if __name__ == '__main__':
    main()