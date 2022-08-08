#include <iostream>
#include "cash.h"
using namespace std;

int main(){
    Cash c1 = Cash(545);
    c1.getCash();
    cout << c1.toString() << endl;
    return 0;
}

/* prueba.cpp
#include <iostream>
using namespace std;

int main(){
    int monto = 545;
    int i = 0;
    string s = "";
    const int cash[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    while(monto > 0){
        if(monto % cash[i] == monto)
            i += 1;
        else{
            s.append(to_string(cash[i]) + "*");
            s.append(to_string(monto / cash[i]));
            s.append(", ");
            monto %= cash[i];
        }
    }
    cout << s;
}
*/
