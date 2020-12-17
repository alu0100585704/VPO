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


///
/// \brief MainWindow::on_actionOpenFiles_triggered
///
void MainWindow::on_actionOpenFiles_triggered()
{
 QStringList filenames;

   filenames = QFileDialog::getOpenFileNames(nullptr, "Abrir Archivo",QString(),"Todos (*.*);; Multimedia (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm) ");

   for (int i=0; i < filenames.size(); i++)
        {
                QFile file(filenames[i]);
                 if (file.exists())
                       {
                        Image *imagen= new Image(filenames[i],this);                       
                        ui->menuVentanas->addAction(imagen->toggleViewAction());                       
                        addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea,imagen,Qt::Orientation::Horizontal);
                        images_.insert(filenames[i],imagen);
                       }
                else
                        QMessageBox::warning(nullptr,"Atención",QString("El archivo %1 no existe.").arg(filenames[i]));

        }


}

///
/// \brief MainWindow::on_actionSaveFile_triggered
///función que graba imagen a disco
void MainWindow::on_actionSaveFile_triggered()
{

  Image * borrador = findImage(focus_);
  if (borrador!=nullptr)
    {
      QString filename = QFileDialog::getSaveFileName(nullptr, "Abrir Archivo",focus_,"Todos (*.*);; *.bmp;;*.gif;;*.jpg;;*.jpeg;;*.png;;*.pbm;;*.pgm;;*.ppm;;*.xbm;;*.xpm");;

      if (!filename.isEmpty())
          borrador->image_->save(filename);

    }



}
///Devuelve puntero clase Image, con la imagen encontrada. nullptr si no se encontró.
/// name Qstring con nombre de la imagen.
/// \brief findImage
/// \param name
/// \return
///
Image * MainWindow::findImage(QString name)
{
  QMap<QString, Image *>::iterator it = images_.begin();
  bool encontrado = false;
  Image *  imagen = nullptr;

  while ((it!=images_.end()) && (!encontrado))
    {
      if (it.key()==name)
        {
              encontrado = true;
              imagen = it.value();
        }
      ++it;
    }

  if (!encontrado)
   QMessageBox::warning(this,"No Encontrado",QString("Imagen no Seleccionada o No encontrada"));

  return imagen;
}
///Devuelve puntero Image con una copia de la imagen buscada, con un nuevo título.
/// Si toHistograma es true , devuelve una claes Imagen que contiene el histrograma absoluto o acumulado serán tipoHistograma
/// \brief findImage
///
Image * MainWindow::findImageAndNew(QString name, QString newTitle, bool toHistograma,bool tipoHistograma)
{
  QMap<QString, Image *>::iterator it = images_.begin();
  bool encontrado = false;
  Image *  imagen = nullptr;

  while ((it!=images_.end()) && (!encontrado))
    {
      if (it.key()==name)
        {
              encontrado = true;
              if (!toHistograma)
                  imagen = new Image(QString("%1_%2").arg(name).arg(newTitle),it.value()->getImage(),this);
              else
                  imagen = new Image(QString("%1_%2").arg(name).arg(newTitle),it.value()->toHistograma(tipoHistograma),this);

              appendImage(QString("%1_%2").arg(name).arg(newTitle),imagen);
        }
      ++it;
    }

  if (!encontrado)
   QMessageBox::warning(this,"No Encontrado",QString("Imagen no Seleccionada o No encontrada"));

  return imagen;
}


void MainWindow::on_actionHistograma_absoluto_triggered()
{
  findImageAndNew(focus_,"Histograma Absoluto",true,false);
}

void MainWindow::on_actionHistograma_Acumulativo_triggered()
{ 
  findImageAndNew(focus_,"Histograma Acumulativo",true,true);

}



void MainWindow::on_actionBrilloyContraste_triggered()
{
  Image * borrador = findImageAndNew(focus_,"Brillo y Contraste");

  if (borrador != nullptr)
    {
      if (dialog_!=nullptr)
        delete dialog_;

       dialog_ = new BrilloYContraste(this);
       dialog_->setWindowTitle(QString("Brillo y Contraste para : %1").arg(focus_));
       dialog_->setImage(borrador);
       dialog_->show();

    }

}


