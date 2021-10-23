#include <iostream>
#ifndef COMPLEJO_H
#define COMPLEJO_H
using namespace std;

class Complejo{
private:
    double real;
    double imag;
public:
    Complejo();
    Complejo(double real, double imag);
    Complejo(const Complejo&);
    Complejo operator+(const Complejo& f);
    Complejo operator-(const Complejo& f);
    Complejo operator*(const Complejo& f);
    Complejo operator/(const Complejo& f);
    friend ostream& operator<<(ofstream& out, const Complejo& c);
    double getReal() const;
    void setReal(double newReal);
    double getImag() const;
    void setImag(double newImag);
};

#endif // COMPLEJO_H
