//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **crear_matriz(int n, int m);
int **llenar_matriz(int **mat, int n,  int m);
bool is_closed(int **mat, int n, int m);

int main(){
    srand(time(NULL));
    int x, y;
    cout << "Ingrese cantidad de filas y columnas respectivamente\n";
    cin >> x >> y;
    int **mat = crear_matriz(x, y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << mat[i][j] << " ";
        }
        delete [] mat[i];
        cout << endl;
    }
    delete [] mat;
    return 0;
}

int **crear_matriz(int n, int m){
    int **mat = new int* [n];
    for(int i = 0; i < n; i++){
        mat[i] = new int [m];
    }
    do{
        mat = llenar_matriz(mat, n, m);
    }while(is_closed(mat, n, m));
    return mat;
}

int **llenar_matriz(int **mat, int n,  int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%2;
        }
    }
    return mat;
}

bool is_closed(int **mat, int n, int m){
    bool arriba, abajo, izquierda, derecha;
    bool cerrada = false;
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            arriba = abajo = izquierda = derecha = false;
            if(mat[i][j] == 1){
                if(mat[i+1][j] == 0)
                    derecha = true;
                if(mat[i-1][j] == 0)
                    izquierda = true;
                if(mat[i][j-1] == 0)
                    arriba = true;
                if(mat[i][j+1] == 0)
                    abajo = true;
                if(arriba == true and abajo == true and izquierda == true and derecha == true)
                    cerrada = true;
            }
        }

    }
    return cerrada;
}