void MainWindow::on_actionEntropia_triggered()
{

  if (findImage(focus_) != nullptr)
          QMessageBox::information(this,"Entropía",QString("Valor para %1: %2").arg(focus_).arg(findImage(focus_)->entropia_));


}

void MainWindow::on_actionGamma_triggered()
{ 

  Image * borrador = findImageAndNew(focus_,"Gamma");

  if (borrador != nullptr)
    {
      QDialog * dialogGamma = new QDialog(this);
      QDoubleSpinBox * valor = new QDoubleSpinBox(dialogGamma);
      QLabel * label = new QLabel(dialogGamma);
      QHBoxLayout * layout = new QHBoxLayout(dialogGamma);

      dialogGamma->setWindowTitle(QString("Valor Gamma para %1").arg(focus_));
      label->setText("Introduzca valor para la función Gamma\n\nValores > 1 Mejora contraste en zona clara\nValores < 1 Mejora contraste en la zona oscura");
      layout->addWidget(label);
      layout->addWidget(valor);
      dialogGamma->setLayout(layout);
      valor->setMinimum(0);
      valor->setMaximum(255.0);
      valor->setSingleStep(0.1);
      valor->setValue(1.0);


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

}

void MainWindow::on_actionEcualizar_triggered()
{
 Image * borrador;
 borrador = findImageAndNew(focus_,"Ecualizada");

 if (borrador != nullptr)
      borrador->toEcualizer();

}


///
/// \brief MainWindow::grayScale
/// \param ntsc
///
void MainWindow::grayScale(bool ntsc,bool ochobits)
{
  Image * borrador;
  QString formato;

  if (ntsc)
    formato = "Gris NTSC ";
   else
     formato = "Gris PAL ";

  if (ochobits)
    {           
      borrador = findImageAndNew(focus_,formato + " 8 bits");
     if (borrador!= nullptr)
       borrador->toGray(ntsc,true);
     }

  else
    {
    borrador = findImageAndNew(focus_,formato+ " RGB 32 Bits");
    if (borrador!= nullptr)
      borrador->toGray(ntsc,false);
    }



}
void MainWindow::on_actionNTSC8Bits_triggered()
{
    grayScale(true,true);
}

void MainWindow::on_actionPAL8Bits_triggered()
{
    grayScale(false,true);
}

void MainWindow::on_actionRGB32_NTSC_triggered()
{
    grayScale(true,false);
}

void MainWindow::on_actionRGB32_PAL_triggered()
{
    grayScale(false,false);
}



void MainWindow::on_actionEspecificacion_triggered()
{
  Image * borrador;

  borrador= findImageAndNew(focus_,"Histograma Especificado");

  if (borrador!= nullptr)
    {
      QDialog * dialogEspecificarHistograma = new QDialog(this);
      QLabel * label = new QLabel(dialogEspecificarHistograma);
      QComboBox * comboBoxTargetHistograma = new QComboBox(dialogEspecificarHistograma);
      QPushButton * pushButtonApply = new QPushButton(dialogEspecificarHistograma);
      QVBoxLayout * layout = new QVBoxLayout(dialogEspecificarHistograma);


      QMap<QString, Image *>::iterator it = images_.begin();

      while (it!=images_.end())
        {
          if ((it.key()!=focus_) && (!it.key().contains("histograma",Qt::CaseInsensitive))) ///agrego al combo solo las imágenes que no sean esta misma y que no sean histogramas
              comboBoxTargetHistograma->addItem(it.key());
          ++it;
        }

      if (comboBoxTargetHistograma->count()!=0)
      {

      pushButtonApply->setText("Aplicar");
      label->setText("Selecciona una imagen desde las ya abiertas.\nEl Histograma Destino será el que tenga la imagen seleccionada.");
      layout->addWidget(label);
      layout->addWidget(comboBoxTargetHistograma);
      layout->addWidget(pushButtonApply);


      dialogEspecificarHistograma->setWindowTitle("Histograma Destino");


      connect(pushButtonApply,(&QPushButton::clicked),[=](bool checked){

          borrador->toHistogramaEspecificado(findImage(comboBoxTargetHistograma->currentText()));
          dialogEspecificarHistograma->close();

      });


      dialogEspecificarHistograma->exec();


      }
      else
      {
        QMessageBox::warning(nullptr,"Atención:Falta imagen destino","Debe abrir por lo menos otra imagen de la que obtener su histograma");
        deleteImage(focus_ + "_Histograma Especificado");
      }

    }

}
/// Elimino del vector de imágenes la imagen indicada o todas si name está vacóo
/// \brief MainWindow::deleteImage
/// \param name
///
void MainWindow::deleteImage(QString name,bool noDelete)
{
   QMap<QString, Image *>::iterator it = images_.begin();

qDebug() << name;

  while (it!=images_.end())
    {
      if (name.isEmpty())
          {
            delete it.value();
            images_.erase(it);

          }
      else  if (it.key()==name)
      {
             if (!noDelete)
                delete it.value();
              images_.erase(it);

      }
      ++it;
    }

}
///
/// \brief MainWindow::appendImage
/// \param title
/// \param imagen
/// Agrego imagen al vector de imágenes y al menu ventanas.
void MainWindow::appendImage(QString title, Image *imagen)
{

  images_.insert(title,imagen);
  ui->menuVentanas->addAction(imagen->toggleViewAction());
       addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea,imagen,Qt::Orientation::Horizontal);
}

