#ifndef CASILLERO_H
#define CASILLERO_H
#include <pastizal.h>

class Casillero
{
private:
    int tipo;           //1 montania , 2 meseta, 3 meseta con pasto
    Pastizal * pasto;
public:
    Casillero();
    Casillero(int tipo);

    void crearPastizal();

    //Setters
    void setTipo(int tipo);
    void setPastizal(bool estado,int crece,int muere);
    void setEstado(bool estado);
    void setCrece(int x);
    void setMuere(int x);

    //Getters
    int getTipo();
    bool getEstado();
    int getCrece();
    int getMuere();
    bool tienePasto();


    ~Casillero();
};

#endif // CASILLERO_H
