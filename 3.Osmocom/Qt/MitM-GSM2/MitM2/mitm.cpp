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
    connect(ui->pushButtonSQLBrowser, SIGNAL(clicked()), this, SLOT(sqlBrowserPressed()));


    connect(ui->pushButtonPcap, SIGNAL(clicked()), this, SLOT(pcapSipDumpPressed()));
    connect(ui->pushButtonSlot1, SIGNAL(clicked()), this, SLOT(slot1Pressed()));
    connect(ui->pushButtonSlot2, SIGNAL(clicked()), this, SLOT(slot2Pressed()));
    connect(ui->pushButtonSlot3, SIGNAL(clicked()), this, SLOT(slot3Pressed()));
    connect(ui->pushButtonSlot4, SIGNAL(clicked()), this, SLOT(slot4Pressed()));
    connect(ui->pushButtonSlot5, SIGNAL(clicked()), this, SLOT(slot5Pressed()));
}





MitM::~MitM()
{
    delete ui;
}






void MitM::checkInput() {

    password = ui->lineEdit->text();
}







void MitM::transceiverPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonTransceiver->isChecked()) {

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







void MitM::sqlBrowserPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonSQLBrowser->isChecked()) {

        exec->start("./startSQLBrowser.sh");
        ui->pushButtonSQLBrowser->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonSQLBrowser->setText("Starten");
    }
}






void MitM::pcapSipDumpPressed(){

    QProcess* exec = new QProcess(this);

    if (ui->pushButtonPcap->isChecked()) {

        exec->start("./startPcapSipDump.sh");
        ui->pushButtonPcap->setText("Stoppen");
    }
    else {

        exec->close();
        ui->pushButtonPcap->setText("Starten");
    }
}





void MitM::slot1Pressed(){

    QProcess* exec = new QProcess(this);
    exec->start("./slot1.sh");
}



void MitM::slot2Pressed(){

    QProcess* exec = new QProcess(this);
    exec->start("./slot2.sh");
}



void MitM::slot3Pressed(){

    QProcess* exec = new QProcess(this);
    exec->start("./slot3.sh");
}



void MitM::slot4Pressed(){

    QProcess* exec = new QProcess(this);
    exec->start("./slot4.sh");
}



void MitM::slot5Pressed(){

    QProcess* exec = new QProcess(this);
    exec->start("./slot5.sh");
}
