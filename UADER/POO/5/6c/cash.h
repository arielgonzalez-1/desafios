#ifndef CASH_H
#define CASH_H
#include <iostream>
using namespace std;

class Cash{
private:
    int *billetes = new (int);
    int size;
    int monto;
public:
    Cash(int monto);
    void add(int);
    int *getCash();
    string toString();
};

#endif // CASH_H
