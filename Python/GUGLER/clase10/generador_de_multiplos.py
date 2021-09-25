#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def multiplos(NUM, MAX):
    """ Guia 10 - Ejercicio 4 """
    for i in range(MAX+1):
        yield i * NUM


def main():
    for p in multiplos(2, 10):
        print(p)


if __name__ == '__main__':
    main()
