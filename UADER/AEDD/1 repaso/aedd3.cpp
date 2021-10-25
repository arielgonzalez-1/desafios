#include <iostream>
using namespace std;
void base2(int n);

int main(){
    cout << "Ingrese un numero entero\n";
    int num;
    cin >> num;
    base2(num);
    return 0;
}

void base2(int n){
    if (n!=0){
        base2(n/2);
        cout << n%2;
    }
}