void MainWindow::on_actionInformacion_triggered()
{
  Image *borrador;
  borrador = findImage(focus_);

  QString information;

  information = "\nNombre Imagen : " + focus_;
   if (borrador!=nullptr)
     {
       if (borrador->isGray_)
       {

           if (borrador->format_==QImage::Format_Indexed8)
            information = information + "\n\nImagen Gris de 8 Bits";
          else
          information = information + "\n\nImagen Gris RGB de 32 Bits";
           information = information + "\nBrillo: " + QString::number(borrador->brillo_gray_);
           information = information + "\nContraste: " + QString::number(borrador->contraste_gray_);


           information =information + "\n\nValor inferior de Gris: " + QString::number(borrador->grayValueMin_) + "\nValor superior de Gris: " + QString::number(borrador->grayValueMax_);
           information =information + "\nTono de Gris con mayor cantidad de pixels: " + QString::number(borrador->toneGrayWidthMorePixels_) + " con " + QString::number(borrador->histograma_[borrador->toneGrayWidthMorePixels_].countGray_) + "\nTono de Gris con menor cantidad de pixels: " + QString::number(borrador->toneGrayWidthLessPixels_) + " con " + QString::number(borrador->histograma_[borrador->toneGrayWidthLessPixels_].countGray_) ;

        }
       else
          {
          information = information + "\n\nImagen Color RGB de 32 Bits";

          information = information + "\n\nBrillo Tono Rojo: " + QString::number(borrador->brillo_red_);
          information = information + "\nContraste Tono Rojo: " + QString::number(borrador->contraste_red_);
          information =information + "\nValor inferior de Rojo: " + QString::number(borrador->redValueMin_) + "\nValor superior de Rojo: " + QString::number(borrador->redValueMax_);
          information =information + "\nTono de Rojo con mayor cantidad de pixels: " + QString::number(borrador->toneRedWidthMorePixels_) + " con " + QString::number(borrador->histograma_[borrador->toneRedWidthMorePixels_].countRed_) + "\nTono de Rojo con menor cantidad de pixels: " + QString::number(borrador->toneRedWidthLessPixels_) + " con " + QString::number(borrador->histograma_[borrador->toneRedWidthLessPixels_].countRed_) ;


          information = information + "\n\nBrillo Tono Verde: " + QString::number(borrador->brillo_green_);
          information = information + "\nContraste Tono Verde: " + QString::number(borrador->contraste_green_);
          information =information + "\nValor inferior de Verde: " + QString::number(borrador->greenValueMin_) + "\nValor superior de Verde " + QString::number(borrador->greenValueMax_);
          information =information + "\nTono de Verde con mayor cantidad de pixels: " + QString::number(borrador->toneGreenWidthMorePixels_) + " con " + QString::number(borrador->histograma_[borrador->toneGreenWidthMorePixels_].countGreen_) + "\nTono de Verde con menor cantidad de pixels: " + QString::number(borrador->toneGreenWidthLessPixels_) + " con " + QString::number(borrador->histograma_[borrador->toneGreenWidthLessPixels_].countGreen_) ;



          information = information + "\n\nBrillo Tono Azul: " + QString::number(borrador->brillo_blue_);
          information = information + "\nContraste Tono Azul: " + QString::number(borrador->contraste_blue_);
          information =information + "\nValor inferior de Azul: " + QString::number(borrador->blueValueMin_) + "\nValor superior de Azul: " + QString::number(borrador->blueValueMax_);
          information =information + "\nTono de Azul con mayor cantidad de pixels: " + QString::number(borrador->toneBlueWidthMorePixels_) + " con " + QString::number(borrador->histograma_[borrador->toneBlueWidthMorePixels_].countBlue_) + "\nTono de Azul con menor cantidad de pixels: " + QString::number(borrador->toneBlueWidthLessPixels_) + " con " + QString::number(borrador->histograma_[borrador->toneBlueWidthLessPixels_].countBlue_) ;

          }

       information = information + QString::fromUtf8("\n\nValor entropía: ") + QString::number(borrador->entropia_);
       information = information + "\n\Ancho: " + QString::number(borrador->width_) + " pixels";
       information = information + "\nAlto: " + QString::number(borrador->height_) + " pixels";
       information = information + "\nTotal de Pixels: " + QString::number(borrador->height_ * borrador->width_) + " pixels";



       QMessageBox::information(this,QString::fromUtf8("Información"),information);
     }


}


