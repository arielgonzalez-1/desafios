class Persona:
    def __init__(self, nombre=None, apellido=None, profesion=None, edad=None, dni=None):
        self.nombre = nombre
        self.apellido = apellido
        self.profesion = profesion
        self.edad = edad
        self.dni = dni

    def es_mayor(self):
        if self.edad >= 18:
            return True

    def mostrar(self):
        return self.nombre + ", " + self.apellido + ", " + self.profesion + ", " + str(self.edad) + ", " + str(self.dni)