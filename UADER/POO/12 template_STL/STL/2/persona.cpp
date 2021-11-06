#include "persona.h"

int Persona::getTelefono() const
{
    return telefono;
}

void Persona::setTelefono(int newTelefono)
{
    telefono = newTelefono;
}

const string &Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

const string &Persona::getCorreo() const
{
    return correo;
}

void Persona::setCorreo(const string &newCorreo)
{
    correo = newCorreo;
}

const string &Persona::getNacimiento() const
{
    return nacimiento;
}

void Persona::setNacimiento(const string &newNacimiento)
{
    nacimiento = newNacimiento;
}

int Persona::getId() const
{
    return id;
}

Persona::Persona(string newNombre, int newTelefono)
{
    this->nombre = newNombre;
    this->telefono = newTelefono;
}
