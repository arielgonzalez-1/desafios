#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int fnd(char *vec, char element, int size);
int cont(char * str);
char *del(char *vec, char element);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = del(str, 'a');
    cout << aux;
    return 0;
}

char *del(char *vec, char element){
    int size = cont(vec);
    int repeated = fnd(vec, element, size);
    if(repeated != 0){
        char *aux = new char[size-repeated];
        int j = 0;
        for(int i = 0; i < size; i++){
            if(vec[i] != element){
                aux[j] = vec[i];
                j += 1;
            }    
        }
        delete [] vec;
        return aux;
    }else{
        return vec;
    }
}

int cont(char * str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return ++i;
}

int fnd(char *vec, char element, int size){
    int cont = 0;
    for(int i = 0; i < size; i++){
        if(vec[i] == element)
            cont += 1;
    }
    return cont;
}