void MainWindow::on_actionChangeMap_triggered()
{
  Image * borrador;

  borrador= findImageAndNew(focus_,"Mapa de Cambios");

  if (borrador!= nullptr)
    {
      QDialog * dialogCambios = new QDialog(this);
      QLabel * label = new QLabel(dialogCambios);
      QComboBox * comboBoxTarget = new QComboBox(dialogCambios);
      QPushButton * pushButtonApply = new QPushButton(dialogCambios);
      QVBoxLayout * layout = new QVBoxLayout(dialogCambios);


      QMap<QString, Image *>::iterator it = images_.begin();

      while (it!=images_.end())
        {
          if ((it.key()!=focus_) && (it.key()!=focus_ + "_Mapa de Cambios") && (!it.key().contains("histograma",Qt::CaseInsensitive))) ///agrego al combo solo las imágenes que no sean esta misma y que no sean histogramas
              comboBoxTarget->addItem(it.key());
          ++it;
        }

      if (comboBoxTarget->count()!=0)
      {

      pushButtonApply->setText("Aplicar");
      label->setText("Selecciona una imagen desde las ya abiertas.\nEl Mapa de Cambios(pixeles de diferencia) se mostrarán en rojo en la imagen resultante");
      layout->addWidget(label);
      layout->addWidget(comboBoxTarget);
      layout->addWidget(pushButtonApply);


      dialogCambios->setWindowTitle("Mapa de Cambios");

      apply_ = false;
      connect(pushButtonApply,(&QPushButton::clicked),[=](bool checked){

          if (!borrador->toMapChange(findImage(comboBoxTarget->currentText())))
             deleteImage(focus_ + "_Mapa de Cambios"); ///borro el objeto en caso de que se haya producido algún error durante
          ///el mapa de cambios, por ejemplo porque las imágenes tuvieran tamaáos diferentes

          apply_ =  true;
          dialogCambios->close();

      });

      connect(dialogCambios,(&QDialog::finished),[=](int result){
          if (!apply_)
            delete borrador;
          dialogCambios->close();

      });


      dialogCambios->exec();


      }
      else
      {
        QMessageBox::warning(nullptr,QString::fromUtf8("Atención: Falta imagen para comparar"),"Debe abrir por lo menos otra imagen con la que comparar");
        deleteImage(focus_ + "_Mapa de Cambios");
      }

    }

}

