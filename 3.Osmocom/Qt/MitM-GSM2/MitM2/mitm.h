#ifndef MITM_H
#define MITM_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MitM;
}

class MitM : public QMainWindow
{
    Q_OBJECT

public:
    explicit MitM(QWidget *parent = 0);
    ~MitM();



private:
    Ui::MitM *ui;

    QString password;
    //QString arguments;


public slots:

    void checkInput();

    void transceiverPressed();
    void btsPressed();
    void bscPressed();
    void wiresharkPressed();
    void sipConnectorPressed();
    void sqlBrowserPressed();


    void pcapSipDumpPressed();
    void slot1Pressed();
    void slot2Pressed();
    void slot3Pressed();
    void slot4Pressed();
    void slot5Pressed();

};

#endif // MITM_H
