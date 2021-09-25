from math import sqrt

def resolvente(a, b, c=0):
    """
    Función para calcular la resolvente para una ecuación cuadrática.
    """
    if a == 0:
        return None
    discrim = b ** 2 - 4 * a * c
    if discrim == 0:
        return -b / (2 * a), float('nan')
    elif discrim < 0:
        real = b / (2 * a)
        imag = abs(sqrt(-discrim) / (2 * a))
        return real + imag * 1j, -real + imag * 1j
    return (-b + sqrt(discrim)) / 2 * a, (-b - sqrt(discrim)) / 2 * a