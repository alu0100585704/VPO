#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{

    QCoreApplication::setApplicationName("Grupo Maquinas");
    QCoreApplication::setOrganizationDomain("VPO");
    QCoreApplication::setOrganizationName("VPO");

    QApplication a(argc, argv);
    MainWindow w;


    //w.setWindowIcon(QIcon(":/Recursos/Images/RMpixel ico 64x64.png"));
    w.setWindowTitle("VPO: Mi FotoVisión");
    w.show();
    return a.exec();
}
