#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QTextCodec>
#include <QObject>
int main(int argc, char *argv[])
{

    QCoreApplication::setApplicationName("FotoVision2");
    QCoreApplication::setOrganizationDomain("VPO");
    QCoreApplication::setOrganizationName("VPO");

    QApplication a(argc, argv);
    MainWindow w;


    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8") );
    w.setWindowIcon(QIcon(":/Recursos/Images/RMpixel ico 64x64.png"));

    w.setWindowTitle(QObject::tr("VPO: Mi FotoVision"));
    w.show();
    return a.exec();
}

