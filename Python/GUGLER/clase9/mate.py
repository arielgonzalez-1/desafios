from bombilla import Bombilla
from yerba import Yerba

class Mate(Bombilla, Yerba):
    """Describe el funcionamiento de la conocida bebida tradicional argentina"""

    def __init__(self, n, duenio, materiales='plastico', tipos_yerba='sin_yerba', lleno = False):
        Bombilla().__init__(materiales)
        Yerba().__init__(tipos_yerba)
        self.duenio = duenio
        self.cebadas = n
        self.lleno = lleno

    def cebar(self):
        """Método que llena el mate vacio"""
        if self.lleno == False:
            self.lleno = True
        else:
            raise Exception("{0}: ¡Cuidado! ¡Te quemaste!".format(self.duenio))
    
    def beber(self):
        """Método que decrementa cebadas en una unidad  y vacia el mate"""
        if self.lleno == True:
            self.lleno = False
            if self.cebadas == 0:
                raise Exception("Advertencia: {0}, el mate está lavado.".format(self.duenio))            
            else:
                self.cebadas -= 1
        else:
            raise Exception("{0}: El mate está vacío!".format(self.duenio))

    def arreglar(self, n):
        """Arregla el mate lavado"""
        self.cebadas = n
        self.lleno = False

    def __str__(self):
        "Formateo de salida"
        if self.cebadas == 0:
            s = "Mate INACTIVO {1}: cebadas disponibles = {0}".format(self.cebadas, self.duenio)
        else:
            s = "Mate ACTIVO {1}: cebadas disponibles = {0}".format(self.cebadas, self.duenio)
        return s

    def __lt__(self, newMate):
        "Estado entre instancias de Mate"
        return self.cebadas < newMate.cebadas

    def __eq__(self, newMate):
        "Estado entre instancias de Mate"
        return self.cebadas == newMate.cebadas

    def __ne__(self, newMate):
        "Estado entre instancias de Mate"
        return self.cebadas != newMate.cebadas