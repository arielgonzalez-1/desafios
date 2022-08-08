//Solucion de Juan Pablo Saluzzo

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int **generar(int f, int c);
int **copiar(int **mat, int n, int m);
bool is_closed(int **mat, int f, int c);
int check(int** mat, int f, int c, int posf, int posc);
void abierta(int **mat, int f, int c);

int main(){
    srand(time(NULL));
    int x, y;
    cout << "Ingrese cantidad de filas y columnas respectivamente\n\n";
    cin >> x >> y;
    cout << endl;
    int **mat  = generar(x, y);
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

int **copiar(int **mat, int n, int m){
    int **aux = new int*[n];
    for(int i=0;i<n;i++){
        aux[i]= new int[m];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            *( *(aux + i) +j) = *( *(mat + i) + j);
        }
    }
    return aux;
}

bool is_closed(int **mat, int f, int c){
    int **aux = copiar(mat, f, c);
    int cont = 0;
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            cont += check(aux,f,c,i,j);
        }
    }
    for(int i = 0; i < f; i++){
        delete [] aux[i];
    }
    delete [] aux;
    return cont == 1;
}

int **generar(int f, int c){
    int **aux = new int *[f];
    for(int x=0;x<f;x++){
        aux[x] = new int [c];
        for(int i=0;i<c;i++){
            aux[x][i]=rand()%2;
        }
    }
    if(!is_closed(aux,f,c)){
        abierta(aux,f,c);
    }
    return aux;
}

void abierta(int **mat, int f, int c){
    //Borra los caminos que no esten conectadoa al primer camino encontrado
    int**aux = copiar(mat,f,c);
    int cont = 0;
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            cont += check(aux,f,c,i,j);
            if(cont > 1){
                check(mat,f,c,i,j);
                cont -= 1;
            }
        }
    }
    for(int i = 0; i < f; i++){
        delete [] aux[i];
    }
    delete[] aux;
}
     
int check(int** mat, int f, int c, int posf, int posc){
    //Se invoca en el primer 1 de la matriz limpiandola, si no, existe un area cerrada
    int cleaned = 0;
    if(mat[posf][posc] == 1){
        mat[posf][posc] = 0;
        cleaned = 1;
        if(posf-1>=0) //arriba
            check(mat,f,c,posf-1,posc);
        if(posf+1<f)  //abajo
            check(mat,f,c,posf+1,posc);
        if(posc+1<c) //izquierda
            check(mat,f,c,posf,posc+1);
        if(posc-1>=0)  //derecha
            check(mat,f,c,posf,posc-1);
    }
    return cleaned;
}
