#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
def concatenar(PATH, PATH2, TO):
    with open(PATH, 'r') as f:
        f1 = f.read()
    with open(PATH2, 'r') as f:
        f2 = f.read()
    with open(TO, 'w') as wf:
        wf.write(f1 + "\n" + f2)

if __name__ == '__main__':
    concatenar(sys.argv[1], sys.argv[2], "concatenado.txt")