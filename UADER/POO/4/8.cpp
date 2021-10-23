#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
char *del(char *vec, int posi, int posf);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = del(str, 1, 4);
    cout << aux;
    return 0;
}

char *del(char *vec, int posi, int posf){
    char *aux = new char[posf-posi+1];
    for(int i = posi; i <= posf; i++){
        aux[i-posi] = vec[i];
    }
    aux[posf+1] = '\0';
    delete [] vec;
    return aux;
}
