#include <iostream>
using namespace std;
int cont(char * str);
char *uppercase(char *str);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = uppercase(str);
    cout << aux;
    return 0;
}

char *uppercase(char *str){
    int size = cont(str);
    char *aux = new char[size];
    for(int x = 0; x < size; x++){
        if(str[x] >= 'a' and str[x] <= 'z')
            aux[x] = str[x] - 32;
        else
            aux[x] = str[x];
    }
    delete [] str;
    return aux;
}

int cont(char * str){
    int i = 0;
    while(str[i] != '\0'){
    i++;
    }
    return ++i;
}