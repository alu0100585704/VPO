#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <image.h>
#include <QVector>
#include <QCloseEvent>
#include <QDebug>
#include <QEvent>
#include <brilloycontraste.h>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/background_segm.hpp>


using namespace  cv;
using namespace  std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);     

    QString focus_; //nombre de la imagen que tiene le foco actualmente        
    QLabel statusPermanentMessage_,information_;
    void deleteImage(QString name, bool noDelete=false);
private slots:

    void on_actionOpenFiles_triggered();

    void on_actionExit_triggered();

    void on_actionSaveFile_triggered();

    void on_actionHistograma_absoluto_triggered();

    void on_actionHistograma_Acumulativo_triggered();


    void on_actionBrilloyContraste_triggered();

    void on_actionEntropia_triggered();

    void on_actionGamma_triggered();

    void on_actionEcualizar_triggered();

    void on_actionNTSC8Bits_triggered();

    void on_actionPAL8Bits_triggered();

    void on_actionRGB32_NTSC_triggered();

    void on_actionRGB32_PAL_triggered();

    void on_actionEspecificacion_triggered();

    void on_actionInformacion_triggered();

    void on_actionChangeMap_triggered();

    void on_actionDiferencia_de_Imagenes_triggered();


private:
    Image * findImageAndNew(QString name, QString newTitle, bool toHistograma = false, bool tipoHistograma = false);
    Image * findImage(QString name);
    void grayScale(bool ntsc, bool ochobits);



    Ui::MainWindow *ui;    
    BrilloYContraste * dialog_;
    bool apply_; ///para cuadros de dialogos, saber cuando se apretó un boton o no
    QMap<QString, Image *> images_;

};

#endif // MAINWINDOW_H
