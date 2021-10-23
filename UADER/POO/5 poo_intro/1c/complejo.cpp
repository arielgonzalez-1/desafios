#include "complejo.h"
using namespace std;

Complejo::Complejo(){}

double Complejo::getReal() const{
    return this->real;
}

void Complejo::setReal(double newReal){
    this->real = newReal;
}

double Complejo::getImag() const{
    return this->imag;
}

void Complejo::setImag(double newImag){
    this->imag = newImag;
}

Complejo::Complejo(double real, double imag) : real(real), imag(imag){}

Complejo Complejo::operator+(const Complejo& f){
    return(Complejo(this->real + f.real , this->imag + f.imag));
}

Complejo Complejo::operator-(const Complejo& f){
    return(Complejo(this->real - f.real , this->imag - f.imag));
}
Complejo Complejo::operator*(const Complejo& f){
    double a = this->real;
    double b = this->imag;
    double c = f.real;
    double d = f.imag;
    return(Complejo(a*c + -(d*b), a*d + c*b));
}

Complejo Complejo::operator/(const Complejo& f){
    double a = this->real;
    double b = this->imag;
    double c = f.real;
    double d = f.imag;
    double deno = c*c + d*d;
    return Complejo((a*c + d*b)/deno,(a*-d + c*b)/deno);
}

ostream& operator<<(ostream& out, const Complejo& f){
    out << f.real << " + (" << f.imag << "j)";
    return out;
}
