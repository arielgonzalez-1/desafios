#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import shutil
import glob
import sys
import pathlib

def file_list(file_ext='txt', dir=None):
    """ Guia 11 - Ejercicio 1
        Lista archivos con una extensión dentro de un directorio determinado.
    """
    if dir:
        os.chdir(dir)
    for f in glob.glob('*.{}'.format(file_ext)):
        yield f


def file_copy(file, dir='BACK'):
    """ Guia 11 - Ejercicio 1
        Realiza la copia de archivos a un directorio, creandolo si no existe.
    """
    file = os.path.abspath(file)
    dir = os.path.join(os.path.dirname(file), dir)
    destino = os.path.join(dir, os.path.basename(file))
    if not os.path.exists(dir):
        pathlib.Path(dir).mkdir(parents=True, exist_ok=True)
    print('Generando copia en:', str(destino))
    shutil.copyfile(file, destino)


def main(argv):
    """ Guia 11 - Ejercicio 1 """

    for d in argv:
        print('Directorio: ', d)
        for f in file_list(dir=d, file_ext='txt'):
            file_copy(f)


if __name__ == '__main__':
    main(sys.argv[1:])