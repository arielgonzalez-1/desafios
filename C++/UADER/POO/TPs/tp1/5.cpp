//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **llenar(int n, int m, int num[]);

int main(){
    int x, y, num[2];
    cout << "Ingrese cantidad de filas y columnas respectivamente\n";
    cin >> x >> y;
    cout << "Ingrese dos números a rellenar\n";
    cin >> num[0] >> num[1];
    int **mat = llenar(x, y, num);
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

int **llenar(int n, int m, int num[]){
    srand(time(NULL));
    int **mat = new int* [n];
    for(int i = 0; i < n; i++){
        mat[i] = new int [m];
        for(int j = 0; j < m; j++){
            mat[i][j] = num[rand()%2];
        }
    }
    return mat;
}
