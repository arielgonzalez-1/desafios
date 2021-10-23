#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int fnd(char *vec, char element);
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
    int pos = fnd(vec, element);
    if(pos != -1){
        char *aux = new char[size-1];
        for(int i = 0; i < pos; i++){
            aux[i] = vec[i];
        }
        for(int i = pos+1; i < size; i++){
            aux[i-1] = vec[i];
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

int fnd(char *vec, char element){
    bool flag = true;
    int place = -1;
    int index = 0;
    while(vec[index] != '\0' and flag == true){
        if(vec[index] == element){
            place = index;
            flag = false;
        }
        index += 1;
    }
    return place;
}
