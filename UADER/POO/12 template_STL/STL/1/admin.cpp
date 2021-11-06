#include "admin.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm>
using namespace std;

Admin::Admin()
{

}

void Admin::generadorEnteros()
{
    srand(time(NULL));
    for(int i = 0; i < 200; ++i){
        enteros.push_back(rand()%100);
    }
}

void Admin::ordenarAscendente()
{
    enteros.sort(); //usar funcion partial_sort
}

void Admin::ordenarDescendente()
{
    enteros.reverse();
}

const string Admin::mostrarEnteros(){
    string str = "";
    for(auto it = enteros.begin(); it != enteros.end(); ++it){
        str.append(to_string(*it));
        str.append(" ");
    }
    str.append("\n\n");
    return str;
}

