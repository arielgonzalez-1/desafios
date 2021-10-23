#include <iostream>
#include "vectordinamico.h"
using namespace std;

int main(){
    int vec[] = {0, 1, 2};
    VectorDinamico vec1 = VectorDinamico(vec, 3);
    cout << vec1.toString() << "Size: " << vec1.getSize() << endl;
    vec1.add(3);
//    vec1.add(4);
    cout << vec1.toString() << "Size: " << vec1.getSize() << endl;
    return 0;
}
