#include "alumno.h"

float *Alumno::getNotas(){
    return this->notas;
}

void Alumno::setNotas(int index, float newNotas){
    this->notas[index] = newNotas;
}

char *Alumno::getNombre(){
    return this->nombre;
}

void Alumno::setNombre(char *newNombre){
    this->nombre = newNombre;
}

unsigned int Alumno::getDni(){
    return this->dni;
}

Alumno::Alumno(){}

Alumno::Alumno(unsigned int dni) : dni(dni){}

float Alumno::avg(){
    float aux = 0;
    for(int i = 0; i < 4; i++){
        aux += this->notas[i];
    }
    return aux / 4;
}
