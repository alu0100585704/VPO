/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenFiles;
    QAction *actionSaveFile;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionEscala_de_Grises;
    QAction *actionBrillo;
    QAction *actionContraste;
    QAction *actionHistograma_absoluto;
    QAction *actionHistograma_Acumulativo;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuVentanas;
    QMenu *menuEfectos;
    QMenu *menuInformaci_n;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(646, 437);
        actionOpenFiles = new QAction(MainWindow);
        actionOpenFiles->setObjectName(QString::fromUtf8("actionOpenFiles"));
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionEscala_de_Grises = new QAction(MainWindow);
        actionEscala_de_Grises->setObjectName(QString::fromUtf8("actionEscala_de_Grises"));
        actionBrillo = new QAction(MainWindow);
        actionBrillo->setObjectName(QString::fromUtf8("actionBrillo"));
        actionContraste = new QAction(MainWindow);
        actionContraste->setObjectName(QString::fromUtf8("actionContraste"));
        actionHistograma_absoluto = new QAction(MainWindow);
        actionHistograma_absoluto->setObjectName(QString::fromUtf8("actionHistograma_absoluto"));
        actionHistograma_Acumulativo = new QAction(MainWindow);
        actionHistograma_Acumulativo->setObjectName(QString::fromUtf8("actionHistograma_Acumulativo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menuVentanas = new QMenu(menuBar);
        menuVentanas->setObjectName(QString::fromUtf8("menuVentanas"));
        menuEfectos = new QMenu(menuBar);
        menuEfectos->setObjectName(QString::fromUtf8("menuEfectos"));
        menuInformaci_n = new QMenu(menuBar);
        menuInformaci_n->setObjectName(QString::fromUtf8("menuInformaci_n"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuInformaci_n->menuAction());
        menuBar->addAction(menuEfectos->menuAction());
        menuBar->addAction(menuVentanas->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionOpenFiles);
        menuArchivo->addAction(actionSaveFile);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionExit);
        menuAyuda->addAction(actionAbout);
        menuEfectos->addAction(actionEscala_de_Grises);
        menuEfectos->addAction(actionBrillo);
        menuEfectos->addAction(actionContraste);
        menuInformaci_n->addAction(actionHistograma_absoluto);
        menuInformaci_n->addAction(actionHistograma_Acumulativo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenFiles->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
        actionSaveFile->setText(QApplication::translate("MainWindow", "Salvar", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Salir", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "Acerca de . . .", nullptr));
        actionEscala_de_Grises->setText(QApplication::translate("MainWindow", "Escala de Grises", nullptr));
        actionBrillo->setText(QApplication::translate("MainWindow", "Brillo y Contraste", nullptr));
        actionContraste->setText(QApplication::translate("MainWindow", "Contraste", nullptr));
        actionHistograma_absoluto->setText(QApplication::translate("MainWindow", "Histograma Absoluto", nullptr));
        actionHistograma_Acumulativo->setText(QApplication::translate("MainWindow", "Histograma Acumulativo", nullptr));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", nullptr));
        menuVentanas->setTitle(QApplication::translate("MainWindow", "Ventanas", nullptr));
        menuEfectos->setTitle(QApplication::translate("MainWindow", "Efectos", nullptr));
        menuInformaci_n->setTitle(QApplication::translate("MainWindow", "Ver", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
