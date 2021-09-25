class Mate:
    """Describe el funcionamiento de la conocida bebida tradicional argentina"""

    def __init__(self, n, duenio, lleno = False):
        self.duenio = duenio
        self.cebadas = n
        self.lleno = lleno

    def cebar(self):
        """Método que llena el mate vacio"""
        if self.lleno == False:
            self.lleno = True
        else:
            print("{0}: ¡Cuidado! ¡Te quemaste!".format(self.duenio))
    
    def beber(self):
        """Método que decrementa cebadas en una unidad  y vacia el mate"""
        if self.lleno == True:
            self.lleno = False
            if self.cebadas == 0:
                print("Advertencia: {0}, el mate está lavado.".format(self.duenio))            
            else:
                self.cebadas -= 1
        else:
            print("{0}: El mate está vacío!".format(self.duenio))

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

def main():
    m = Mate(5, "Marcos")
    n = Mate(2, "Yamila")
    m.beber()
    n.beber()
    print(m)
    print(n)
    while m.cebadas > 0:
        print(m == n)
        m.cebar()
        print(m)
        m.beber()
        print(m)
        input(' --- ')
    return 0

if __name__ == '__main__':
    main()