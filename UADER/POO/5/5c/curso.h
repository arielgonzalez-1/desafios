#ifndef CURSO_H
#define CURSO_H
#include "alumno.h"
#include <iostream>
using namespace std;

class Curso{
private:
    char *nombre;
    Alumno alumnos[20];
    unsigned int cantidad = 0;
public:
    Curso();
    Curso(char *newNombre);
    char *getNombre();
    void agregarAlumno(Alumno);
    string mostrarAlumnos();
};

#endif // CURSO_H
