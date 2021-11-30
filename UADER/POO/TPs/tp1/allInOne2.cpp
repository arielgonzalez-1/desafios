//Andrian Alexis
//Miller Marcos
//Suquilvide Jerónimo

#include<iostream>
#include<time.h>
using namespace std;
int **mat_random(int,int);
int **mat_randomSuma(int,int,int **,int **);
int **transpuesta(int,int,int **);
bool cerrada(int**,int,int);
int **llenar(int, int, int []);
int main()
{
    int opc,filas,columnas;
    do{
        cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout<<"\n1. Realizar matriz de numeros aleatoreos."<<endl;
        cout<<"\n2. Sumar elementos de dos matrices."<<endl;
        cout<<"\n3. Rellenar una matriz con un numero ingresado."<<endl;
        cout<<"\n4. Realizar la transpuesta de una matriz."<<endl;
        cout<<"\n5. Rellenar una matriz con dos numeros aleatoreos."<<endl;
        cout<<"\n6. Determina si una matriz esta cerrada o no."<<endl;
        cout<<"\n7. Obtener una matriz abierta. "<<endl;
        cout<<"\n8. Salir"<<endl;
        cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout<<"\nIngrese una opcion: ";
        cin>>opc;

        if(opc == 1){
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;
            int ** aux = mat_random(filas,columnas);
                for(int i=0;i<filas;i++){
                    for (int j=0;j<columnas;j++){
                        cout<<aux[i][j]<<" ";
                    }
                    delete [] aux[i];
                    cout<<endl;
                }
                delete []aux;
        }
        else if(opc == 2){
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;
            //Creo la primer matriz
            int **mat1 = new int * [filas];
            for(int i=0;i<filas;i++){
                mat1[i] = new int [columnas];
            }
            //Relleno la primer matriz con numeros randoms
            srand(time(NULL));
            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    mat1[i][j] = rand()%5;
                }
            }
            //Muesto la primer matriz
            cout<<"\nMatriz aleatorea 1: "<<endl;
            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    cout<<mat1[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            //Creo la segunda matriz
            cout<<"Matriz aleatorea 2: "<<endl;
            int **mat2 = new int *[filas];
            for(int i=0;i<filas;i++){
                mat2[i] = new int [columnas];
            }
            //Relleno la segunda matriz con numeros randoms

            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    mat2[i][j] = rand()%5;
                }
            }
            //Muesto la segunda matriz
            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    cout<<mat2[i][j]<<" ";
                }
                cout<<"\n";
            }

            int ** auxS = mat_randomSuma(filas,columnas,mat1,mat2);
            cout<<"\n\n Resultado: "<<endl;
                for(int i=0;i<filas;i++){
                    for (int j=0;j<columnas;j++){
                        cout<<auxS[i][j]<<" ";
                    }
                    cout<<endl;
                    delete [] auxS[i];
                    delete [] mat1[i];
                    delete [] mat2[i];
                }
                delete [] auxS;
                delete [] mat1;
                delete [] mat2;
            }

        else if(opc == 3){
            int num[2];
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;
            cout<<"\nIngrese un numero: ";cin>>num[1];
            cout<<"\n\n";
            num[0] = num[1];
            int ** M = llenar(filas,columnas,num);
                for(int i=0;i<filas;i++){
                    for (int j=0;j<columnas;j++){
                        cout<<M[i][j]<<" ";
                    }
                    cout<<endl;
                }
                delete [] M;
            }
        else if(opc == 4){
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;
            int **aux = new int * [filas];
            for(int i=0;i<filas;i++){
                aux[i] = new int[columnas];
            }
            for(int i=0;i<filas;i++){
                for (int j=0;j<columnas;j++){
                    cout<<"\n Ingrese un elemento en la posicion ["<<i<<"]["<<j<<"] :";
                    cin>>aux[i][j];
                }
            }
            //Muestro la matriz ingresada
            cout<<"\nMatiz ingresada: "<<endl;
            for(int i=0;i<filas;i++){
                for (int j=0;j<columnas;j++){
                    cout<<aux[i][j]<<" ";
                }
                cout<<endl;
            }
            int ** transp = transpuesta(filas,columnas,aux);
                cout<<"\nMatriz transpuesta: "<<endl;
                 for(int i=0;i<columnas;i++){
                    for(int j=0;j<filas;j++){
                        cout<<transp[i][j]<<" ";
                    }
                    delete [] transp[i];
                    cout<<"\n";
                }
                 delete []  transp;

                 for(int i=0;i<filas;i++){
                     delete [] aux[i];
                 }
                 delete [] aux;

        }
        else if(opc == 5){
            int num[2];
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;
            cout<<"\nIngrese el primer numero: ";cin>>num[0];
            cout<<"\nIngrese el segundo numero: ";cin>>num[1];
            int ** aleatorea = llenar(filas,columnas,num);
            for(int i=0;i<filas;i++){
                for (int j=0;j<columnas;j++){
                    cout<<aleatorea[i][j]<<" ";
                }
                delete [] aleatorea[i];
                cout<<"\n";
            }
            delete [] aleatorea;
        }
        else if(opc == 6){
            int num[2] = {1,0};
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;
            int **mat = llenar(filas,columnas,num);

            if(cerrada(mat,filas,columnas) == true){
                cout<<"\nLa matriz esta cerrada."<<endl;
            }else{
                cout<<"\nLa matriz no esta cerrada."<<endl;
            }
            cout<<"\nMatriz obtenida: "<<endl;
            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    cout<<mat[i][j]<<" ";
                }
                delete [] mat[i];
                cout<<endl;
            }
            delete [] mat;
        }
        else if(opc == 7){
            int num[2] = {1,0};
            cout<<"\nIngrese la cantidad de filas: ";cin>>filas;
            cout<<"\nIngrese la cantidad de columnas: ";cin>>columnas;

            int **abierta = llenar(filas,columnas,num);
            while(cerrada(abierta,filas,columnas)){
                abierta = llenar(filas,columnas,num);
            }
            cout<<"\nMatriz obtenida: "<<endl;
            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    cout<<abierta[i][j]<<" ";
                }
                delete [] abierta[i];
                cout<<endl;
            }
            delete [] abierta;
        }
        }while(opc != 8);
    return 0;
}

