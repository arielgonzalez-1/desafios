#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int *add(int size, int *vec, int element, int pos);

int main(){
    const int  N = 3;
    int *arr = new int[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        arr[i] = rand()%10 + 1;
    }
    int *aux = add(N, arr, 99, 1);
    for(int i=0;i<N+1;i++){
        cout<<aux[i]<<" ";
    }
    return 0;
}

int *add(int size, int *vec, int element, int pos){
    int *aux = new int[size+1];
    for(int i = 0; i < size; i++){
        if(i != pos)
            aux[i] = vec[i];
        else
            aux[size] = vec[pos];
    }
    aux[pos] = element;
    delete [] vec;
    return aux;
}
