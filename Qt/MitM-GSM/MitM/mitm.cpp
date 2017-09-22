#include "mitm.h"
#include "ui_mitm.h"

MitM::MitM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MitM)
{
    ui->setupUi(this);



    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(checkInput()));

    connect(ui->pushButtonTransceiver, SIGNAL(clicked()), this, SLOT(transceiverPressed()));
    connect(ui->pushButtonBSC, SIGNAL(clicked()), this, SLOT(bscPressed()));
    connect(ui->pushButtonBTS, SIGNAL(clicked()), this, SLOT(btsPressed()));
    connect(ui->pushButtonSipConnector, SIGNAL(clicked()), this, SLOT(sipConnectorPressed()));
    connect(ui->pushButtonWireshark, SIGNAL(clicked()), this, SLOT(wiresharkPressed()));
}





MitM::~MitM()
{
    delete ui;
}






void MitM::checkInput() {

    password = ui->lineEdit->text();
    //for testing
    //ui->label->setText(password);
}







void MitM::transceiverPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonTransceiver->isChecked()) {

        //exec->start("/home/netpc06/test.sh");
        exec->start("./startTransceiver.sh");
        ui->pushButtonTransceiver->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonTransceiver->setText("Starten");
    }
}







void MitM::bscPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonBSC->isChecked()) {

        //exec->start("sudo", QStringList() << "-A" << password << "nautilus");
        //exec->start("sudo", QStringList() << "-p" << password << "nautilus");
        exec->start("./startOsmoNitb.sh");
        ui->pushButtonBSC->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonBSC->setText("Starten");
    }
}








void MitM::btsPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonBTS->isChecked()) {

        //exec->start("sudo", QStringList() << "nautilus");
        exec->start("./startOsmoBTS.sh");
        ui->pushButtonBTS->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonBTS->setText("Starten");
    }
}








void MitM::wiresharkPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonWireshark->isChecked()) {

        exec->start("./wireshark.sh");
        ui->pushButtonWireshark->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonWireshark->setText("Starten");
    }
}








void MitM::sipConnectorPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonSipConnector->isChecked()) {

        exec->start("./startSipConnector.sh");
        ui->pushButtonSipConnector->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonSipConnector->setText("Starten");
    }
}















