#include <iostream>
using namespace std;
int cont(char * str);
char *reverse(char *vec);

int main(){
    char *str = new char[100];
    cin >> str;
    char *aux = reverse(str);
    cout << aux;
    return 0;
}

char *reverse(char *vec){
    int size = cont(vec);
    for(int i = 0, j = size-2; i < (size-2)/2, j >= (size-1)/2; i++, j--){
        char aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux;
    }
    return vec;
}

int cont(char * str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return ++i;
}
