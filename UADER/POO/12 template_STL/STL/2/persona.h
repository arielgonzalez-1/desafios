#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <algorithm>
using namespace std;


class Persona
{
private:
    int id;
    int telefono;
    string nombre;
    string correo;
    string nacimiento; //ddmmaaaa
public:
    Persona(string, int);
    int getTelefono() const;
    void setTelefono(int newTelefono);
    const string &getNombre() const;
    void setNombre(const string &newNombre);
    const string &getCorreo() const;
    void setCorreo(const string &newCorreo);
    const string &getNacimiento() const;
    void setNacimiento(const string &newNacimiento);
    int getId() const;
    void setId(int newId);
};

#endif // PERSONA_H
