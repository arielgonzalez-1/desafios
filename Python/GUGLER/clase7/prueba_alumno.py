#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from alumno import Alumno

def main():
    alumno1 = Alumno(29343123, 10, 10, 10)
    alumno2 = Alumno(25456656, 6, 3, 9)
    alumno3 = Alumno(45788546, 3, 3, 1)

    print(alumno1.estado(), alumno2.estado(), alumno3.estado())

if __name__ == "__main__":
    main()