#include <iostream>
#include "complejo.h"

using namespace std;

int main(){
    Complejo a = Complejo(3, 2);
    Complejo b = Complejo(-1, 2);
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "A + B = " << a + b << endl;
    cout << "A - B = " << a - b << endl;
    cout << "A * B = " << a * b << endl;
    cout << "A / B = " << a / b << endl;
    return 0;
}
