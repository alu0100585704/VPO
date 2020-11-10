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

  //for (int i=0;i < images_.size();i++)
    //  delete images_[i];

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

bool MainWindow::lutGray8bitsPrepare()
{
  lutGray8bits_.resize(256);

 for (int i=0; i < 255;i++)
    lutGray8bits_[i] = qRgb(i,i,i);

return  true;
}
void MainWindow::on_actionEscala_de_Grises_triggered()
{
  QMap<QString, Image *>::iterator it = images_.begin();
  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
              lutGray8bitsPrepare();
              QImage * ochobits =new QImage(it.value()->width_,it.value()->height_, QImage::Format_Indexed8);
              ochobits->setColorTable(lutGray8bits_);
              Image *imagen = new Image(QString("%1_Gris 8 bit").arg(focus_),ochobits,this);
              imagen->toGray8Bits(it.value(),imagen);
              images_.insert(QString("%1_Gris 8 bit").arg(focus_),imagen);
              ui->menuVentanas->addAction(imagen->toggleViewAction());
              addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);
        }
      ++it;
    }
}
