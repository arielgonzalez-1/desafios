#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int fnd(char *vec, char element);

int main(){
    char *str = new char[100];
    cin >> str;
    cout << fnd(str, 'a');
    return 0;
}

int fnd(char *vec, char element){
    bool flag = true;
    int place = -1;
    int index = 0;
    while(vec[index] != '\0' and flag == true){
        if(vec[index] == element){
            place = index;
            flag = false;
        }
        index += 1;
    }
    return place;
}

