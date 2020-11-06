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

    void show_images();

private slots:

    void on_actionOpenFiles_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QVector<Image *> images_;
};

#endif // MAINWINDOW_H
