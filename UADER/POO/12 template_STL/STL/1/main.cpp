#include <iostream>
#include <admin.h>
using namespace std;

int main()
{
    Admin* obj = new Admin();
    obj->generadorEnteros();
    obj->ordenarAscendente();
    //obj->ordenarDescendente();
    cout << obj->mostrarEnteros();
    return 0;
}
