#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int *del(int size, int *vec, int pos);
int fnd(int size, int *vec, int element);

int main(){
    const int N = 10;
    int *arr = new int[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        //arr[i] = rand()%10 + 1;
        arr[i] = i;
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int *aux = del(N, arr, fnd(N, arr, 7));
    for(int i = 0; i < N-1; i++){
        cout << aux[i] << " ";
    }
    return 0;
}

int *del(int size, int *vec, int pos){
    if(pos == -1)
        return vec;
    else{
        int *aux = new int[size-1];
        for(int i = 0; i < pos; i++){
            aux[i] = vec[i];
        }
        for(int i = pos+1; i < size; i++){
            aux[i-1] = vec[i];
        }
        delete [] vec;
        return aux;
    }
}

int fnd(int size, int *vec, int element){
    int place = -1;
    for(int i = 0; i < size; i++){
        if(vec[i] == element){
            place = i;
            i = size;
        }
    }
    return place;
}
