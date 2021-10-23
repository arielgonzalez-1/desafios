#include "cash.h"
#include <iostream>
using namespace std;

Cash::Cash(int monto) : monto(monto){
    this->size = 0;
}

int *Cash::getCash(){ //Los billetes son de 1000, 500, 200, 100, 50, 20, 10 y monedas de 5, 2, 1
    int i = 0;
    const int cash[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    while(this->monto > 0){
        if(this->monto % cash[i] == this->monto)
            i += 1;
        else{
            int cantidad = this->monto / cash[i];
            for(int x = 1; x <= cantidad; x++){
                add(cash[i]);
                this->size += 1;
            }
            this->monto %= cash[i];
        }
    }
    return billetes;
}

string Cash::toString(){
    string s = "";
    for(int i = 0; i < this->size; i++){
        s.append(to_string(this->billetes[i]) + ", ");
    }
    return s;
}


void Cash::add(int element){
    if(this->size == 0)
       this->billetes[0] = element;
    else{
        int *aux = new int[this->size+1];
        for(int i = 0; i < this->size; i++){
           aux[i] = this->billetes[i];
        }
       aux[this->size] = element;
       this->billetes = &*aux;
       delete [] aux;
    this->size += 1;
    }
}
