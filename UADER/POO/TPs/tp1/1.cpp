//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **random(int n, int m);

int main(){
    int x, y;
    cout << "Ingrese cantidad de filas y columnas respectivamente\n";
    cin >> x >> y;
    int **mat = random(x, y);

    cout << "\nMatriz obtenida:\n";
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

int **random(int n, int m){
    srand(time(NULL));
    int **mat = new int* [n];
    for(int i = 0; i < n; i++){
        mat[i] = new int [m];
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%10;
        }
    }
    return mat;
}
