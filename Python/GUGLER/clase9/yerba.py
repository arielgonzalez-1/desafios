# tipos_yerba = ('sin palo', 'con palo', 'con hierbas')

class Yerba:
    def __init__(self, tipos_yerba='sin palo'):
        self.tipos_yerba = tipos_yerba

    def __str__(self):
        return 'Soy una instancia de la clase {}'.format(self.__class__)
