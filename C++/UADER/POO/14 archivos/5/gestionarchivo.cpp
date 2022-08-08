#include "gestionarchivo.h"
#include <iostream>
#include <fstream>
using namespace std;

struct evento
{
    int nro;
    char descripcion[100];
    char tipo;
    //T es una notificación que se debe escribir en un archivo de texto llamado “notificaciones.txt” en cual se escribe una línea por notificación con el siguiente formato: “nro, descripción del evento”
    //C es una notificación de consola, se debe escribir en consola la notificación con el mismo formato que el tipo anterior
    //B es una notificación la cual debe escribirse en un archivo binario llamado “notificaciones.dat” con el siguiente formato
};

GestionArchivo::GestionArchivo()
{
    this->ruta = "D:\Marcos\GIT\desafios\UADER\POO\14\eventos.dat";
}

void GestionArchivo::leer()
{
    char* buffer;
    ifstream archivo(this->ruta, ios::binary|ios::in);
    long tamanio = archivo.tellg();
    buffer = new char[tamanio];
    archivo.read((char*)& buffer, tamanio);
    if(!archivo.fail()){

    }


}

void GestionArchivo::escribir(){
    ofstream notificacion("notificaciones.txt", ios::app);
    notificacion.write();
}
