# materiales = ('aluminio', 'alpaca')

class Bombilla:
    def __init__(self, materiales='aluminio'):
        self.materiales = materiales

    def __str__(self):
        return 'Soy una instancia de la clase {}'.format(self.__class__)