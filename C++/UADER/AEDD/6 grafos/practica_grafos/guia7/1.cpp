#include <iostream>
#define N 8
using namespace std;

int main(){
    int mat[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mat[i][j] = 0;
        }
    }
    
    mat[1][2] = 1;
    mat[2][3] = 1;
    mat[2][5] = 1;
    mat[3][4] = 1;
    mat[5][3] = 1;
    mat[5][6] = 1;
    mat[6][7] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
