#ifndef MOSTRAR_SIMULACION_H
#define MOSTRAR_SIMULACION_H

#include <QDialog>
#include <simulacion.h>
#include<QLabel>
#include <QTimer>
#include <gestorarchivos.h>
#include <QMessageBox>

namespace Ui {
class Mostrar_Simulacion;
}

class Mostrar_Simulacion : public QDialog
{
    Q_OBJECT

public:
    explicit Mostrar_Simulacion(QWidget *parent = nullptr);
    ~Mostrar_Simulacion();
    void setSimulacion(Simulacion * simulacion);

private slots:

    void iteracionMapa();
    void mostrar();
    void TM();
    void on_GuardarSimulacion_clicked();

    void on_PausarSimulacion_clicked();

    void on_EjecutarSimulacion_clicked();

    void on_SalirSimulacion_clicked();

private:
    Ui::Mostrar_Simulacion *ui;
    Simulacion * simulacion = NULL;
    QLabel *** labels;
    QTimer * timer = NULL;
    int DiasQuePasaron = 0;
    GestorArchivos * miGestor = NULL;
};

#endif // MOSTRAR_SIMULACION_H
