#ifndef ADMIN_H
#define ADMIN_H
#include <list>
#include <iostream>
using namespace std;

class Admin
{
private:
    list<int> enteros;
public:
    Admin();
    void generadorEnteros();
    void ordenarAscendente();
    void ordenarDescendente();
    const string mostrarEnteros();
};

#endif // ADMIN_H
