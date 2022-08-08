#ifndef AGENDA_H
#define AGENDA_H
#include "persona.h"
#include <algorithm>
#include <list>


class Agenda
{
private:
    list<Persona> personas;

public:
    Agenda();
    int buscarTelefono(string);
    void agregar(Persona);
    void eliminar(string);
};

#endif // AGENDA_H
