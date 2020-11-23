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
    QAction *actionBrilloyContraste;
    QAction *actionHistograma_absoluto;
    QAction *actionHistograma_Acumulativo;
    QAction *actionNTSC8Bits;
    QAction *actionPAL8Bits;
    QAction *actionEntropia;
    QAction *actionGamma;
    QAction *actionEcualizar;
    QAction *actionEspecificacion;
    QAction *actionRGB32_NTSC;
    QAction *actionRGB32_PAL;
    QAction *actionLineal;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuVentanas;
    QMenu *menuEfectos;
    QMenu *menuEscala_de_Grises;
    QMenu *menuHistograma;
    QMenu *menuInformaci_n;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(930, 696);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionOpenFiles = new QAction(MainWindow);
        actionOpenFiles->setObjectName(QString::fromUtf8("actionOpenFiles"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Recursos/iconos/abir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFiles->setIcon(icon);
        actionOpenFiles->setIconVisibleInMenu(true);
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Recursos/iconos/save_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveFile->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionBrilloyContraste = new QAction(MainWindow);
        actionBrilloyContraste->setObjectName(QString::fromUtf8("actionBrilloyContraste"));
        actionHistograma_absoluto = new QAction(MainWindow);
        actionHistograma_absoluto->setObjectName(QString::fromUtf8("actionHistograma_absoluto"));
        actionHistograma_Acumulativo = new QAction(MainWindow);
        actionHistograma_Acumulativo->setObjectName(QString::fromUtf8("actionHistograma_Acumulativo"));
        actionNTSC8Bits = new QAction(MainWindow);
        actionNTSC8Bits->setObjectName(QString::fromUtf8("actionNTSC8Bits"));
        actionPAL8Bits = new QAction(MainWindow);
        actionPAL8Bits->setObjectName(QString::fromUtf8("actionPAL8Bits"));
        actionEntropia = new QAction(MainWindow);
        actionEntropia->setObjectName(QString::fromUtf8("actionEntropia"));
        actionGamma = new QAction(MainWindow);
        actionGamma->setObjectName(QString::fromUtf8("actionGamma"));
        actionEcualizar = new QAction(MainWindow);
        actionEcualizar->setObjectName(QString::fromUtf8("actionEcualizar"));
        actionEspecificacion = new QAction(MainWindow);
        actionEspecificacion->setObjectName(QString::fromUtf8("actionEspecificacion"));
        actionRGB32_NTSC = new QAction(MainWindow);
        actionRGB32_NTSC->setObjectName(QString::fromUtf8("actionRGB32_NTSC"));
        actionRGB32_PAL = new QAction(MainWindow);
        actionRGB32_PAL->setObjectName(QString::fromUtf8("actionRGB32_PAL"));
        actionLineal = new QAction(MainWindow);
        actionLineal->setObjectName(QString::fromUtf8("actionLineal"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menuVentanas = new QMenu(menuBar);
        menuVentanas->setObjectName(QString::fromUtf8("menuVentanas"));
        menuEfectos = new QMenu(menuBar);
        menuEfectos->setObjectName(QString::fromUtf8("menuEfectos"));
        menuEscala_de_Grises = new QMenu(menuEfectos);
        menuEscala_de_Grises->setObjectName(QString::fromUtf8("menuEscala_de_Grises"));
        menuHistograma = new QMenu(menuEfectos);
        menuHistograma->setObjectName(QString::fromUtf8("menuHistograma"));
        menuInformaci_n = new QMenu(menuBar);
        menuInformaci_n->setObjectName(QString::fromUtf8("menuInformaci_n"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

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
        menuEfectos->addAction(menuEscala_de_Grises->menuAction());
        menuEfectos->addAction(actionBrilloyContraste);
        menuEfectos->addAction(actionGamma);
        menuEfectos->addAction(menuHistograma->menuAction());
        menuEscala_de_Grises->addAction(actionNTSC8Bits);
        menuEscala_de_Grises->addAction(actionPAL8Bits);
        menuEscala_de_Grises->addAction(actionRGB32_NTSC);
        menuEscala_de_Grises->addAction(actionRGB32_PAL);
        menuHistograma->addAction(actionEcualizar);
        menuHistograma->addAction(actionEspecificacion);
        menuInformaci_n->addAction(actionHistograma_absoluto);
        menuInformaci_n->addAction(actionHistograma_Acumulativo);
        menuInformaci_n->addAction(actionEntropia);
        toolBar->addAction(actionOpenFiles);
        toolBar->addAction(actionSaveFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenFiles->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpenFiles->setToolTip(QApplication::translate("MainWindow", "Cargar Imagen", nullptr));
#endif // QT_NO_TOOLTIP
        actionSaveFile->setText(QApplication::translate("MainWindow", "Salvar", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveFile->setToolTip(QApplication::translate("MainWindow", "Guardar imagen en fichero", nullptr));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Salir", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "Acerca de . . .", nullptr));
        actionBrilloyContraste->setText(QApplication::translate("MainWindow", "Brillo y Contraste", nullptr));
        actionHistograma_absoluto->setText(QApplication::translate("MainWindow", "Histograma Absoluto", nullptr));
        actionHistograma_Acumulativo->setText(QApplication::translate("MainWindow", "Histograma Acumulativo", nullptr));
        actionNTSC8Bits->setText(QApplication::translate("MainWindow", "8 bit NTSC", nullptr));
        actionPAL8Bits->setText(QApplication::translate("MainWindow", "8 bit PAL", nullptr));
        actionEntropia->setText(QApplication::translate("MainWindow", "Entrop\303\255a(Solo Gris)", nullptr));
        actionGamma->setText(QApplication::translate("MainWindow", "Funcion Gamma", nullptr));
        actionEcualizar->setText(QApplication::translate("MainWindow", "Ecualizar", nullptr));
        actionEspecificacion->setText(QApplication::translate("MainWindow", "Especificaci\303\263n", nullptr));
        actionRGB32_NTSC->setText(QApplication::translate("MainWindow", "RGB32 NTSC", nullptr));
        actionRGB32_PAL->setText(QApplication::translate("MainWindow", "RGB32 PAL", nullptr));
        actionLineal->setText(QApplication::translate("MainWindow", "Lineal", nullptr));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", nullptr));
        menuVentanas->setTitle(QApplication::translate("MainWindow", "Ventanas", nullptr));
        menuEfectos->setTitle(QApplication::translate("MainWindow", "Efectos", nullptr));
        menuEscala_de_Grises->setTitle(QApplication::translate("MainWindow", "Escala de Grises", nullptr));
        menuHistograma->setTitle(QApplication::translate("MainWindow", "Histograma", nullptr));
        menuInformaci_n->setTitle(QApplication::translate("MainWindow", "Ver", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
