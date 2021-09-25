#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

class WithoutEndl:
    """Contiene los parametros pasados por terminal"""
    
    def __init__(self, withEndl):
        self.withEndl = withEndl

    def write_file(self):
        """Itera el objeto devuelto por read_file y escribe en un archivo remplazando fines de linea por espacios"""
        for line in self.read_file():
            with open("replace.txt", 'a') as f:
                    f.write(line.replace("\n", " "))

    def read_file(self):
        """Abre el documento y devuelve un objeto iterable"""
        with open(self.withEndl) as f:
            for line in f:
                yield line

def main(argv):
    """Crea un objeto por cada parametro dado"""
    for i in argv:
        w = WithoutEndl(i)
        w.write_file()

if __name__ == '__main__':
    main(sys.argv[1:])