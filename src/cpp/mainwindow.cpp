#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    focus_("Sin foco")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
qDebug() << "Destrucyendo mainwindow";
    delete ui;


qDebug() << "Destructor mainwindow";
}

/*
bool MainWindow::event(QEvent *event)
{
  qDebug() << event->type();


    event->accept();

}
*/

void MainWindow::closeEvent(QCloseEvent *event)
{

  qDebug() << "closeevent";



  qDebug() << "destruidas desde closeevent";

    event->accept();

}



void MainWindow::on_actionExit_triggered()
{
    close();
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
                        Image *imagen= new Image(filenames[i],this);
                        ui->menuVentanas->addAction(imagen->toggleViewAction());
                        addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);
                        images_.insert(filenames[i],imagen);
                       }
                else
                        QMessageBox::warning(nullptr,"Atención",QString("El archivo %1 no existe.").arg(filenames[i]));

        }


}


void MainWindow::on_actionSaveFile_triggered()
{

}


void MainWindow::grayScale(bool ntsc)
{
  QMap<QString, Image *>::iterator it = images_.begin();
  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
              Image *imagen = new Image(QString("%1_Gris 8 bit").arg(focus_),it.value()->toGray8Bits(ntsc),this);
              images_.insert(QString("%1_Gris 8 bit").arg(focus_),imagen);
              ui->menuVentanas->addAction(imagen->toggleViewAction());
              addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);
        }
      ++it;
    }
}

void MainWindow::on_actionNTS_triggered()
{
    grayScale(true);
}

void MainWindow::on_actionPAL_triggered()
{
    grayScale(false);
}

void MainWindow::on_actionHistograma_absoluto_triggered()
{
  QMap<QString, Image *>::iterator it = images_.begin();
  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
          Image *imagen = new Image(QString("%1_Histograma Absoluto").arg(focus_),it.value()->toHistograma(),this);
          images_.insert(QString("%1_Histograma Absoluto").arg(focus_),imagen);
          ui->menuVentanas->addAction(imagen->toggleViewAction());
          addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);

        }
      ++it;
    }
}

void MainWindow::on_actionHistograma_Acumulativo_triggered()
{
  QMap<QString, Image *>::iterator it = images_.begin();
  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
          Image *imagen = new Image(QString("%1_Histograma Acumulativo").arg(focus_),it.value()->toHistogramaAcumulativo(),this);
          images_.insert(QString("%1_Histograma Acumulativo").arg(focus_),imagen);
          ui->menuVentanas->addAction(imagen->toggleViewAction());
          addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);

        }
      ++it;
    }
}

void MainWindow::on_actionBrillo_2_triggered()
{
}

void MainWindow::on_actionContraste_2_triggered()
{

}
