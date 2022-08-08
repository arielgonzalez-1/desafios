#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 6
using namespace std;
void ordenamiento_lineal(int vector[]);
void max_min(int vec[], int &max, int &min);

int main(){
    srand(time(NULL));
    int arr[N], total = 0;
    for(int i = 0; i < N; i++){
        int random = rand()%101;
        //cout << random << endl;
        arr[i] = random;
        total += random;
    }
    float avg = total / N;
    cout << "AVG:" << avg << endl;
    ordenamiento_lineal(arr);/*
    for(int i = 0; i < N; i++){
        cout << arr[i] << endl;
    }*/
    unsigned int pos = N / 2;
    if(N % 2 == 1)
        cout << "Elemento Medio\t" << arr[pos] << endl;
    else
        cout << "Elemento Medio\t" << arr[pos-1] << ", " << arr[pos] << endl;
    int mayor, menor;
    max_min(arr, mayor, menor);
    cout << "Maximo/Minimo: " << mayor << "/" << menor << endl;
    return 0;
}

void ordenamiento_lineal(int vector[]){
    for(int i = 0; i < N-1; i++){ //i es el indice del elemento anterior
        for(int j = i+1; j < N; j++){ //j es el indice del elemento siguiente
            if(vector[i] > vector[j]){ //orden ASCENDENTE; para orden descendente usar "<"
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void max_min(int vec[], int &max, int &min){
    max = vec[N-1];
    min = vec[0];
}
