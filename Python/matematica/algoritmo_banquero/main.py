#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import colorama
from colorama import Fore
from terminaltables import SingleTable
import numpy as np

class Main:
    def __init__(self):
        self.clear = lambda: os.system('cls' if os.name in ('nt', 'dos') else 'clear')
        self.procesos = None
        self.recursos = None
        self.existentes = None
        self.disponibles = None
        self.solicitudes = None
        self.asignados = None
        self.necesidades = None

    def show_matrix(self, color: str, nombre: str, mat: np.ndarray) -> None:
        newmat = []
        aux = mat.copy()
        if aux.ndim > 1:
            for f in aux:
                newmat.append(f)
        table_instance = SingleTable(newmat, nombre)
        print(f"{color}{table_instance.table}")

    def input_matrix(self, color: str, tipo: str) -> None:
        # self.clear()
        nombres = {
            "1": "Vector de Recursos Disponibles",
            "2": "Matriz de Solicitudes",
            "3": "Matriz de Asignacion"
        }
        nombre = nombres[tipo]

        matrices = {
            "1": "self.disponibles",
            "2": "self.solicitudes",
            "3": "self.asignados"
        }
        matriz = eval(matrices[tipo])
        print(f"{color}Ingrese {nombre}:\n")
        if tipo == "1":
            for c in range(self.recursos):
                flag = True
                while flag:
                    try:
                        matriz[c] = int(input(f"{Fore.YELLOW}Ingrese un valor para [{c+1}]\n"))
                    except ValueError:
                        # self.clear()
                        print(f"{Fore.RED}\nIngrese el valor nuevamente\n")
                    else:
                        flag = False
                        # self.clear()
        else:
            for f in range(self.procesos):
                for c in range(self.recursos):
                    flag = True
                    while flag:
                        try:
                            matriz[f][c]= int(input(f"{Fore.YELLOW}Ingrese un valor para [{f+1},{c+1}]\n"))
                        except ValueError:
                            # self.clear()
                            print(f"{Fore.RED}\nIngrese el valor nuevamente\n")
                        else:
                            flag = False
                            # self.clear()
        self.show_matrix(color, nombre, matriz)
        # print(f"{color}{nombre}:")
        # print(f"{color}{matriz}")
        flag = None
        while flag != "yes":
            try:
                flag = str(input(f"{Fore.YELLOW}\nLa matriz es correcta? [yes/no]\n"))
                if flag == "yes":
                    # self.clear()
                    continue
                elif flag == "no":
                    self.input_matrix(color, tipo)
                else:
                    # self.clear()
                    raise ValueError(f"{Fore.RED}\nIngrese el valor nuevamente\n")                    
            except ValueError as e:
                print(e)

    def run(self) -> None:
        try:
            # self.clear()
            self.procesos = int(input(f"{Fore.YELLOW}Ingrese cantidad de procesos involucrados:\n"))
            self.recursos = int(input(f"{Fore.YELLOW}\nIngrese cantidad de recursos involucrados:\n"))
            # self.clear()
        except (KeyError, ValueError):
            print(f"{Fore.RED}\nIngrese el valor nuevamente\n")
        else:
            self.existentes = np.zeros((self.recursos), dtype=int)
            self.disponibles = np.zeros((self.recursos), dtype=int)
            self.solicitudes = np.zeros((self.procesos, self.recursos), dtype=int)
            self.asignados = np.zeros((self.procesos, self.recursos), dtype=int)
            self.necesidades = np.zeros((self.procesos, self.recursos), dtype=int)
            for i, color in enumerate([Fore.GREEN, Fore.CYAN, Fore.MAGENTA]):
                self.input_matrix(color, str(i+1))
        finally:
            while True:
                try:
                    flag = input(f"{Fore.YELLOW}\nDesea continuar? [yes/no]\n")
                    if flag == "yes":
                        self.run()
                    elif flag == "no":
                        exit()
                    else:
                        # self.clear()
                        raise ValueError(f"{Fore.RED}\nIngrese el valor nuevamente\n")
                except ValueError as e:
                    print(e)

if __name__ == '__main__':
    colorama.init(autoreset=True)
    main = Main()
    main.run()