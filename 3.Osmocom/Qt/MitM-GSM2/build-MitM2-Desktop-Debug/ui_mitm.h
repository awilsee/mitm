/********************************************************************************
** Form generated from reading UI file 'mitm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MITM_H
#define UI_MITM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
            MitM->setObjectName(QStringLiteral("MitM"));
        MitM->resize(367, 313);
        centralWidget = new QWidget(MitM);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(240, 10, 101, 27));
        lineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 171, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 111, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 91, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 140, 81, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 180, 111, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 220, 91, 17));
        pushButtonTransceiver = new QPushButton(centralWidget);
        pushButtonTransceiver->setObjectName(QStringLiteral("pushButtonTransceiver"));
        pushButtonTransceiver->setGeometry(QRect(240, 50, 99, 27));
        pushButtonTransceiver->setCheckable(true);
        pushButtonBSC = new QPushButton(centralWidget);
        pushButtonBSC->setObjectName(QStringLiteral("pushButtonBSC"));
        pushButtonBSC->setGeometry(QRect(240, 90, 99, 27));
        pushButtonBSC->setCheckable(true);
        pushButtonBTS = new QPushButton(centralWidget);
        pushButtonBTS->setObjectName(QStringLiteral("pushButtonBTS"));
        pushButtonBTS->setGeometry(QRect(240, 130, 99, 27));
        pushButtonBTS->setCheckable(true);
        pushButtonSipConnector = new QPushButton(centralWidget);
        pushButtonSipConnector->setObjectName(QStringLiteral("pushButtonSipConnector"));
        pushButtonSipConnector->setGeometry(QRect(240, 170, 99, 27));
        pushButtonSipConnector->setCheckable(true);
        pushButtonWireshark = new QPushButton(centralWidget);
        pushButtonWireshark->setObjectName(QStringLiteral("pushButtonWireshark"));
        pushButtonWireshark->setGeometry(QRect(240, 210, 99, 27));
        pushButtonWireshark->setCheckable(true);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 260, 121, 17));
        pushButtonSQLBrowser = new QPushButton(centralWidget);
        pushButtonSQLBrowser->setObjectName(QStringLiteral("pushButtonSQLBrowser"));
        pushButtonSQLBrowser->setGeometry(QRect(240, 250, 99, 27));
        pushButtonSQLBrowser->setCheckable(true);
        MitM->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MitM);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MitM->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MitM);

        QMetaObject::connectSlotsByName(MitM);
    } // setupUi

    void retranslateUi(QMainWindow *MitM)
    {
        MitM->setWindowTitle(QApplication::translate("MitM", "MitM", Q_NULLPTR));
        label->setText(QApplication::translate("MitM", "Administratorpasswort:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MitM", "Transceiver:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MitM", "OsmoBSC:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MitM", "OsmoBTS:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MitM", "Sip-Connector:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MitM", "Wireshark:", Q_NULLPTR));
        pushButtonTransceiver->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonBSC->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonBTS->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonSipConnector->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonWireshark->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        label_7->setText(QApplication::translate("MitM", "SQLiteBrowser:", Q_NULLPTR));
        pushButtonSQLBrowser->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MitM: public Ui_MitM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MITM_H
