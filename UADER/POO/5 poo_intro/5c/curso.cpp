#include "curso.h"
#include <iostream>
using namespace std;

Curso::Curso(){}

Curso::Curso(char *newNombre){
    this->nombre = newNombre;
}

char *Curso::getNombre(){
    return this->nombre;
}

void Curso::agregarAlumno(Alumno unAlumno){
    this->alumnos[cantidad] = unAlumno;
    this->cantidad += 1;
}

string Curso::mostrarAlumnos(){
    string s = "";
    for(unsigned int i = 0; i < this->cantidad; i++){
        s.append("Nombre: ");
        s.append(this->alumnos[i].getNombre());
        s.append(", Nota AVG: ");
        s.append(to_string(this->alumnos[i].avg()));
        s.append("\n");
    }
    return s;
}
