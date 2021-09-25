class Alumno:
    def __init__(self, legajo, n1, n2, n3):
        self.legajo = legajo
        self.n1 = n1
        self.n2 = n2
        self.n3 = n3
        self.avg = (self.n1 + self.n2 + self.n3) / 3

    def estado(self):
        if self.avg < 6:
            return "Libre"
        elif self.avg >= 6 and self.avg <= 8:
            return "Regular"
        elif self.avg > 8:
            return "Promocion"