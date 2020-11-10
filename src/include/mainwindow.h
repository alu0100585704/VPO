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
    //virtual bool event(QEvent *event);
    bool lutGray8bitsPrepare();
    void show_images();

    QString focus_; //nombre de la imagen que tiene le foco actualmente    
private slots:

    void on_actionOpenFiles_triggered();

    void on_actionExit_triggered();

    void on_actionSaveFile_triggered();

    void on_actionEscala_de_Grises_triggered();


private:
    Ui::MainWindow *ui;
    QMap<QString, Image *> images_;
    QVector<QRgb>  lutGray8bits_;

};

#endif // MAINWINDOW_H
