#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from persona import Persona

def main():
    persona = Persona("Marcos", "Miller", "Developer", 20, 42573648)
    print(persona.mostrar())
    print("Es mayor?\t", persona.es_mayor())

if __name__ == "__main__":
    main()