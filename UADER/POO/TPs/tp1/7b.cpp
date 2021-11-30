//Solucion de Andrian, Alexis

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **crear_matriz(int n, int m);
int **llenar_matriz(int **mat, int n,  int m);

int main(){
    srand(time(NULL));
    int x, y;
    cout << "Ingrese cantidad de filas y columnas respectivamente\n\n";
    cin >> x >> y;
    int **mat = crear_matriz(x, y);
    mat = llenar_matriz(mat, x, y);
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
        for(int j = 0; j < m; j++){
            mat[i][j] = 0;
        }
    }
    return mat;
}

int **llenar_matriz(int **mat, int n,  int m){
    int fcentro = n/2;
    int ccentro = m/2;
    while(ccentro < m-1 and ccentro > 0 and fcentro < n-1 and fcentro > 0){
        int dir = rand()%4;
        if(dir==0){ //Izquierda
            ccentro+=1;
        }else if(dir==1){ //Derecha
            ccentro-=1;
        }else if(dir==2){ //Arriba
            fcentro-=1;
        }else if(dir==3){ //Abajo
            fcentro+=1;
        }
        mat[fcentro][ccentro] = 1;
    }
    return mat;
}
