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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MitM
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *pushButtonWireshark;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonSipConnector;
    QPushButton *pushButtonSQLBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButtonTransceiver;
    QLabel *label_5;
    QPushButton *pushButtonBTS;
    QPushButton *pushButtonBSC;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QPushButton *pushButtonPcap;
    QPushButton *pushButtonSlot1;
    QPushButton *pushButtonSlot2;
    QPushButton *pushButtonSlot3;
    QPushButton *pushButtonSlot4;
    QPushButton *pushButtonSlot5;

    void setupUi(QMainWindow *MitM)
    {
        if (MitM->objectName().isEmpty())
            MitM->setObjectName(QStringLiteral("MitM"));
        MitM->resize(648, 330);
        centralWidget = new QWidget(MitM);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 341, 311));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 171, 17));
        pushButtonWireshark = new QPushButton(groupBox);
        pushButtonWireshark->setObjectName(QStringLiteral("pushButtonWireshark"));
        pushButtonWireshark->setGeometry(QRect(230, 230, 99, 27));
        pushButtonWireshark->setCheckable(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 160, 81, 17));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 240, 91, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 111, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 91, 17));
        pushButtonSipConnector = new QPushButton(groupBox);
        pushButtonSipConnector->setObjectName(QStringLiteral("pushButtonSipConnector"));
        pushButtonSipConnector->setGeometry(QRect(230, 190, 99, 27));
        pushButtonSipConnector->setCheckable(true);
        pushButtonSQLBrowser = new QPushButton(groupBox);
        pushButtonSQLBrowser->setObjectName(QStringLiteral("pushButtonSQLBrowser"));
        pushButtonSQLBrowser->setGeometry(QRect(230, 270, 99, 27));
        pushButtonSQLBrowser->setCheckable(true);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(230, 30, 101, 27));
        lineEdit->setEchoMode(QLineEdit::Password);
        pushButtonTransceiver = new QPushButton(groupBox);
        pushButtonTransceiver->setObjectName(QStringLiteral("pushButtonTransceiver"));
        pushButtonTransceiver->setGeometry(QRect(230, 70, 99, 27));
        pushButtonTransceiver->setCheckable(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 200, 111, 17));
        pushButtonBTS = new QPushButton(groupBox);
        pushButtonBTS->setObjectName(QStringLiteral("pushButtonBTS"));
        pushButtonBTS->setGeometry(QRect(230, 150, 99, 27));
        pushButtonBTS->setCheckable(true);
        pushButtonBSC = new QPushButton(groupBox);
        pushButtonBSC->setObjectName(QStringLiteral("pushButtonBSC"));
        pushButtonBSC->setGeometry(QRect(230, 110, 99, 27));
        pushButtonBSC->setCheckable(true);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 270, 121, 17));
        label->raise();
        pushButtonWireshark->raise();
        label_6->raise();
        label_4->raise();
        pushButtonSipConnector->raise();
        label_3->raise();
        label_2->raise();
        pushButtonSQLBrowser->raise();
        lineEdit->raise();
        pushButtonTransceiver->raise();
        label_5->raise();
        pushButtonBTS->raise();
        pushButtonBSC->raise();
        label_7->raise();
        label->raise();
        pushButtonWireshark->raise();
        label_4->raise();
        label_6->raise();
        label_2->raise();
        label_3->raise();
        pushButtonSipConnector->raise();
        pushButtonSQLBrowser->raise();
        lineEdit->raise();
        pushButtonTransceiver->raise();
        label_5->raise();
        pushButtonBTS->raise();
        pushButtonBSC->raise();
        label_7->raise();
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(360, 10, 281, 311));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 40, 111, 17));
        pushButtonPcap = new QPushButton(groupBox_2);
        pushButtonPcap->setObjectName(QStringLiteral("pushButtonPcap"));
        pushButtonPcap->setGeometry(QRect(170, 40, 89, 25));
        pushButtonPcap->setCheckable(true);
        pushButtonSlot1 = new QPushButton(groupBox_2);
        pushButtonSlot1->setObjectName(QStringLiteral("pushButtonSlot1"));
        pushButtonSlot1->setGeometry(QRect(170, 110, 89, 25));
        pushButtonSlot2 = new QPushButton(groupBox_2);
        pushButtonSlot2->setObjectName(QStringLiteral("pushButtonSlot2"));
        pushButtonSlot2->setGeometry(QRect(170, 150, 89, 25));
        pushButtonSlot3 = new QPushButton(groupBox_2);
        pushButtonSlot3->setObjectName(QStringLiteral("pushButtonSlot3"));
        pushButtonSlot3->setGeometry(QRect(170, 190, 89, 25));
        pushButtonSlot4 = new QPushButton(groupBox_2);
        pushButtonSlot4->setObjectName(QStringLiteral("pushButtonSlot4"));
        pushButtonSlot4->setGeometry(QRect(170, 230, 89, 25));
        pushButtonSlot5 = new QPushButton(groupBox_2);
        pushButtonSlot5->setObjectName(QStringLiteral("pushButtonSlot5"));
        pushButtonSlot5->setGeometry(QRect(170, 270, 89, 25));
        MitM->setCentralWidget(centralWidget);

        retranslateUi(MitM);

        QMetaObject::connectSlotsByName(MitM);
    } // setupUi

    void retranslateUi(QMainWindow *MitM)
    {
        MitM->setWindowTitle(QApplication::translate("MitM", "MitM", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MitM", "GSM-Netz erzeugen", Q_NULLPTR));
        label->setText(QApplication::translate("MitM", "Administratorpasswort:", Q_NULLPTR));
        pushButtonWireshark->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        label_4->setText(QApplication::translate("MitM", "OsmoBTS:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MitM", "Wireshark:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MitM", "Transceiver:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MitM", "OsmoBSC:", Q_NULLPTR));
        pushButtonSipConnector->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonSQLBrowser->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonTransceiver->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        label_5->setText(QApplication::translate("MitM", "Sip-Connector:", Q_NULLPTR));
        pushButtonBTS->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonBSC->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        label_7->setText(QApplication::translate("MitM", "SQLiteBrowser:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MitM", "Gespr\303\244ch aussp\303\244hen", Q_NULLPTR));
        label_8->setText(QApplication::translate("MitM", "PcapSipDump:", Q_NULLPTR));
        pushButtonPcap->setText(QApplication::translate("MitM", "Starten", Q_NULLPTR));
        pushButtonSlot1->setText(QApplication::translate("MitM", "Slot 1", Q_NULLPTR));
        pushButtonSlot2->setText(QApplication::translate("MitM", "Slot 2", Q_NULLPTR));
        pushButtonSlot3->setText(QApplication::translate("MitM", "Slot 3", Q_NULLPTR));
        pushButtonSlot4->setText(QApplication::translate("MitM", "Slot 4", Q_NULLPTR));
        pushButtonSlot5->setText(QApplication::translate("MitM", "Slot 5", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MitM: public Ui_MitM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MITM_H
