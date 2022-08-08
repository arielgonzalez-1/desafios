#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>


class Complejo{
private:
    double real;
    double imag;
public:
    Complejo();
    Complejo(double real, double imag);
    Complejo suma(Complejo);
    Complejo resta(Complejo);
    Complejo multi(Complejo);
    Complejo div(Complejo);
    const std::string toString();
    double getReal() const;
    void setReal(double newReal);
    double getImag() const;
    void setImag(double newImag);
};

#endif // COMPLEJO_H
