//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

#include <iostream>
using namespace std;
int **suma(int** A, int** B, int n, int m);

int main(){
    int x, y;
    cout << "Ingrese cantidad de filas y columnas respectivamente\n";
    cin >> x >> y;
    int **A = new int* [x];
    int **B = new int* [x];
    for(int i = 0; i < x; i++){
        A[i] = new int [y];
        B[i] = new int [y];
        for(int j = 0; j < y; j++){
            cout << "\nIngrese elemento (" << i+1 << ", " << j+1 << ") de la matriz ( A )\n";
            cin >> A[i][j];
            cout << "\nIngrese elemento (" << i+1 << ", " << j+1 << ") de la matriz ( B ) \n";
            cin >> B[i][j];
        }
    }
    int **C = suma(A, B, x, y);
    cout << "\nMatriz obtenida:\n";
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << C[i][j] << " ";
        }
        delete [] A[i];
        delete [] B[i];
        delete [] C[i];
        cout << endl;
    }
    delete [] A;
    delete [] B;
    delete [] C;
    return 0;
}

int **suma(int** A, int** B, int n, int m){
    int **C = new int* [n];
    for(int i  = 0; i < n; i++){
        C[i] = new int [m];
        for(int j = 0; j < m; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
