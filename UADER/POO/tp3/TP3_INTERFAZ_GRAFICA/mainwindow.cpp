#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Simulacion de ciervos colorados");
    miGestor = new GestorArchivos;

    miGestor->getConfig();
    dataConfig datos = miGestor->getConfig();
    this->ui->SpinFilas->setValue(datos.filas);
    this->ui->SpinColumnas->setValue(datos.columnas);
    this->ui->SpinMesetas->setValue(datos.mpasto);
    this->ui->SpinTipoA->setValue(datos.tipoA);
    this->ui->SpinTipoB->setValue(datos.tipoB);
    this->ui->SpinDias->setValue(datos.dias);
    this->ui->SpinTiempo->setValue(datos.tiempo);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GuardarValores_clicked()
{
    dataConfig nuevaConfig;
    nuevaConfig.filas =  this->ui->SpinFilas->text().toInt();
    nuevaConfig.columnas = this->ui->SpinColumnas->text().toInt();
    nuevaConfig.mpasto = this->ui->SpinMesetas->text().toInt();
    nuevaConfig.tipoA = this->ui->SpinTipoA->text().toInt();
    nuevaConfig.tipoB = this->ui->SpinTipoB->text().toInt();
    nuevaConfig.dias = this->ui->SpinDias->text().toInt();
    nuevaConfig.tiempo = this->ui->SpinTiempo->text().toInt();
    miGestor->setConfig(nuevaConfig);
}

void MainWindow::on_Simular_clicked()
{
    dataConfig data;
    data.filas =  this->ui->SpinFilas->text().toInt();
    data.columnas = this->ui->SpinColumnas->text().toInt();
    data.mpasto = this->ui->SpinMesetas->text().toInt();

    data.tipoA = this->ui->SpinTipoA->text().toInt();
    data.tipoB = this->ui->SpinTipoB->text().toInt();


    data.dias = this->ui->SpinDias->text().toInt();
    data.tiempo = this->ui->SpinTiempo->text().toInt();

    miSimulacion = new Simulacion(data.filas,data.columnas,data.mpasto,
                                  data.tipoA,data.tipoB,data.dias,data.tiempo);

    Mostrar_Simulacion * ventana = new Mostrar_Simulacion(this);
    ventana->setModal(true);
    ventana->setSimulacion(miSimulacion);
    ventana->show();
}

void MainWindow::on_RecuperarSimulacion_clicked()
{
    bool estado = miGestor->cargarSimulacion(miSimulacion);
    if(estado){
        Mostrar_Simulacion * ventana = new Mostrar_Simulacion(this);
        ventana->setModal(true);
        ventana->setSimulacion(miSimulacion);

        QMessageBox::StandardButton respuesta1;
        respuesta1 = QMessageBox::information(this,"Simulacion","Simulacion cargada",QMessageBox::Ok);
        if(respuesta1 == QMessageBox::Ok)
            ventana->show();
    }else{
        //QMessageBox::StandardButton respuesta1;
        //respuesta1 =
                QMessageBox::critical(this,"ERROR","No hay simulacion guardada",QMessageBox::Ok);
        //if(respuesta1 == QMessageBox::Ok){}
    }
}
