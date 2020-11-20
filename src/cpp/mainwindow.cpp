#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    focus_("Ninguna imagen Seleccionada"),
    dialog_(nullptr)
{
    ui->setupUi(this);
    statusBar();
    statusBar()->addPermanentWidget(&statusPermanentMessage_);
    statusBar()->addWidget(&information_);
    statusPermanentMessage_.setAlignment(Qt::AlignLeft);
    information_.setAlignment(Qt::AlignRight);
    statusPermanentMessage_.setText(focus_);

}

MainWindow::~MainWindow()
{
qDebug() << "Destrucyendo mainwindow";
    delete ui;

if (dialog_ != nullptr)
   delete dialog_;

qDebug() << "Destructor mainwindow";
}


void MainWindow::closeEvent(QCloseEvent *event)
{


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
                        QMessageBox::warning(nullptr,"Atenci√≥n",QString("El archivo %1 no existe.").arg(filenames[i]));

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
          Image *imagen = new Image(QString("%1_Histograma Absoluto").arg(focus_),it.value()->toHistograma(false),this);
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
          Image *imagen = new Image(QString("%1_Histograma Acumulativo").arg(focus_),it.value()->toHistograma(true),this);
          images_.insert(QString("%1_Histograma Acumulativo").arg(focus_),imagen);
          ui->menuVentanas->addAction(imagen->toggleViewAction());
          addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);

        }
      ++it;
    }
}



void MainWindow::on_actionBrilloyContraste_triggered()
{
  QMap<QString, Image *>::iterator it = images_.begin();
  Image * borrador;

  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
          Image * imagen = new Image(QString("%1_Brillo y Contraste").arg(focus_),it.value()->getImage(),this);
          images_.insert(QString("%1_Brillo y Contraste").arg(focus_),imagen);
          ui->menuVentanas->addAction(imagen->toggleViewAction());
          addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);
          borrador = imagen;
        }
      ++it;
    }

if (dialog_!=nullptr)
  delete dialog_;

 dialog_ = new BrilloYContraste(this);
 dialog_->setWindowTitle(QString("Brillo y Contraste para : %1").arg(focus_));
 dialog_->setImage(borrador);
 dialog_->show();


}


void MainWindow::on_actionEntropia_triggered()
{
  QMap<QString, Image *>::iterator it = images_.begin();
  Image * borrador;

  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
          QMessageBox::information(this,"Entropia",QString("Valor para %1: %2").arg(focus_).arg(it.value()->entropia_));
        }
      ++it;
    }


}

void MainWindow::on_actionGamma_triggered()
{

  QMap<QString, Image *>::iterator it = images_.begin();
  Image * borrador;


  while (it!=images_.end())
    {
      if (it.key()==focus_)
        {
          Image * imagen = new Image(QString("%1_Gamma").arg(focus_),it.value()->getImage(),this);
          images_.insert(QString("%1_Gamma").arg(focus_),imagen);
          ui->menuVentanas->addAction(imagen->toggleViewAction());
          addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea,imagen,Qt::Orientation::Vertical);
          borrador = imagen;
        }
      ++it;
    }

  QDialog * dialogGamma = new QDialog(this);
  QDoubleSpinBox * valor = new QDoubleSpinBox(dialogGamma);
  QLabel * label = new QLabel(dialogGamma);
  QHBoxLayout * layout = new QHBoxLayout(dialogGamma);

  dialogGamma->setWindowTitle(QString("Valor Gamma para %1").arg(focus_));
  label->setText("Introduzca valor para la funciÛn Gamma\n\nValores > 1 Mejora contraste en zona clara\nValores < 1 Mejora contraste en la zona oscura");
  layout->addWidget(label);
  layout->addWidget(valor);
  dialogGamma->setLayout(layout);
  valor->setMinimum(0);
  valor->setMaximum(255.0);

  dialogGamma->show();
  QImage * imageForKeepOriginal = borrador->getImage();

  connect(valor,QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){

      borrador->setImage(*imageForKeepOriginal);
      borrador->funcionGamma(d);

  });


  connect(dialogGamma,(&QDialog::finished),[=](int result){

    delete imageForKeepOriginal;

  });


}
