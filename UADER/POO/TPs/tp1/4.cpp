//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

#include <iostream>
using namespace std;
int **transpose(int **M, int n, int m);

int main(){
    int n, m;
    cout << "\nIngrese cantidad de filas y columnas respectivamente\n";
    cin >> n >> m;
    int **mat = new int * [n];
        for(int i = 0; i < n; i++){
            mat[i] = new int [m];
            for (int j = 0; j < m; j++){
                cout<<"\nIngrese un elemento en la posicion ("<<i+1<<", "<<j+1<<")\n";
                cin >> mat[i][j];
            }
        }
        int **T = transpose(mat, n, m);
        cout << "\nMatriz transpuesta:\n" << endl;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                cout << T[j][i]<<" ";
            }
            delete [] T[j];
            cout<<"\n";
        }
        delete [] T;
        for(int i = 0; i < n; i++){
            delete [] mat[i];
        }
        delete [] mat;
    return 0;
}

int **transpose(int **M, int n, int m){
    int **T = new int* [m];
    for(int j = 0; j < m; j++){
        T[j] = new int [n];
        for(int i = 0; i < n; i++){
            T[j][i] =  M[i][j];
        }
    }
    return T;
}
