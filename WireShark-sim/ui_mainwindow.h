/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *showWidget;
    QLabel *label;
    QComboBox *netDevsCombo;
    QLabel *label_2;
    QPushButton *startBtn;
    QPushButton *finishBtn;
    QTreeWidget *protoWidget;
    QTextEdit *textEdit;
    QLineEdit *filterLineEdit;
    QPushButton *clearBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1164, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        showWidget = new QTableWidget(centralWidget);
        showWidget->setObjectName(QStringLiteral("showWidget"));
        showWidget->setGeometry(QRect(40, 130, 1091, 271));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(570, 10, 61, 21));
        netDevsCombo = new QComboBox(centralWidget);
        netDevsCombo->setObjectName(QStringLiteral("netDevsCombo"));
        netDevsCombo->setGeometry(QRect(570, 40, 511, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 10, 51, 21));
        startBtn = new QPushButton(centralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(40, 80, 121, 31));
        finishBtn = new QPushButton(centralWidget);
        finishBtn->setObjectName(QStringLiteral("finishBtn"));
        finishBtn->setGeometry(QRect(180, 80, 121, 31));
        protoWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        protoWidget->setHeaderItem(__qtreewidgetitem);
        protoWidget->setObjectName(QStringLiteral("protoWidget"));
        protoWidget->setGeometry(QRect(40, 410, 1091, 171));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 590, 1091, 131));
        filterLineEdit = new QLineEdit(centralWidget);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));
        filterLineEdit->setGeometry(QRect(40, 40, 511, 20));
        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setGeometry(QRect(320, 80, 121, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1164, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\275\221\345\215\241", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\277\207\346\273\244", Q_NULLPTR));
        startBtn->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        finishBtn->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", Q_NULLPTR));
        clearBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
