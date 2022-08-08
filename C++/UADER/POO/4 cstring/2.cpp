#include <iostream>
using namespace std;
int cont(char * str);
char *lowercase(char *str);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = lowercase(str);
    cout << aux;
    return 0;
}

char *lowercase(char *str){
    int size = cont(str);
    char *aux = new char[size];
    for(int x = 0; x < size; x++){
        if(str[x] >= 'A' and str[x] <= 'Z')
            aux[x] = str[x] + 32;
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