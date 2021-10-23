#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int cont(char * str);
char *del(char *vec, int pos);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = del(str, 1);
    cout << aux;
    return 0;
}

char *del(char *vec, int pos){
    int size = cont(vec);
    char *aux = new char[size-pos];
    for(int i = pos; i < size; i++){
        aux[i-pos] = vec[i];
    }
    aux[size] = '\0';
    delete [] vec;
    return aux;
}

int cont(char * str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return ++i;
}
