#include <iostream>
using namespace std;
int cont(char * str);
char *add(char *str, char element);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = add(str, 's');
    cout << aux;
    return 0;
}

char *add(char *str, char element){
    int size = cont(str);
    char *aux = new char[size];
    for(int x = 0; x < size; x++){
        aux[x+1] = str[x];
    }
    aux[0] = element;
    aux[size] = '\0';    
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