#include <iostream>
#include "persona.h"
#include "agenda.h"
using namespace std;

int main()
{
    Persona p1 = Persona("Marcos Miller", 123456);
    Agenda g1 = Agenda();
    g1.agregar(p1);
    return 0;
}
