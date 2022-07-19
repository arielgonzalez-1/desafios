#!/usr/bin/env python3
# -*- coding: utf-8 -*-

datos = [
    75, 89, 66, 52, 90, 68, 83, 94, 77, 60, 63, 77, 31, 88, 74, 37, 85, 76, 74, 63, 38, 47, 87, 65, 97, 49, 65, 72, 73, 81, 69, 72, 91, 87, 76, 58, 63, 70, 72, 65
]
datos.sort()
n = len(datos) #muestra

def media():
    return sum(datos) / n

def es_par():
    return n % 2 == 0

def mediana():
    if es_par:
        return (datos[(n+1)//2] + datos[n//2]) /2
    else:
        return datos[(n+1)/2]

def cuartiles(): #Q1, Q2, Q3, Q4 respectivamente
    #ver como programar percentiles
    if es_par():
        q1 = datos[n//4] + datos[1//4+1]
        q2 = datos[n//2] + datos[n//2 + 1]
        q3 = datos[]
def main():
    print(media())

if __name__ == "__main__":
    main()
