#include "complejo.h"
using namespace std;

double Complejo::getReal() const
{
    return real;
}

void Complejo::setReal(double newReal)
{
    real = newReal;
}

double Complejo::getImag() const
{
    return imag;
}

void Complejo::setImag(double newImag)
{
    imag = newImag;
}

Complejo::Complejo(){}

Complejo::Complejo(double real, double imag) : real(real), imag(imag){}

Complejo Complejo::suma(Complejo c){
    return(Complejo(this->real + c.real , this->imag + c.imag));
}

Complejo Complejo::resta(Complejo c){
    return(Complejo(this->real - c.real , this->imag - c.imag));
}

Complejo Complejo::multi(Complejo x){ //(a + bi)(c + di)
    double a = this->real;
    double b = this->imag;
    double c = x.real;
    double d = x.imag;
    return(Complejo(a*c + -(d*b), a*d + c*b));
}

Complejo Complejo::div(Complejo x){
    double a = this->real;
    double b = this->imag;
    double c = x.real;
    double d = x.imag;
    double deno = c*c + d*d;
    return Complejo((a*c + d*b)/deno,(a*-d + c*b)/deno);
}

const string Complejo::toString(){
    string s = to_string(this->real);
    s.append(" + (");
    s.append(to_string(this->imag));
    s.append("j)");
    return s;
}
