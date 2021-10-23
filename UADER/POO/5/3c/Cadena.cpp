#include "Cadena.h"

char *Cadena::getStr() const{
    return str;
}

int Cadena::getSize() const{
    return size;
}

Cadena::Cadena(char *str){
    this->str = str;
    while(this->str[this->size]!= '\0'){
        this->size += 1;
    }
    this->size += 1;
}

int Cadena::find(char element){
    bool flag = true;
    int place = -1;
    int index = 0;
    while(this->str[index] != '\0' and flag == true){
        if(this->str[index] == element){
            place = index;
            flag = false;
        }
        index += 1;
    }
    return place;
}

void Cadena::add_final(char element){
    char *aux = new char[this->size+1];
    for(int x = 0; x < this->size; x++){
        aux[x] = this->str[x];
    }
    aux[this->size] = element;
    aux[this->size] = '\0';
    this->str = aux;
    this->size += 1;
    delete [] aux;
}

void Cadena::add_start(char element){
    char *aux = new char[this->size];
    for(int x = 0; x < this->size; x++){
        aux[x+1] = this->str[x];
    }
    aux[0] = element;
    aux[this->size] = '\0';
    this->str = aux;
    this->size += 1;
    delete [] aux;
}

void Cadena::remove(char element){
    int pos = find(element);
    if(pos != -1){
        char *aux = new char[this->size-1];
        for(int i = 0; i < pos; i++){
            aux[i] = this->str[i];
        }
        for(int i = pos+1; i < size; i++){
            aux[i-1] = this->str[i];
        }
        this ->size -= 1;
        this->str = aux;
        delete [] aux;
    }
}

void Cadena::uppercase(){
    char *aux = new char[size];
    for(int x = 0; x < size; x++){
        if(this->str[x] >= 'a' and this->str[x] <= 'z')
            aux[x] = this->str[x] - 32;
        else
            aux[x] = this->str[x];
    }
    this->str = aux;
    delete [] aux;
}
