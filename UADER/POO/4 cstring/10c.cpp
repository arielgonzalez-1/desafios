#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int fnd(char *vec, char element);
int cont(char * str);
char *ocurrencias(char *vec, char element);

int main(){
    char *str = new char[100];
    cin.getline(str, 100);
    char *aux = ocurrencias(str, 'a');
    return 0;
}

char *ocurrencias(char *vec, char element){
    int pos = fnd(vec, element);
    int space = fnd(vec, ' ');
    while(space != -1){

    }
    char *aux = new char[size-1];
    delete [] vec;
    return aux;
}

int cont(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return ++i;
}

int fnd(char *vec, char element){
    int index = 0;
    int pos = -1;
    while(vec[index] != '\0'){
        if(vec[index] == element){
            pos = index;
            return pos;
        }
        index += 1;
    }
    return pos;
}
