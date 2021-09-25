#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def even(MAX):
    for i in range(MAX):
        yield i * 2

if __name__ == "__main__":
    pares = even(100)
    for i in pares:
        print(i)