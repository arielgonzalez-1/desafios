/*Realice una función que dado un vector dinámico de enteros, remueva un elemento pasado por parámetro.*/
#include<iostream>

using namespace std;
int *remueve(int [],int &,int);
int main(){
    int cant = 5,elemento;
    //cout<<"\nIngrese la cantidad de elementos del vector: ";cin>>cant;
    //srand(time(NULL));
    int *vec = new int [cant];
    /*for(int i=0;i<cant;i++){
        vec[i] = rand()%100-1;
    }
    for(int i=0;i<cant;i++){
        cout<<vec[i]<<" ";
    }*/
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 2;
    vec[4] = 5;
    vec[5] = 2;
    //cout<<"\nIngrese el elemento a eliminar: ";cin>>elemento;
    elemento = 2;
    int *vec2 = remueve(vec,elemento,cant);
    for(int i=0;i<cant;i++){
        if(vec2[i] != 0){
            cout<<vec2[i]<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
int *remueve(int vec[],int &elemento, int cant){
    int cont = 0;
    for(int i=0;i<=cant;i++){
        if(vec[i] == elemento){
            cont++;
        }
    }
    int *aux = new int [cant-cont];

    for(int i=0;i<=cant;i++){
        if(vec[i] != elemento){
            aux[i] = vec[i];
        }else{
            aux[i] = vec[i+1];
            i++;
        }
    }
    delete [] vec;
    return aux;
}
