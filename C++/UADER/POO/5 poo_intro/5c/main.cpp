#include <iostream>
#include "alumno.h"
#include "curso.h"

using namespace std;

int main(){
    Alumno marcos(42577368);
    marcos.setNotas(0, 100);
    marcos.setNotas(1, 30);
    marcos.setNotas(2, 100);
    marcos.setNotas(3, 90);
    marcos.setNombre("Marcos");

    Alumno javier(39222333);
    javier.setNotas(0, 10);
    javier.setNotas(1, 10);
    javier.setNotas(2, 300);
    javier.setNotas(3, 80);
    javier.setNombre("Javier");

    Alumno angela(42577278);
    angela.setNotas(0, 9.90);
    angela.setNotas(1, 100);
    angela.setNotas(2, 100);
    angela.setNotas(3, 100);
    angela.setNombre("Angela");

    Curso curso("MatematicaDiscreta");
    curso.agregarAlumno(marcos);
    curso.agregarAlumno(javier);
    curso.agregarAlumno(angela);
    cout << curso.mostrarAlumnos();
    return 0;
}
