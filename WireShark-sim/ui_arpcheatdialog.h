/********************************************************************************
** Form generated from reading UI file 'arpcheatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARPCHEATDIALOG_H
#define UI_ARPCHEATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArpCheatDialog
{
public:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *targetIp;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *targetMac;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *gateIp;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *gateMac;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *ArpCheatDialog)
    {
        if (ArpCheatDialog->objectName().isEmpty())
            ArpCheatDialog->setObjectName(QStringLiteral("ArpCheatDialog"));
        ArpCheatDialog->resize(502, 376);
        startBtn = new QPushButton(ArpCheatDialog);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(400, 40, 81, 31));
        stopBtn = new QPushButton(ArpCheatDialog);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setGeometry(QRect(400, 100, 81, 31));
        layoutWidget = new QWidget(ArpCheatDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 13, 361, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        targetIp = new QLineEdit(layoutWidget);
        targetIp->setObjectName(QStringLiteral("targetIp"));

        horizontalLayout->addWidget(targetIp);

        layoutWidget1 = new QWidget(ArpCheatDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 60, 361, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        targetMac = new QLineEdit(layoutWidget1);
        targetMac->setObjectName(QStringLiteral("targetMac"));

        horizontalLayout_2->addWidget(targetMac);

        layoutWidget2 = new QWidget(ArpCheatDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 100, 361, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        gateIp = new QLineEdit(layoutWidget2);
        gateIp->setObjectName(QStringLiteral("gateIp"));

        horizontalLayout_3->addWidget(gateIp);

        layoutWidget3 = new QWidget(ArpCheatDialog);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 130, 361, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        gateMac = new QLineEdit(layoutWidget3);
        gateMac->setObjectName(QStringLiteral("gateMac"));

        horizontalLayout_4->addWidget(gateMac);

        textBrowser = new QTextBrowser(ArpCheatDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 190, 361, 161));

        retranslateUi(ArpCheatDialog);

        QMetaObject::connectSlotsByName(ArpCheatDialog);
    } // setupUi

    void retranslateUi(QDialog *ArpCheatDialog)
    {
        ArpCheatDialog->setWindowTitle(QApplication::translate("ArpCheatDialog", "Dialog", Q_NULLPTR));
        startBtn->setText(QApplication::translate("ArpCheatDialog", "\345\274\200\345\247\213", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("ArpCheatDialog", "\345\201\234\346\255\242", Q_NULLPTR));
        label->setText(QApplication::translate("ArpCheatDialog", "\347\233\256\346\240\207IP ", Q_NULLPTR));
        label_2->setText(QApplication::translate("ArpCheatDialog", "\347\233\256\346\240\207MAC", Q_NULLPTR));
        label_3->setText(QApplication::translate("ArpCheatDialog", "\347\275\221\345\205\263IP ", Q_NULLPTR));
        label_4->setText(QApplication::translate("ArpCheatDialog", "\347\275\221\345\205\263MAC", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ArpCheatDialog: public Ui_ArpCheatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARPCHEATDIALOG_H
