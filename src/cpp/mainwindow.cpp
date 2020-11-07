#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
qDebug() << "Destrucyendo mainwindow";
    delete ui;


qDebug() << "Destructor mainwindow";
}


void MainWindow::closeEvent(QCloseEvent *event)
{

  qDebug() << "closeevent";

  for (int i=0;i < images_.size();i++)
      delete images_[i];

  qDebug() << "destruidas desde closeevent";

    event->accept();

}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::show_images()
{
   for (int i =0; i < images_.size(); i++)
     {
         ui->menuVentanas->addAction(images_[i]->dock_->toggleViewAction());
         images_[i]->dock_->show();

     }
}


void MainWindow::on_actionOpenFiles_triggered()
{
 QStringList filenames;

   filenames = QFileDialog::getOpenFileNames(nullptr, "Abrir Archivo",QString(),"Multimedia (*.*)");

   for (int i=0; i < filenames.size(); i++)
        {
                QFile file(filenames[i]);
                 if (file.exists())
                       {
                        Image *imagen= new Image(filenames[i]);
                        images_.push_back(imagen);   
                       }
                else
                        QMessageBox::warning(nullptr,"Atención",QString("El archivo %1 no existe.").arg(filenames[i]));

        }

   show_images();

}