int **mat_random(int filas,int columnas){
    int **mat = new int* [filas];
    for(int i = 0; i < filas; i++){
        mat[i] = new int  [columnas];
    }
    srand(time(NULL));
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            mat[i][j] = rand()%9;
        }
    }
    return mat;
}

int **mat_randomSuma(int filas ,int columnas,int **mat1,int **mat2){
    //Creo la matriz que va a sumar todos esos numeros randoms
    int **suma = new int *[filas];
    for(int i=0;i<filas;i++){
        suma[i] = new int [columnas];
    }
    //La inicializo en cero
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            suma[i][j] = 0;
        }
    }
    //Sumo las dos matrices
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            suma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return suma;
}

int **transpuesta(int filas, int columnas,int ** mat){
    if(filas>columnas || filas == columnas){
        //Creo mat si filas > = columnas
        int **aux2_mas = new int * [filas];
        for(int i=0;i<filas;i++){
            aux2_mas[i] = new int [columnas];
        }
        //Relleno la matriz y guardo los datos de la transpuesta
        for(int i=0;i<filas;i++){
            for (int j=0;j<columnas;j++){
                aux2_mas[j][i] = mat[i][j];
            }
        }
        return aux2_mas;

    }else{
        //Creo el caso contrario
        int **aux2 = new int * [columnas];
        for(int i=0;i<columnas;i++){
            aux2[i] = new int [filas];
        }
        //Relleno la matriz y guardo los datos de la transpuesta
        for(int i=0;i<filas;i++){
            for (int j=0;j<columnas;j++){
                aux2[j][i] = mat[i][j];
            }
        }
        return aux2;
    }
}
bool cerrada(int ** mat ,int filas,int columnas){
    bool arriba, abajo, izquierda, derecha;
        bool cerrada = false;
        for(int i = 1; i < filas-1; i++){
            for(int j = 1; j < columnas-1; j++){
                arriba = abajo = izquierda = derecha = false;
                if(mat[i][j] == 1){
                    if(mat[i+1][j] == 0){
                        derecha = true;}
                    if(mat[i-1][j] == 0){
                        izquierda = true;}
                    if(mat[i][j-1] == 0){
                        arriba = true;}
                    if(mat[i][j+1] == 0){
                        abajo = true;}
                    if(arriba == true and abajo == true and izquierda == true and derecha == true){
                        cerrada = true;
                        i = filas;
                        j = columnas;}
                }
            }
        }
        return cerrada;
}
int **llenar(int filas,int columnas,int num[]){
        int **mat = new int* [filas];
        for(int i = 0; i < filas; i++){
            mat[i] = new int [columnas];
            for(int j = 0; j < columnas; j++){
                mat[i][j] = num[rand()%2];
            }
        }
        return mat;
}
