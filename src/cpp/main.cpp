#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{

    QCoreApplication::setApplicationName("Grupo Maquinas");
    QCoreApplication::setOrganizationDomain("SIPC: Reconocimiento Gestos");
    QCoreApplication::setOrganizationName("SIPC");

    QApplication a(argc, argv);
    MainWindow w;


    //w.setWindowIcon(QIcon(":/Recursos/Images/RMpixel ico 64x64.png"));
    w.setWindowTitle("SIPC: Reconocimiento Gestos");
    w.show();
    return a.exec();
}
