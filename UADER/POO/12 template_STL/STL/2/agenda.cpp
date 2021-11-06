#include "agenda.h"
#include "persona.h"
#include <algorithm>

Agenda::Agenda()
{

}

int Agenda::buscarTelefono(string nombre)
{
    int retorno = -1;
    for(Persona p : personas){
        if(p.getNombre() == nombre)
            retorno = p.getTelefono();
    }
    return retorno;
}

void Agenda::agregar(Persona obj)
{
    this->personas.push_back(obj);
}

void Agenda::eliminar(string nombre)
{
    if(this->personas.empty() == false){
        for(Persona p : personas){
            if(p.getNombre() == nombre)
               this->personas.remove(p);
        }
    }else{
        //lanzar excepcion
    }
}
