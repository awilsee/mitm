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

};

#endif // MITM_H