void MainWindow::on_actionDiferencia_de_Imagenes_triggered()
{
  Image * borrador;

  borrador= findImageAndNew(focus_,QString::fromUtf8("Diferencia"));

  if (borrador!= nullptr)
    {
      QDialog * dialogDifference = new QDialog(this);
      QLabel * label = new QLabel(dialogDifference);
      QComboBox * comboBoxTarget = new QComboBox(dialogDifference);
      QPushButton * pushButtonApply = new QPushButton(dialogDifference);
      QVBoxLayout * layout = new QVBoxLayout(dialogDifference);


      QMap<QString, Image *>::iterator it = images_.begin();

      while (it!=images_.end())
        {
          if ((it.key()!=focus_) &&  (it.key()!=focus_ + "_Diferencia") && (!it.key().contains("histograma",Qt::CaseInsensitive))) ///agrego al combo solo las imágenes que no sean esta misma y que no sean histogramas
              comboBoxTarget->addItem(it.key());
          ++it;
        }

      if (comboBoxTarget->count()!=0)
      {

      pushButtonApply->setText("Aplicar");
      label->setText("Selecciona una imagen desde las ya abiertas.\nLa imagen final será la diferencia entre la imagen origen y la seleccionada");
      layout->addWidget(label);
      layout->addWidget(comboBoxTarget);
      layout->addWidget(pushButtonApply);      
      dialogDifference->setLayout(layout);

      dialogDifference->setWindowTitle(QString::fromUtf8("Diferencia de Imágenes"));

      apply_ = false;
      connect(pushButtonApply,(&QPushButton::clicked),[=](bool checked){

          if (borrador->toDifference(findImage(comboBoxTarget->currentText())))
              apply_ = true;
          else
              apply_ = false;

          dialogDifference->close();


      });


      connect(dialogDifference,(&QDialog::finished),[=](int result){
          if (!apply_)
            delete borrador;
          dialogDifference->close();

      });

      dialogDifference->exec();


      }
      else
      {
        QMessageBox::warning(this,QString::fromUtf8("Atención: Falta imagen con la que realizar la diferencia"),"Debe abrir por lo menos otra imagen");
        deleteImage(focus_ + "_Diferencia");
      }

    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"Acerca de . . .",QString("Realizado por Juan Siverio Rojas.\n* Práctica 1 y 3 para Visión por Computador\n* 4ª Ingeniería Informática\n* Itinerario Ingeniería de Computadores\n"));
}

