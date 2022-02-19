#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from datetime import datetime
import multiprocessing as mp
from multiprocessing import Pool
from math import sqrt
from traceback import print_tb

def is_prime(num: int) -> bool:
    if num % 2 == 0 or num in [0, 1]:
        return False
    else:
        for i in range(3, int(sqrt(num))+1, 2):
            mod = num % i
            if mod == 0:
                return False
    return True

def is_prime_recursive(num, var=3):
    if num == 2:
        prime = True
    elif num in [0, 1] or num % 2 == 0:
        prime = False
    elif var * var > num:
        prime = True
    elif num % var == 0:
        prime = False
    else:
        prime = is_prime_recursive(num, var+2)
    return prime

def print_all(num):
    if is_prime(num):
        print(num)

if __name__ == '__main__':
    # print(sys.getrecursionlimit())
    # sys.setrecursionlimit(99999999)

    x = int(input('Ingresa un numero natural\n'))
    start = datetime.now()
    pool = Pool(processes=mp.cpu_count())
    result = pool.map_async(print_all, range(x))
    result.wait()
    stop = datetime.now()
    print(f'{stop - start}')