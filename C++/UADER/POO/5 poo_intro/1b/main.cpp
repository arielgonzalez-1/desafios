#include <iostream>
#include "complejo.h"
using namespace std;

int main(){
    Complejo a = Complejo(3, 2);
    Complejo b = Complejo(-1, 2);
    cout << "A = " << a.toString() << endl;
    cout << "B = " << b.toString() << endl;
    cout << "A + B = " << a.suma(b).toString() << endl;
    cout << "A - B = " << a.resta(b).toString() << endl;
    cout << "A * B = " << a.multi(b).toString() << endl;
    cout << "A / B = " << a.div(b).toString() << endl;
    return 0;
}
