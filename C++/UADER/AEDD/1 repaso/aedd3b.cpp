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
    while(n > 0){
        cout << n % 2;
        n/=2;
    }
}
