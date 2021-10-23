#include <iostream>
#include <Cadena.h>

using namespace std;

int main(){
    Cadena unaCadena("ol");
    cout << unaCadena.getSize() << endl;
    cout << unaCadena.getStr() << endl << endl;

    unaCadena.add_start('h');
    cout << unaCadena.getSize() << endl;
    cout << unaCadena.getStr() << endl << endl;

    unaCadena.add_final('a');
    cout << unaCadena.getSize() << endl;
    cout << unaCadena.getStr() << endl << endl;

    unaCadena.uppercase();
    cout << unaCadena.getSize() << endl;
    cout << unaCadena.getStr() << endl << endl;
    return 0;
}
