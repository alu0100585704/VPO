/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
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
    QAction *actionInformacion;
    QAction *actionSuavizado;
    QAction *actionChangeMap;
    QAction *actionDiferencia_de_Imagenes;
    QAction *actionTransformaci_n_Lineal_Por_tramos;
    QAction *actionEspejoTraspuesta;
    QAction *actionEspejoVertical;
    QAction *actionEspejoHorizontal;
    QAction *actionRotacion90Izq;
    QAction *actionRotacion90Derecha;
    QAction *actionEscalado;
    QAction *actionRotacionAIquierda;
    QAction *actionRotacionADerecha;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuVentanas;
    QMenu *menuEfectos;
    QMenu *menuHistograma;
    QMenu *menuLineales;
    QMenu *menuNo_Lineales;
    QMenu *menuFiltros;
    QMenu *menuEscala_de_Grises;
    QMenu *menuGeom_tricos;
    QMenu *menuTransormaci_n_con_interpolaci_n;
    QMenu *menuInformaci_n;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(930, 696);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AnimatedDocks);
        actionOpenFiles = new QAction(MainWindow);
        actionOpenFiles->setObjectName(QString::fromUtf8("actionOpenFiles"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Recursos/iconos/open files.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFiles->setIcon(icon);
        actionOpenFiles->setIconVisibleInMenu(true);
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Recursos/iconos/save file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveFile->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Recursos/iconos/cerrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionBrilloyContraste = new QAction(MainWindow);
        actionBrilloyContraste->setObjectName(QString::fromUtf8("actionBrilloyContraste"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Recursos/iconos/brilloycontraste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBrilloyContraste->setIcon(icon3);
        actionHistograma_absoluto = new QAction(MainWindow);
        actionHistograma_absoluto->setObjectName(QString::fromUtf8("actionHistograma_absoluto"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Recursos/iconos/histograma absoluto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistograma_absoluto->setIcon(icon4);
        actionHistograma_Acumulativo = new QAction(MainWindow);
        actionHistograma_Acumulativo->setObjectName(QString::fromUtf8("actionHistograma_Acumulativo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Recursos/iconos/histograma acumulado.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistograma_Acumulativo->setIcon(icon5);
        actionNTSC8Bits = new QAction(MainWindow);
        actionNTSC8Bits->setObjectName(QString::fromUtf8("actionNTSC8Bits"));
        actionPAL8Bits = new QAction(MainWindow);
        actionPAL8Bits->setObjectName(QString::fromUtf8("actionPAL8Bits"));
        actionEntropia = new QAction(MainWindow);
        actionEntropia->setObjectName(QString::fromUtf8("actionEntropia"));
        actionGamma = new QAction(MainWindow);
        actionGamma->setObjectName(QString::fromUtf8("actionGamma"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Recursos/iconos/gamma.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGamma->setIcon(icon6);
        actionEcualizar = new QAction(MainWindow);
        actionEcualizar->setObjectName(QString::fromUtf8("actionEcualizar"));
        actionEspecificacion = new QAction(MainWindow);
        actionEspecificacion->setObjectName(QString::fromUtf8("actionEspecificacion"));
        actionRGB32_NTSC = new QAction(MainWindow);
        actionRGB32_NTSC->setObjectName(QString::fromUtf8("actionRGB32_NTSC"));
        actionRGB32_PAL = new QAction(MainWindow);
        actionRGB32_PAL->setObjectName(QString::fromUtf8("actionRGB32_PAL"));
        actionInformacion = new QAction(MainWindow);
        actionInformacion->setObjectName(QString::fromUtf8("actionInformacion"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Recursos/iconos/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInformacion->setIcon(icon7);
        actionSuavizado = new QAction(MainWindow);
        actionSuavizado->setObjectName(QString::fromUtf8("actionSuavizado"));
        actionChangeMap = new QAction(MainWindow);
        actionChangeMap->setObjectName(QString::fromUtf8("actionChangeMap"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Recursos/iconos/mapa de cambios.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangeMap->setIcon(icon8);
        actionDiferencia_de_Imagenes = new QAction(MainWindow);
        actionDiferencia_de_Imagenes->setObjectName(QString::fromUtf8("actionDiferencia_de_Imagenes"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Recursos/iconos/diferencia de imagenes.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDiferencia_de_Imagenes->setIcon(icon9);
        actionTransformaci_n_Lineal_Por_tramos = new QAction(MainWindow);
        actionTransformaci_n_Lineal_Por_tramos->setObjectName(QString::fromUtf8("actionTransformaci_n_Lineal_Por_tramos"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Recursos/iconos/transformacion_lineal_tramos.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTransformaci_n_Lineal_Por_tramos->setIcon(icon10);
        actionEspejoTraspuesta = new QAction(MainWindow);
        actionEspejoTraspuesta->setObjectName(QString::fromUtf8("actionEspejoTraspuesta"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Recursos/iconos/transpuesta.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEspejoTraspuesta->setIcon(icon11);
        actionEspejoVertical = new QAction(MainWindow);
        actionEspejoVertical->setObjectName(QString::fromUtf8("actionEspejoVertical"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Recursos/iconos/espejo vertical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEspejoVertical->setIcon(icon12);
        actionEspejoHorizontal = new QAction(MainWindow);
        actionEspejoHorizontal->setObjectName(QString::fromUtf8("actionEspejoHorizontal"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Recursos/iconos/espejo horizontal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEspejoHorizontal->setIcon(icon13);
        actionRotacion90Izq = new QAction(MainWindow);
        actionRotacion90Izq->setObjectName(QString::fromUtf8("actionRotacion90Izq"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Recursos/iconos/Rotar 90 izquierda.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotacion90Izq->setIcon(icon14);
        actionRotacion90Derecha = new QAction(MainWindow);
        actionRotacion90Derecha->setObjectName(QString::fromUtf8("actionRotacion90Derecha"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Recursos/iconos/Rotar 90 derecha.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotacion90Derecha->setIcon(icon15);
        actionEscalado = new QAction(MainWindow);
        actionEscalado->setObjectName(QString::fromUtf8("actionEscalado"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Recursos/iconos/escalar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEscalado->setIcon(icon16);
        actionRotacionAIquierda = new QAction(MainWindow);
        actionRotacionAIquierda->setObjectName(QString::fromUtf8("actionRotacionAIquierda"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Recursos/iconos/rotacion izquierda.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotacionAIquierda->setIcon(icon17);
        actionRotacionADerecha = new QAction(MainWindow);
        actionRotacionADerecha->setObjectName(QString::fromUtf8("actionRotacionADerecha"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Recursos/iconos/rotacion derecha.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotacionADerecha->setIcon(icon18);
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
        menuHistograma = new QMenu(menuEfectos);
        menuHistograma->setObjectName(QString::fromUtf8("menuHistograma"));
        menuLineales = new QMenu(menuEfectos);
        menuLineales->setObjectName(QString::fromUtf8("menuLineales"));
        menuNo_Lineales = new QMenu(menuEfectos);
        menuNo_Lineales->setObjectName(QString::fromUtf8("menuNo_Lineales"));
        menuFiltros = new QMenu(menuEfectos);
        menuFiltros->setObjectName(QString::fromUtf8("menuFiltros"));
        menuEscala_de_Grises = new QMenu(menuEfectos);
        menuEscala_de_Grises->setObjectName(QString::fromUtf8("menuEscala_de_Grises"));
        menuGeom_tricos = new QMenu(menuEfectos);
        menuGeom_tricos->setObjectName(QString::fromUtf8("menuGeom_tricos"));
        menuTransormaci_n_con_interpolaci_n = new QMenu(menuEfectos);
        menuTransormaci_n_con_interpolaci_n->setObjectName(QString::fromUtf8("menuTransormaci_n_con_interpolaci_n"));
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
        menuEfectos->addSeparator();
        menuEfectos->addAction(menuHistograma->menuAction());
        menuEfectos->addSeparator();
        menuEfectos->addAction(menuLineales->menuAction());
        menuEfectos->addSeparator();
        menuEfectos->addAction(menuNo_Lineales->menuAction());
        menuEfectos->addSeparator();
        menuEfectos->addAction(menuFiltros->menuAction());
        menuEfectos->addSeparator();
        menuEfectos->addAction(menuGeom_tricos->menuAction());
        menuEfectos->addSeparator();
        menuEfectos->addAction(menuTransormaci_n_con_interpolaci_n->menuAction());
        menuHistograma->addAction(actionEcualizar);
        menuHistograma->addAction(actionEspecificacion);
        menuLineales->addSeparator();
        menuLineales->addAction(actionBrilloyContraste);
        menuLineales->addAction(actionTransformaci_n_Lineal_Por_tramos);
        menuLineales->addSeparator();
        menuNo_Lineales->addAction(actionGamma);
        menuNo_Lineales->addAction(actionDiferencia_de_Imagenes);
        menuNo_Lineales->addAction(actionChangeMap);
        menuFiltros->addAction(actionSuavizado);
        menuEscala_de_Grises->addSeparator();
        menuEscala_de_Grises->addAction(actionRGB32_NTSC);
        menuEscala_de_Grises->addAction(actionNTSC8Bits);
        menuEscala_de_Grises->addSeparator();
        menuEscala_de_Grises->addAction(actionRGB32_PAL);
        menuEscala_de_Grises->addAction(actionPAL8Bits);
        menuGeom_tricos->addAction(actionEspejoTraspuesta);
        menuGeom_tricos->addAction(actionEspejoVertical);
        menuGeom_tricos->addAction(actionEspejoHorizontal);
        menuGeom_tricos->addAction(actionRotacion90Izq);
        menuGeom_tricos->addAction(actionRotacion90Derecha);
        menuGeom_tricos->addSeparator();
        menuTransormaci_n_con_interpolaci_n->addAction(actionEscalado);
        menuTransormaci_n_con_interpolaci_n->addAction(actionRotacionAIquierda);
        menuTransormaci_n_con_interpolaci_n->addAction(actionRotacionADerecha);
        menuInformaci_n->addAction(actionHistograma_absoluto);
        menuInformaci_n->addAction(actionHistograma_Acumulativo);
        menuInformaci_n->addAction(actionEntropia);
        menuInformaci_n->addSeparator();
        menuInformaci_n->addAction(actionInformacion);
        toolBar->addAction(actionOpenFiles);
        toolBar->addAction(actionSaveFile);
        toolBar->addAction(actionGamma);
        toolBar->addAction(actionBrilloyContraste);
        toolBar->addAction(actionHistograma_absoluto);
        toolBar->addAction(actionHistograma_Acumulativo);
        toolBar->addAction(actionChangeMap);
        toolBar->addAction(actionDiferencia_de_Imagenes);
        toolBar->addAction(actionTransformaci_n_Lineal_Por_tramos);
        toolBar->addAction(actionInformacion);
        toolBar->addSeparator();
        toolBar->addAction(actionEspejoTraspuesta);
        toolBar->addAction(actionEspejoVertical);
        toolBar->addAction(actionEspejoHorizontal);
        toolBar->addAction(actionRotacion90Izq);
        toolBar->addAction(actionRotacion90Derecha);
        toolBar->addSeparator();
        toolBar->addAction(actionEscalado);
        toolBar->addAction(actionRotacionADerecha);
        toolBar->addAction(actionRotacionAIquierda);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);
        toolBar->addSeparator();

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
#ifndef QT_NO_SHORTCUT
        actionOpenFiles->setShortcut(QApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveFile->setText(QApplication::translate("MainWindow", "Salvar", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveFile->setToolTip(QApplication::translate("MainWindow", "Guardar imagen en fichero", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSaveFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Salir", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Alt+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "Acerca de . . .", nullptr));
        actionBrilloyContraste->setText(QApplication::translate("MainWindow", "Brillo y Contraste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionBrilloyContraste->setShortcut(QApplication::translate("MainWindow", "Alt+B", nullptr));
#endif // QT_NO_SHORTCUT
        actionHistograma_absoluto->setText(QApplication::translate("MainWindow", "Histograma Absoluto", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHistograma_absoluto->setShortcut(QApplication::translate("MainWindow", "Alt+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionHistograma_Acumulativo->setText(QApplication::translate("MainWindow", "Histograma Acumulativo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHistograma_Acumulativo->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionNTSC8Bits->setText(QApplication::translate("MainWindow", "8 bit NTSC", nullptr));
        actionPAL8Bits->setText(QApplication::translate("MainWindow", "8 bit PAL", nullptr));
        actionEntropia->setText(QApplication::translate("MainWindow", "Entrop\303\255a (Solo Gris)", nullptr));
        actionGamma->setText(QApplication::translate("MainWindow", "Funcion Gamma", nullptr));
#ifndef QT_NO_TOOLTIP
        actionGamma->setToolTip(QApplication::translate("MainWindow", "Calcular Funcion Gamma", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionGamma->setShortcut(QApplication::translate("MainWindow", "Alt+G", nullptr));
#endif // QT_NO_SHORTCUT
        actionEcualizar->setText(QApplication::translate("MainWindow", "Ecualizar", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEcualizar->setShortcut(QApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_NO_SHORTCUT
        actionEspecificacion->setText(QApplication::translate("MainWindow", "Especificaci\303\263n", nullptr));
        actionRGB32_NTSC->setText(QApplication::translate("MainWindow", "RGB32 NTSC", nullptr));
        actionRGB32_PAL->setText(QApplication::translate("MainWindow", "RGB32 PAL", nullptr));
        actionInformacion->setText(QApplication::translate("MainWindow", "Informaci\303\263n", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInformacion->setToolTip(QApplication::translate("MainWindow", "Informaci\303\263n sobre la imagen seleccionada", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionInformacion->setShortcut(QApplication::translate("MainWindow", "Alt+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionSuavizado->setText(QApplication::translate("MainWindow", "Suavizado", nullptr));
        actionChangeMap->setText(QApplication::translate("MainWindow", "Mapa de Cambios (Solo Gris)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionChangeMap->setToolTip(QApplication::translate("MainWindow", "Mapa de Cambios entre 2 im\303\241genes", nullptr));
#endif // QT_NO_TOOLTIP
        actionDiferencia_de_Imagenes->setText(QApplication::translate("MainWindow", "Diferencia de Im\303\241genes (Solo Gris)", nullptr));
        actionTransformaci_n_Lineal_Por_tramos->setText(QApplication::translate("MainWindow", "Transformaci\303\263n Lineal Por tramos", nullptr));
#ifndef QT_NO_TOOLTIP
        actionTransformaci_n_Lineal_Por_tramos->setToolTip(QApplication::translate("MainWindow", "Transformaci\303\263n Lineal por Tramos", nullptr));
#endif // QT_NO_TOOLTIP
        actionEspejoTraspuesta->setText(QApplication::translate("MainWindow", "Traspuesta", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEspejoTraspuesta->setToolTip(QApplication::translate("MainWindow", "Traspuesta de la Imagen", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionEspejoTraspuesta->setShortcut(QApplication::translate("MainWindow", "Alt+T", nullptr));
#endif // QT_NO_SHORTCUT
        actionEspejoVertical->setText(QApplication::translate("MainWindow", "Espejo Vertical", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEspejoVertical->setShortcut(QApplication::translate("MainWindow", "Alt+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionEspejoHorizontal->setText(QApplication::translate("MainWindow", "Espejo Horizontal", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEspejoHorizontal->setShortcut(QApplication::translate("MainWindow", "Alt+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionRotacion90Izq->setText(QApplication::translate("MainWindow", "Rotaci\303\263n 90 \302\272 Izquierda", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRotacion90Izq->setToolTip(QApplication::translate("MainWindow", "Rotaci\303\263n 90\302\272 a Izquierda", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRotacion90Izq->setShortcut(QApplication::translate("MainWindow", "Alt+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionRotacion90Derecha->setText(QApplication::translate("MainWindow", "Rotaci\303\263n 90 \302\272 Derecha", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRotacion90Derecha->setToolTip(QApplication::translate("MainWindow", "Rotaci\303\263n 90 \302\272 a  Derecha", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRotacion90Derecha->setShortcut(QApplication::translate("MainWindow", "Alt+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionEscalado->setText(QApplication::translate("MainWindow", "Escalado", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEscalado->setToolTip(QApplication::translate("MainWindow", "Escalar Imagen", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionEscalado->setShortcut(QApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_NO_SHORTCUT
        actionRotacionAIquierda->setText(QApplication::translate("MainWindow", "Rotaci\303\263n a Iquierda", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRotacionAIquierda->setToolTip(QApplication::translate("MainWindow", "Rotaci\303\263n a Iquierda con Interpolado", nullptr));
#endif // QT_NO_TOOLTIP
        actionRotacionADerecha->setText(QApplication::translate("MainWindow", "Rotaci\303\263n a Derecha", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRotacionADerecha->setToolTip(QApplication::translate("MainWindow", "Rotaci\303\263n a Derecha con Interpolado", nullptr));
#endif // QT_NO_TOOLTIP
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", nullptr));
        menuVentanas->setTitle(QApplication::translate("MainWindow", "Ventanas", nullptr));
        menuEfectos->setTitle(QApplication::translate("MainWindow", "Efectos", nullptr));
        menuHistograma->setTitle(QApplication::translate("MainWindow", "Histograma", nullptr));
        menuLineales->setTitle(QApplication::translate("MainWindow", "Lineales", nullptr));
        menuNo_Lineales->setTitle(QApplication::translate("MainWindow", "No Lineales", nullptr));
        menuFiltros->setTitle(QApplication::translate("MainWindow", "Filtros", nullptr));
        menuEscala_de_Grises->setTitle(QApplication::translate("MainWindow", "Escala de Grises", nullptr));
        menuGeom_tricos->setTitle(QApplication::translate("MainWindow", "Geom\303\251tricos", nullptr));
        menuTransormaci_n_con_interpolaci_n->setTitle(QApplication::translate("MainWindow", "Transormaci\303\263n con interpolado", nullptr));
        menuInformaci_n->setTitle(QApplication::translate("MainWindow", "Ver", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