///
////// \brief MainWindow::roiImage
////// \param xi
////// \param yi
////// \param xf
////// \param yf
////// \param imagen
/// Región de interés de la imagen
void MainWindow::roiImage(int xi, int yi, int xf, int yf, Image *imagen)
{
  QImage * borrador = new QImage(imagen->image_->copy(xi,yi,xf,yf));
  Image * roiImage = new Image(QString("ROI de: %1").arg(imagen->title_),borrador,this);
  appendImage(QString("ROI de: %1").arg(imagen->title_),roiImage);
}
///
/// \brief MainWindow::on_actionTransformaci_n_Lineal_Por_tramos_triggered
///
void MainWindow::on_actionTransformaci_n_Lineal_Por_tramos_triggered()
{
  Image * borrador;

  borrador= findImageAndNew(focus_,QString::fromUtf8("Tramos Lineales"));

  if (borrador!= nullptr)
    {
      QDialog * dialog = new QDialog(this);
      QVBoxLayout * layoutV = new QVBoxLayout();
      QLabel * label = new QLabel();
      QHBoxLayout * layoutH = new QHBoxLayout();
      QSpinBox * xI = new QSpinBox();
      QLabel * labelxI = new QLabel();
      QSpinBox * yI = new QSpinBox();
      QLabel * labelyI = new QLabel();
      QSpinBox * xF = new QSpinBox();
      QLabel * labelxF = new QLabel();
      QSpinBox * yF = new QSpinBox();
      QLabel * labelyF = new QLabel();
      QPushButton * pushButtonAppendTramo = new QPushButton("Agregar Tramo");
      QPushButton * pushButtonApply = new QPushButton("Aplicar");

      labelxI->setText("X Inicial ");
      labelxF->setText("X Final ");
      labelyI->setText("Y Inicial ");
      labelyF->setText("Y Final ");
      layoutH->addWidget(labelxI);
      layoutH->addWidget(xI);
      layoutH->addWidget(labelxF);
      layoutH->addWidget(xF);
      layoutH->addWidget(labelyI);
      layoutH->addWidget(yI);
      layoutH->addWidget(labelyF);
      layoutH->addWidget(yF);

      xI->setMinimum(0);
      xF->setMinimum(0);
      yI->setMinimum(0);
      yF->setMinimum(0);

      xI->setMaximum(255);
      xF->setMaximum(255);
      yI->setMaximum(255);
      yF->setMaximum(255);

      layoutH->addWidget(pushButtonAppendTramo);
      label->setText("Introduzca tramos de valores delimitados para la transformación.\nPuede agregar más de un tramo");
      layoutV->addWidget(label);
      layoutV->addLayout(layoutH);
      layoutV->addWidget(pushButtonApply);

      ///preparación del área de histograma.

      QChart * chart = new QChart();

      QValueAxis * axisX =new QValueAxis();
      QValueAxis * axisY =new QValueAxis();
      axisX->setRange(0,255);
      axisX->setTitleText("Color de pixel");
      axisY->setRange(0,255);
      axisY->setTitleText("Color de pixel");
      chart->setTitle("Tramos definidos");
      chart->addAxis(axisX,Qt::AlignBottom);
      chart->addAxis(axisY, Qt::AlignLeft);
      chart->legend()->setVisible(true);
      chart->legend()->setAlignment(Qt::AlignBottom);


      QChartView *histograma = new QChartView(chart);
      histograma->setRenderHint(QPainter::Antialiasing);

      layoutV->addWidget(histograma);
      histograma->setMinimumHeight(350);
      histograma->setMinimumWidth(350);


      dialog->setLayout(layoutV);
      dialog->setWindowTitle(QString::fromUtf8("Transformación lineal por tramos"));

      apply_ = false;
      borrador->newTramos(); ///para a segurarme que comenzamos desde cero.

      connect(pushButtonApply,(&QPushButton::clicked),[=](bool checked){

          if (borrador->toLinealTransform())
              apply_ = true;

          dialog->close();


      });
      connect(pushButtonAppendTramo,(&QPushButton::clicked),[=](bool checked){

         if  (borrador->appendTramo(xI->text().toDouble(),yI->text().toDouble(),xF->text().toDouble(),yF->text().toDouble()))
           {
              QLineSeries * linesPixelsCambian = new QLineSeries();

              linesPixelsCambian->append(xI->text().toInt(),yI->text().toInt());
              linesPixelsCambian->append(xF->text().toInt(),yF->text().toInt());
              linesPixelsCambian->setName(QString("Tramo [%1, %2]").arg(xI->text().toInt()).arg(xF->text().toInt()));

              chart->addSeries(linesPixelsCambian);
              linesPixelsCambian->attachAxis(axisX); ///restablezco las proporciones de los ejes
              linesPixelsCambian->attachAxis(axisY);

            xI->setMinimum(xF->text().toInt()+1);

           }



      });

      connect(dialog,(&QDialog::finished),[=](int result){
          if (!apply_)            
            delete borrador;          

      });

      dialog->exec();
     }


}


void MainWindow::on_actionEspejoVertical_triggered()
{
  Image * borrador;
  borrador = findImageAndNew(focus_,"Espejo Vertical");

  if (borrador != nullptr)
       borrador->toEspejoVertical();
}

void MainWindow::on_actionEspejoHorizontal_triggered()
{
  Image * borrador;
  borrador = findImageAndNew(focus_,"Espejo Horizontal");

  if (borrador != nullptr)
       borrador->toEspejoHorizontal();
}


void MainWindow::on_actionEspejoTraspuesta_triggered()
{
  Image * borrador;
  borrador = findImageAndNew(focus_,"Transpuesta");

  if (borrador != nullptr)
       borrador->toTransposed();

}

void MainWindow::on_actionRotacion90Izq_triggered()
{
  Image * borrador;
  borrador = findImageAndNew(focus_,"Rotada Izquierda");

  if (borrador != nullptr)
       borrador->toRotate90Left();

}

void MainWindow::on_actionRotacion90Derecha_triggered()
{
  Image * borrador;
  borrador = findImageAndNew(focus_,"Rotada Derecha");

  if (borrador != nullptr)
       borrador->toRotate90Right();


}

void MainWindow::on_actionEscalado_triggered()
{

}

void MainWindow::on_actionRotacionAIquierda_triggered()
{

}

void MainWindow::on_actionRotacionADerecha_triggered()
{

}
