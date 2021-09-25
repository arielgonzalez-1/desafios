import sys
from clase5.matematica import *

intro = "INGRESE: \n0 Para salir \n1 Para la suma \n2 Para la resta \n3 Para la division \n4 Para la division entera \n5 Para la potencia \n6 Para la raiz \n7 Para la resolvente \n"

while True:
    print(intro)
    try:
        indice = int(input())
        if indice == 0:
            break
        elif indice == 6:
            a = int(input())
        elif indice == 7:
            a = int(input())
            b = int(input())
            c = int(input())
        else:
            a = int(input())
            b = int(input())
    except:
        print("Por favor ingrese un valor correctamente\nError inesperado:", sys.exc_info()[0])
    else:
        if indice == 1:
            print(suma(a, b))
        elif indice == 2:
            print(resta(a, b))
        elif indice == 3:
            print(cociente(a, b))
        elif indice == 4:
            print(cociente_entero(a, b))
        elif indice == 5:
            print(potencia(a, b))
        elif indice == 6:
            print(raiz_cuadrada(a))
        elif indice == 7:
            print(resolvente(a, b, c))