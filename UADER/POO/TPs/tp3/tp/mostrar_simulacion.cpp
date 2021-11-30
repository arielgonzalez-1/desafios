#include "mostrar_simulacion.h"
#include "ui_mostrar_simulacion.h"
#include <time.h>
#include <unistd.h>


Mostrar_Simulacion::Mostrar_Simulacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mostrar_Simulacion)
{
    ui->setupUi(this);
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(iteracionMapa()));
}

Mostrar_Simulacion::~Mostrar_Simulacion()
{
    delete ui;
}

void Mostrar_Simulacion::setSimulacion(Simulacion *simulacion)
{
    this->simulacion = simulacion;

    this->labels = new QLabel**[simulacion->getFilas()];

        for (int i = 0; i < simulacion->getFilas(); i++) {
            this->labels[i] = new QLabel*[simulacion->getColumnas()];
            for (int j = 0; j < simulacion->getColumnas(); j++) {

                    this->labels[i][j] = new QLabel();

                    this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
            }
        }

        timer->setInterval(3000 * simulacion->getTiempo());

        timer->start(1000); // Valor > mas lento

        this->ui->progressBar->setValue(0);
        this->ui->progressBar->setRange(0,simulacion->getTiempo());

        this->DiasQuePasaron = simulacion->getDiaActual() ;
        this->ui->LCDDias->display(DiasQuePasaron+1);
}

void Mostrar_Simulacion::iteracionMapa()
{
    this->ui->SalirSimulacion->setEnabled(false);
    this->ui->GuardarSimulacion->setEnabled(false);
    this->ui->EjecutarSimulacion->setEnabled(false);

    int nro = this->ui->progressBar->value();

    this->ui->progressBar->setValue(nro+1);

    mostrar();

    if(nro == simulacion->getTiempo()){

        simulacion->ControlSimulacion();
        mostrar();
        DiasQuePasaron++;

        this->ui->progressBar->setValue(0);

        this->timer->start(1000);

        this->ui->LCDDias->display(DiasQuePasaron+1);
    }
    if(DiasQuePasaron == simulacion->getCantDias()){
        this->timer->stop();

        QMessageBox::StandardButton respuesta1;
        respuesta1 = QMessageBox::warning(this,"Simulacion","Simulacion Finalizada",QMessageBox::Ok);
        if(respuesta1 == QMessageBox::Ok){
            simulacion->~Simulacion();
            close();
        }
    }
}

void Mostrar_Simulacion::mostrar()
{
    this->ui->lcdTipoA->display(simulacion->getCantA());
    this->ui->lcdTipoB->display(simulacion->getCantB());

    QFont f = {"Arial",14};
        for (int i = 0; i < simulacion->getFilas(); i++) {
            for (int j = 0; j < simulacion->getColumnas(); j++) {

                this->labels[i][j]->clear();
                this->labels[i][j]->setFont(f);

                if(simulacion->getTipoCasillero(i,j) == 1)
                    this->labels[i][j]->setText("███");

                if(simulacion->tienePasto(i,j) == true){ //TIENE PASTO

                    if(simulacion->getEstadoPastizal(i,j) == true)
                        this->labels[i][j]->setText("▓");
                    else
                        this->labels[i][j]->setText("░");

                    for(int l=0;l<simulacion->getCantPoblaciones();l++){
                        if(simulacion->getPoblacion(l,i,j) != 'N'){
                            this->labels[i][j]->setText( labels[i][j]->text() +
                                                         QString(QChar::fromLatin1(simulacion->getPoblacion(l,i,j))));
                        }
                    }
                }else { //NO TIENE PASTO
                    for(int l=0;l<simulacion->getCantPoblaciones();l++){
                        if(simulacion->getPoblacion(l,i,j) != 'N'){
                            this->labels[i][j]->setText( labels[i][j]->text() +
                                                         QString(QChar::fromLatin1(simulacion->getPoblacion(l,i,j))));
                        }
                    }
                }
                this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
                ui->gridLayout->setAlignment(labels[i][j],Qt::AlignHCenter);

            }
        }
}

void Mostrar_Simulacion::TM()
{

}

void Mostrar_Simulacion::on_GuardarSimulacion_clicked()
{
    simulacion->setDiaActual(DiasQuePasaron);
    miGestor->guardarSimulacion(simulacion);
    QMessageBox::information(this,"Simulacion","Guardado con exito!!!",QMessageBox::Ok);
}

void Mostrar_Simulacion::on_PausarSimulacion_clicked()
{
    this->timer->stop();
    this->ui->PausarSimulacion->setEnabled(false);
    this->ui->SalirSimulacion->setEnabled(true);
    this->ui->GuardarSimulacion->setEnabled(true);
    this->ui->EjecutarSimulacion->setEnabled(true);
}

void Mostrar_Simulacion::on_EjecutarSimulacion_clicked()
{
    this->timer->start();
    this->ui->PausarSimulacion->setEnabled(true);
}

void Mostrar_Simulacion::on_SalirSimulacion_clicked()
{
    this->timer->stop();
    simulacion->~Simulacion();
    close();
}
