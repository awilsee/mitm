/********************************************************************************
** Form generated from reading UI file 'mitm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MITM_H
#define UI_MITM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MitM
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonTransceiver;
    QPushButton *pushButtonBSC;
    QPushButton *pushButtonBTS;
    QPushButton *pushButtonSipConnector;
    QPushButton *pushButtonWireshark;
    QLabel *label_7;
    QPushButton *pushButtonSQLBrowser;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MitM)
    {
        if (MitM->objectName().isEmpty())
            MitM->setObjectName(QString::fromUtf8("MitM"));
        MitM->resize(367, 313);
        centralWidget = new QWidget(MitM);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(240, 10, 101, 27));
        lineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 171, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 111, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 91, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 140, 81, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 180, 111, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 220, 91, 17));
        pushButtonTransceiver = new QPushButton(centralWidget);
        pushButtonTransceiver->setObjectName(QString::fromUtf8("pushButtonTransceiver"));
        pushButtonTransceiver->setGeometry(QRect(240, 50, 99, 27));
        pushButtonTransceiver->setCheckable(true);
        pushButtonBSC = new QPushButton(centralWidget);
        pushButtonBSC->setObjectName(QString::fromUtf8("pushButtonBSC"));
        pushButtonBSC->setGeometry(QRect(240, 90, 99, 27));
        pushButtonBSC->setCheckable(true);
        pushButtonBTS = new QPushButton(centralWidget);
        pushButtonBTS->setObjectName(QString::fromUtf8("pushButtonBTS"));
        pushButtonBTS->setGeometry(QRect(240, 130, 99, 27));
        pushButtonBTS->setCheckable(true);
        pushButtonSipConnector = new QPushButton(centralWidget);
        pushButtonSipConnector->setObjectName(QString::fromUtf8("pushButtonSipConnector"));
        pushButtonSipConnector->setGeometry(QRect(240, 170, 99, 27));
        pushButtonSipConnector->setCheckable(true);
        pushButtonWireshark = new QPushButton(centralWidget);
        pushButtonWireshark->setObjectName(QString::fromUtf8("pushButtonWireshark"));
        pushButtonWireshark->setGeometry(QRect(240, 210, 99, 27));
        pushButtonWireshark->setCheckable(true);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 260, 121, 17));
        pushButtonSQLBrowser = new QPushButton(centralWidget);
        pushButtonSQLBrowser->setObjectName(QString::fromUtf8("pushButtonSQLBrowser"));
        pushButtonSQLBrowser->setGeometry(QRect(240, 250, 99, 27));
        pushButtonSQLBrowser->setCheckable(true);
        MitM->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MitM);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MitM->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MitM);

        QMetaObject::connectSlotsByName(MitM);
    } // setupUi

    void retranslateUi(QMainWindow *MitM)
    {
        MitM->setWindowTitle(QApplication::translate("MitM", "MitM", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MitM", "Administratorpasswort:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MitM", "Transceiver:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MitM", "OsmoBSC:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MitM", "OsmoBTS:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MitM", "Sip-Connector:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MitM", "Wireshark:", 0, QApplication::UnicodeUTF8));
        pushButtonTransceiver->setText(QApplication::translate("MitM", "Starten", 0, QApplication::UnicodeUTF8));
        pushButtonBSC->setText(QApplication::translate("MitM", "Starten", 0, QApplication::UnicodeUTF8));
        pushButtonBTS->setText(QApplication::translate("MitM", "Starten", 0, QApplication::UnicodeUTF8));
        pushButtonSipConnector->setText(QApplication::translate("MitM", "Starten", 0, QApplication::UnicodeUTF8));
        pushButtonWireshark->setText(QApplication::translate("MitM", "Starten", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MitM", "SQLiteBrowser:", 0, QApplication::UnicodeUTF8));
        pushButtonSQLBrowser->setText(QApplication::translate("MitM", "Starten", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MitM: public Ui_MitM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MITM_H
