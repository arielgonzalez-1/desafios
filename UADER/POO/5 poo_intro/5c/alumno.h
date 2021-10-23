#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno{
private:
    float notas[4];
    char *nombre;
    unsigned int dni;
public:
    Alumno();
    Alumno(unsigned int dni);
    float avg();
    float *getNotas();
    void setNotas(int, float);
    char *getNombre();
    void setNombre(char*);
    unsigned int getDni();
};

#endif // ALUMNO_H
