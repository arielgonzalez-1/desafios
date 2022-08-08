#include "poblacion.h"

Poblacion::Poblacion()
{

}

//para crear poblacion desde cero
Poblacion::Poblacion(char tipo)
{
    this->sincomer = 0;
    this->tipo = tipo;
}

//Para saber si comio o no, si comio recarga vida
void Poblacion::setComio(bool x)
{
    if(x==false){
        sincomer++;
    }else
        sincomer=0;
}

//SETEAN ATRIBUTOS POBLACION
void Poblacion::setsincomer(int x)
{
    this->sincomer = x;
}

void Poblacion::setCoordX(int coordX){ this->coordX = coordX; }

void Poblacion::setCoordY(int coordY){ this->coordY = coordY; }

void Poblacion::setTipo(char tipo){ this->tipo = tipo; }
//

//Getters con los que interactua simulacion y gestorarchivos para guardar las poblaciones
int Poblacion::getSincomer(){ return sincomer; }

int Poblacion::getCoordX(){ return coordX; }

int Poblacion::getCoordY(){ return coordY; }

char Poblacion::getTipo(){ return tipo; }
