#include <iostream>
#define N 34
using namespace std;
typedef unsigned int ui;

int main(){
    float avg = 0;
    struct planilla{
        ui dni[N];
        float parcial[N][4];
    }alumno;
    
    for(int i = 0; i < N; i++){
        cout << "Ingrese DNI\n";
        cin >> alumno.dni[i];
        for(int j = 1; j <= 3; j++){
            ui nota;
            cout << "Ingrese parcial " << j << "\n";
            cin >> nota;
            alumno.parcial[i][j] = nota;
            avg += nota;
        }
    }

    avg /= (N*3);

    for(int i = 0; i < N; i++){
        bool flag = true;
        for(int j = 1; j <= 3; j++){
            if(alumno.parcial[i][j] <= avg)
                flag = false;
        }
        if(flag)
            cout << alumno.dni[i] << endl;
    }

    return 0;
}
