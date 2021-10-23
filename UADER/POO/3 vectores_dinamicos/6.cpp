#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int *del(int size, int *vec, int element);
int fnd(int size, int *vec, int element, int &cont);
void order(int size, int *vec);

int main(){
    const int N = 10;
    int *arr = new int[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        arr[i] = rand()%3 + 1;
    }
    order(N, arr);
/*
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
*/
    int *aux = del(N, arr, 1);
    return 0;
}

int *del(int size, int *vec, int element){
    int cont;
    int pos = fnd(size, vec, element, cont);
    //cout << "Repetidos: " << cont << endl;
    if(pos == -1)
        return vec;
    else{
        int *aux = new int[size-cont];
        for(int i = 0; i < pos; i++){
            aux[i] = vec[i];
        }
        for(int i = pos+cont; i < size; i++){
            aux[i-cont] = vec[i];
        }
        delete [] vec;
/*
        for(int i = 0; i < size-cont; i++){
            cout << aux[i] << " ";
        }
*/
        return aux;
        }
}

int fnd(int size, int *vec, int element, int &cont){
    int place = -1;
    cont = 0;
    for(int i = size-1; i >= 0; i--){
        if(vec[i] == element){
            place = i;
            cont += 1;
        }
    }
    return place;
}

void order(int size, int *vec){
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(vec[i] > vec[j]){
                int iaux = vec[i];
                vec[i] = vec[j];
                vec[j] = iaux;
            }
        }
    }
}
