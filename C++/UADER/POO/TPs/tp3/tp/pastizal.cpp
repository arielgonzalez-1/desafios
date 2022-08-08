#include "pastizal.h"

//para crear
Pastizal::Pastizal()
{
    this->estado = true;
    this->crece = 0;
    this->muere = 10;
}

//para cargar
Pastizal::Pastizal(bool estado, int crece, int muere)
{
    this->estado = estado;
    this->crece = crece;
    this->muere = muere;
}

//para cambiar desde simulacion
void Pastizal::setEstado(bool estado){ this->estado = estado; }

void Pastizal::setCrece(int crece){ this->crece = crece; }

void Pastizal::setMuere(int muere){ this->muere = muere; }

//getters
bool Pastizal::getEstado(){ return estado; }

int Pastizal::getCrece(){ return crece; }

int Pastizal::getMuere(){ return muere; }
