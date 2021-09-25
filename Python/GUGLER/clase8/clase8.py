#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
1) - Modelar y codificar una clase Mate que describa el funcionamiento de la conocida bebida tradicional argentina. La clase debe contener los siguientes miembros: •  Un atributo para la cantidad de cebadas restantes hasta que se lava el mate (representada por un número). •  Un atributo para el estado (lleno o vacío). El constructor (__init__()) debe recibir como parámetro n, la cantidad máxima de cebadas en base a la cantidad de yerba vertida en el recipiente. Guardar el archivo del módulo con el nombre Mate.py. 

2) - Escribir un nuevo método denominado cebar (que llena el mate con agua) en el módulo Mate.py. Si se intenta cebar con el mate lleno, se debe emitir un aviso por pantalla con el mensaje ¡Cuidado! ¡Te quemaste!.

3) - Modificar el módulo Mate.py del primer ejercicio para agregar un nuevo método beber, que vacía el mate y le resta una cebada disponible. Si se intenta beber un mate vacío, se debe emitir un aviso por pantalla que el “El mate está vacío!”.

4) - Escribir el código necesario para contemplar la siguiente situación: Es posible seguir cebando y bebiendo el mate aunque no haya cebadas disponibles. En ese caso la cantidad de cebadas restantes se mantendrá en 0, y cada vez que se intente beber se debe imprimir un mensaje de aviso por pantalla: Advertencia: el mate está lavado.

5) - Hacer un nuevo método denominado arreglar en el módulo Mate.py, que permitirá arreglar el mate cambiando la yerba y que debe recibir por parámetro la cantidad de cebadas adicionales según la cantidad de yerba reemplazada en el arreglo.

6) - Agregar a la clase Mate un método especial, llamado __str__ que debe devolver una cadena de caracteres con un mensaje que indique si el mate se encuentra activo (con cebadas disponibles) o desactivado (cebadas disponibles en cero).

7) - Agregar a la clase Mate un método especial, llamado __eq__ que debe devolver true o false teniendo en cuenta la cantidad de cebadas y el estado entre dos instancias de la clase Mate para saber si son iguales. Hacer lo mismo para el método especial __ne__.

8) - Escriba una breve documentación de la clase Mate utilizando el formato docstrings de Python. Finalmente, se le solicita que haga uso y pruebas de la clase Mate.
"""