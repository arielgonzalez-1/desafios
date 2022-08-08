//Andrian, Alexis
//Miller, Marcos
//Suquilvide, Jeronimo

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **random(int n, int m);
int **suma(int** A, int** B, int n, int m);
int **llenar(int n, int m, int num[]);
int **transpose(int **M, int n, int m);
bool is_closed(int **mat, int n, int m);
string mostrarMatriz(int **mat, int n, int m);

int main(){
    srand(time(NULL));
    unsigned int opc;
    do{
        cout<<"\n##################################################\n";
        cout<<"\n1. Realizar matriz de numeros aleatoreos.\n";
        cout<<"\n2. Sumar entre dos matrices.\n";
        cout<<"\n3. Rellenar una matriz con un numero ingresado.\n";
        cout<<"\n4. Realizar la transpuesta de una matriz.\n";
        cout<<"\n5. Rellenar una matriz con dos numeros aleatoreos.\n";
        cout<<"\n6. Determina si una matriz esta cerrada.\n";
        cout<<"\n7. Genera una matriz abierta.\n";
        cout<<"\n8. Salir\n";
        cout<<"\n##################################################\n";
        cin >> opc;

        int n, m;
        if(opc == 1){
            cout << "\nIngrese cantidad de filas y columnas respectivamente\n";
            cin >> n >> m;
            cout << mostrarMatriz(random(n, m), n, m) << endl;
        }
        else if(opc == 2){
            cout << "Ingrese cantidad de filas y columnas respectivamente\n";
            cin >> n >> m;
            int **A = new int* [n];
            int **B = new int* [n];
            for(int i = 0; i < n; i++){
                A[i] = new int [m];
                B[i] = new int [m];
                for(int j = 0; j < m; j++){
                    cout << "\nIngrese elemento (" << i+1 << ", " << j+1 << ") de la matriz ( A )\n";
                    cin >> A[i][j];
                    cout << "\nIngrese elemento (" << i+1 << ", " << j+1 << ") de la matriz ( B ) \n";
                    cin >> B[i][j];
                }
            }
            cout << mostrarMatriz(suma(A, B, n, m), n, m) << endl;
            for(int i = 0; i < n; i++){
                delete [] A[i];
                delete [] B[i];
            }
            delete [] A;
            delete [] B;
        }
        else if(opc == 3){
            int num[2]; 
            cout << "\nIngrese cantidad de filas y columnas respectivamente\n";
            cin >> n >> m;
            cout << "\nIngrese un número a rellenar\n";
            cin >> num[1];
            num[0] = num[1];
            cout << mostrarMatriz(llenar(n, m, num), n, m) << endl;
        }
        else if(opc == 4){
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
            cout << mostrarMatriz(transpose(mat, n, m), m, n) << endl;
            for(int i = 0; i < n; i++){
                delete [] mat[i];
            }
            delete [] mat;
        }
        else if(opc == 5){
            int num[2]; 
            cout << "\nIngrese cantidad de filas y columnas respectivamente\n";
            cin >> n >> m;
            cout << "Ingrese dos números a rellenar\n";
            cin >> num[0] >> num[1];
            cout << mostrarMatriz(llenar(n, m, num), n, m) << endl;
        }
        else if(opc == 6){
            int num[2] = {0, 1}; 
            cout << "\nIngrese cantidad de filas y columnas respectivamente\n";
            cin >> n >> m;
            int **mat = llenar(n, m, num);
            if(is_closed(mat, n, m))
                cout << "\nCerrada\n";
            else
                cout << "\nAbierta\n";
            cout << mostrarMatriz(mat, n, m) << endl;
        }
        else if(opc == 7){
            int num[2] = {0, 1};
            cout << "\nIngrese cantidad de filas y columnas respectivamente\n";
            cin >> n >> m;
            int **mat = llenar(n, m, num);
            while(is_closed(mat, n, m)){
                mat = llenar(n, m, num);
            }
            cout << mostrarMatriz(mat, n, m) << endl;
        }
        else if(opc == 8){
            exit(1);
        }
    }while(true);
    return 0;
}

int **random(int n, int m){
    int **mat = new int* [n];
    for(int i = 0; i < n; i++){
        mat[i] = new int [m];
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%5;
        }
    }
    return mat;
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

int **llenar(int n, int m, int num[]){
    int **mat = new int* [n];
    for(int i = 0; i < n; i++){
        mat[i] = new int [m];
        for(int j = 0; j < m; j++){
            mat[i][j] = num[rand()%2];
        }
    }
    return mat;
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
                if(arriba == true and abajo == true and izquierda == true and derecha == true){
                    cerrada = true;
                    i = n;
                    j = m;
                }
            }
        }

    }
    return cerrada;
}

string mostrarMatriz(int **mat, int n, int m){
    string s = "";
    s.append("\nMatriz obtenida:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            s.append(to_string(mat[i][j]) + " ");
        }
        delete [] mat[i]; //elimino las columnas de la matriz
        s.append("\n");
    }
    delete [] mat; //elimino las filas
    return s;
}
