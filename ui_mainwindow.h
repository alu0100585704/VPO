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
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuVentanas;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(982, 701);
        actionOpenFiles = new QAction(MainWindow);
        actionOpenFiles->setObjectName(QString::fromUtf8("actionOpenFiles"));
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 982, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menuVentanas = new QMenu(menuBar);
        menuVentanas->setObjectName(QString::fromUtf8("menuVentanas"));
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
        menuBar->addAction(menuVentanas->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionOpenFiles);
        menuArchivo->addAction(actionSaveFile);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionExit);
        menuAyuda->addAction(actionAbout);

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
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", nullptr));
        menuVentanas->setTitle(QApplication::translate("MainWindow", "Ventanas", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
