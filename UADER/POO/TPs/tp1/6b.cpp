//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

//Solucion que SI contempla bordes

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **llenar(int n, int m);
bool is_closed(int **mat, int n, int m);

int main(){
    int x, y;
    cout << "Ingrese cantidad de filas y columnas respectivamente\n";
    cin >> x >> y;
    int **mat = llenar(x, y);
    if(is_closed(mat, x, y))
        cout << "\nCerrada\n";
    else
        cout << "\nAbierta\n";
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

int **llenar(int n, int m){
    srand(time(NULL));
    int **mat = new int* [n];
    for(int i = 0; i < n; i++){
        mat[i] = new int [m];
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%2;
        }
    }
    return mat;
}

bool is_closed(int **mat, int n, int m){
    bool izquierda, derecha, abajo, arriba;
    bool cerrada = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            izquierda = derecha = abajo = arriba = false;
            if(mat[i][j] == 1){
                if(i == 0 and j == 0){
                    if(mat[i+1][j] == 0)
                        derecha = true;
                    if(mat[i][j+1] == 0)
                        abajo = true;
                    if(abajo == true and derecha == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else if(i == 0 and j == m-1){
                    if(mat[i+1][j] == 0)
                        derecha = true;
                    if(mat[i][j-1] == 0)
                        arriba = true;
                    if(arriba == true and derecha == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }

                }else if(i == n-1 and j == 0){
                    if(mat[i-1][j] == 0)
                        izquierda = true;
                    if(mat[i][j+1] == 0)
                        abajo = true;
                    if(abajo == true and izquierda == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else if(i == n-1 and j == m-1){
                    if(mat[i-1][j] == 0)
                        izquierda = true;
                    if(mat[i][j-1] == 0)
                        arriba = true;
                    if(arriba == true and izquierda == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else if(i == 0){
                    if(mat[i+1][j] == 0)
                        derecha = true;
                    if(mat[i][j-1] == 0)
                        arriba = true;
                    if(mat[i][j+1] == 0)
                        abajo = true;
                    if(arriba == true and abajo == true and derecha == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else if(j == 0){
                    if(mat[i+1][j] == 0)
                        derecha = true;
                    if(mat[i-1][j] == 0)
                        izquierda = true;
                    if(mat[i][j+1] == 0)
                        abajo = true;
                    if(abajo == true and izquierda == true and derecha == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else if(j == m-1){
                    if(mat[i+1][j] == 0)
                        derecha = true;
                    if(mat[i-1][j] == 0)
                        izquierda = true;
                    if(mat[i][j-1] == 0)
                        arriba = true;
                    if(arriba == true and izquierda == true and derecha == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else if(i == n-1){
                    if(mat[i-1][j] == 0)
                        izquierda = true;
                    if(mat[i][j-1] == 0)
                        arriba = true;
                    if(mat[i][j+1] == 0)
                        abajo = true;
                    if(arriba == true and abajo == true and izquierda == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }else{
                    if(mat[i+1][j] == 0)
                        derecha = true;
                    if(mat[i-1][j] == 0)
                        izquierda = true;
                    if(mat[i][j-1] == 0)
                        arriba = true;
                    if(mat[i][j+1] == 0)
                        abajo = true;
                    if(arriba == true and abajo == true and izquierda == true and derecha == true){
                        cerrada = true;
                        i = n;
                        j = m;
                    }
                }
            }
        }
    }
    return cerrada;
}
