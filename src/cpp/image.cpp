#include <image.h>
#include <mainwindow.h>

QT_CHARTS_USE_NAMESPACE

Image::Image(const QString fileImage,MainWindow * parent) :
      QDockWidget(fileImage,parent),
  //aqui fileImage tambiÃ©n es el titulo de la ventana
    nameFile_(fileImage),
    title_(fileImage),
    image_(new QImage(fileImage)),
    barGraphics_(nullptr),
    pixmapImage_(nullptr),
    isBarGraphics_(false),
    filterEvents_(new Events(this)),
    parent_(parent)
{

  prepare();

}

Image::Image(QString title,QImage *image,MainWindow * parent):
      QDockWidget(title,parent),
      image_(image),
      barGraphics_(nullptr),
      pixmapImage_(nullptr),
      isBarGraphics_(false),
      title_(title),
      nameFile_(title),
      filterEvents_(new Events(this)),
      parent_(parent)
{


  prepare();
}

Image::Image(QString title, QChartView *image, MainWindow *parent):
  QDockWidget(title,parent),
  image_(nullptr),
  barGraphics_(image),
  pixmapImage_(nullptr),
  isBarGraphics_(true),
  title_(title),
  nameFile_(title),
  filterEvents_(new Events(this)),
  parent_(parent)
{

  setButtonTitleBar(); ///configuro barra de titulos nueva.
  ///Preparo Dock widget acoplado pero con posibilidad de ser flotante
  /// Lo hago dentro de un QLabel que a la vez está dentro de un QScroolArea
  /// y a la vez dentro de un DockWidget.

  setMinimumHeight(50);
  setMinimumWidth(50);
  setMaximumWidth(1680);
  setMaximumHeight(1024);

  setGeometry(0,0,800,600);



    setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable  | QDockWidget::DockWidgetFloatable);
    setFloating(true);
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);


    setWidget(barGraphics_);


}

Image::~Image()
{



    qDebug() << "Destruyendo Image pixmapimage";
  if (pixmapImage_!= nullptr)
      delete pixmapImage_;

  qDebug() << "Destruyendo Image image_";

  if (image_ != nullptr)
    delete image_;

  qDebug() << "Destruyendo Image barGraphics_";
  if (barGraphics_ != nullptr)
    delete barGraphics_;

    qDebug() << "Destructor Image";
  if (filterEvents_ !=nullptr)
    delete filterEvents_;

}


bool Image::prepare()
{
  setButtonTitleBar(); ///configuro barra de titulos nueva.
  ///
  label_= new QLabel(this);
  pixmapImage_= new QPixmap();
  scrollArea_=new QScrollArea(this);
  scrollAreaWidgetContents_=new QWidget(this);
  dockWidgetContents_=new QWidget(this);
  gridLayoutDockWidgetContentsAndScrollArea_ =new QGridLayout(dockWidgetContents_);
  gridLayoutScrollAreaWidgetContentsAndLabel_=new QGridLayout(scrollAreaWidgetContents_);

  label_->setMouseTracking(true);
  label_->installEventFilter(filterEvents_);


  ///Preparo Dock widget acoplado pero con posibilidad de ser flotante
  /// Lo hago dentro de un QLabel que a la vez está dentro de un QScroolArea
  /// y a la vez dentro de un DockWidget.

    setContextMenuPolicy(Qt::DefaultContextMenu);

    setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable  | QDockWidget::DockWidgetFloatable );
    setAllowedAreas(Qt::AllDockWidgetAreas);
    setFloating(false);
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

   //scrollArea_->setWidgetResizable(true);



    if (image_->isNull())
          label_->setText(QString("Formato no admitido o ilegible para el fichero %1").arg(nameFile_));

      else
          updateImage();

          setGeometry(0,0,width_,height_);

        qDebug() << "ancho" << width_ << "alto " << height_;



    gridLayoutScrollAreaWidgetContentsAndLabel_->addWidget(label_,0,0,0,0);
    gridLayoutDockWidgetContentsAndScrollArea_->addWidget(scrollArea_,0,0,0,0);

    gridLayoutDockWidgetContentsAndScrollArea_->setContentsMargins(0,0,0,0);
    gridLayoutScrollAreaWidgetContentsAndLabel_->setContentsMargins(0,0,0,0);
    scrollArea_->setWidget(scrollAreaWidgetContents_);
    setWidget(dockWidgetContents_);


}


void Image::updateImage()
{

  brillo_blue_=0;
  brillo_gray_=0;
  brillo_green_=0;
  brillo_red_=0;
  contraste_blue_=0;
  contraste_gray_=0;
  contraste_green_=0;
  contraste_red_=0;


  setMinimumHeight(50);
  setMinimumWidth(50);
  setMaximumWidth(1024);
  setMaximumHeight(768);

  width_=image_->width();
  height_=image_->height();


  if (width_ <1024)
      setMaximumWidth(width_+8);

  if (height_<768)
      setMaximumHeight(height_+50);


  *pixmapImage_ = pixmapImage_->fromImage(*image_);
  label_->setPixmap(*pixmapImage_);
  label_->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  label_->setGeometry(0,0,width_,height_);


  format_=image_->format();

  if (format_ == QImage::Format_Indexed8)
    isGray_=true; ///si está en formato 8 bits, asume que serán solo 256 colores y
  ///los trato igual que si fueran grises
  else
    isGray_ = image_->isGrayscale();

  lutGray8bitsPrepare();

  calcular_histograma();

  calcular_histograma_acumulado();

  calcular_probabilidad_absoluto();

  calcular_probabilidad_acumulativo();

  calcular_brillo();

  calcular_contraste();

  calcular_entropia();

  qDebug() << image_->format()<< "Es gris : "<< isGray_ << "valor primer pixel "<< qRed(image_->pixel(0,0)) << ", " << qGreen(image_->pixel(0,0)) << "," << qBlue(image_->pixel(0,0));


}


void Image::calcular_histograma()
{

  histograma_.clear();
  histograma_.resize(256);
  redValueMax_=0;
  redValueMin_=255;
  blueValueMax_=0;
  blueValueMin_=255;
  greenValueMax_=0;
  greenValueMin_=255;
  grayValueMax_=0;
  grayValueMin_=255;




 for (int i=0; i < image_->height();i++)
   for (int j=0; j < image_->width();j++)
     {
        QRgb valor = image_->pixel(j,i);

        if (isGray_)
          {
            ///actualizo los valores de pixel máximo y mínimos.
            if (qRed(valor)> grayValueMax_)
                grayValueMax_=qRed(valor);

            if (qRed(valor)< grayValueMin_)
                grayValueMin_=qRed(valor);

            histograma_[qRed(valor)].countGray_++;
          }
        else {
            ///entonces tengo que actualizar los tres colores
            histograma_[qRed(valor)].countRed_++;
            histograma_[qGreen(valor)].countGreen_++;
            histograma_[qBlue(valor)].countBlue_++;

            if (qRed(valor)> redValueMax_)
                redValueMax_=qRed(valor);

            if (qRed(valor)< redValueMin_)
                redValueMin_=qRed(valor);

            if (qGreen(valor)> greenValueMax_)
                greenValueMax_=qGreen(valor);

            if (qGreen(valor)< greenValueMin_)
                greenValueMin_=qGreen(valor);

            if (qBlue(valor)> blueValueMax_)
                blueValueMax_=qBlue(valor);

            if (qBlue(valor)< blueValueMin_)
                blueValueMin_=qBlue(valor);

          }

     }

 ///ahora averiguo que tono de cada banda tiene más y menos píxeles asignados.
 ///
 toneBlueWidthLessPixels_=0;
 toneBlueWidthMorePixels_=0;
 toneGrayWidthLessPixels_=0;
 toneGrayWidthMorePixels_=0;
 toneGreenWidthLessPixels_=0;
 toneGreenWidthMorePixels_=0;
 toneRedWidthLessPixels_=0;
 toneRedWidthMorePixels_=0;

 double tmpMax = 0;
 double tmpMin = 0xFFFFFFFFFFFF;  ///equivalente a infinito

 for (int i=grayValueMin_; i <=grayValueMax_; i++)  ///miro solo desde el primer valor con pixeles hasta el último con pixeles,
   ///que no tiene porqué coincidir con todo el rango [0,255]
     {
          if (histograma_[i].countGray_ >= tmpMax)
            {
              toneGrayWidthMorePixels_ = i;
              tmpMax = histograma_[i].countGray_;
            }


          if ((histograma_[i].countGray_ <= tmpMin) && (histograma_[i].countGray_ > 0)) ///no incluyo los valores que tengan cero pixels
            {
              toneGrayWidthLessPixels_ = i;
              tmpMin = histograma_[i].countGray_;
            }

     }

 tmpMax = 0;
 tmpMin = 0xFFFFFFFFFFFF;

 for (int i=redValueMin_; i <=redValueMax_; i++)  ///miro solo desde el primer valor con pixeles hasta el último con pixeles,
   ///que no tiene porqué coincidir con todo el rango [0,255]
     {
          if (histograma_[i].countRed_ >= tmpMax)
            {
              toneRedWidthMorePixels_ = i;
              tmpMax = histograma_[i].countRed_;
            }

          if ((histograma_[i].countRed_ <= tmpMin)&& (histograma_[i].countRed_ > 0))
            {
              toneRedWidthLessPixels_ = i;
              tmpMin = histograma_[i].countRed_;
            }
     }

 tmpMax = 0;
 tmpMin = 0xFFFFFFFFFFFF;

 for (int i=greenValueMin_; i <=greenValueMax_; i++)  ///miro solo desde el primer valor con pixeles hasta el último con pixeles,
   ///que no tiene porqué coincidir con todo el rango [0,255]
     {

          if (histograma_[i].countGreen_ >= tmpMax)
            {
              toneGreenWidthMorePixels_ = i;
              tmpMax = histograma_[i].countGreen_;
            }


          if ((histograma_[i].countGreen_ <= tmpMin) && (histograma_[i].countGreen_ > 0))
            {
              toneGreenWidthLessPixels_ = i;
              tmpMin = histograma_[i].countGreen_;
            }

      }
 tmpMax = 0;
 tmpMin = 0xFFFFFFFFFFFF;
 for (int i=blueValueMin_; i <=blueValueMax_; i++)  ///miro solo desde el primer valor con pixeles hasta el último con pixeles,
   ///que no tiene porqué coincidir con todo el rango [0,255]
     {
          if (histograma_[i].countBlue_ >= tmpMax)
            {
              toneBlueWidthMorePixels_ = i;
              tmpMax = histograma_[i].countBlue_;
            }


          if ((histograma_[i].countBlue_ <= tmpMin) && (histograma_[i].countBlue_ > 0))
            {
            toneBlueWidthLessPixels_ = i;
            tmpMin = histograma_[i].countBlue_;
            }

     }
}

void Image::calcular_histograma_acumulado()
{
  histograma_acumulado_.clear();
  histograma_acumulado_.resize(256);

 if (isGray_)
  histograma_acumulado_[0].countGray_ = histograma_[0].countGray_; ///el primer valor del acumulado
  ///es igual al del absoluto
  ///
  else
   {
     histograma_acumulado_[0].countRed_ = histograma_[0].countRed_; ///el primer valor del acumulado
     ///es igual al del absoluto
     ///
     histograma_acumulado_[0].countGreen_ = histograma_[0].countGreen_; ///el primer valor del acumulado
     histograma_acumulado_[0].countBlue_ = histograma_[0].countBlue_; ///el primer valor del acumulado
   }

  for (int i=1; i < 256;i++)
  {
      if (isGray_)  
          histograma_acumulado_[i].countGray_ = histograma_acumulado_[i-1].countGray_ + histograma_[i].countGray_;

      else {
            histograma_acumulado_[i].countRed_ = histograma_acumulado_[i-1].countRed_ + histograma_[i].countRed_;
            histograma_acumulado_[i].countGreen_ = histograma_acumulado_[i-1].countGreen_ + histograma_[i].countGreen_;
            histograma_acumulado_[i].countBlue_ = histograma_acumulado_[i-1].countBlue_ + histograma_[i].countBlue_;
        }
  }

}

void Image::calcular_brillo()
{
  for (int i=0; i< 256;i++)
  {
      if (isGray_)
        brillo_gray_ = brillo_gray_ + (histograma_[i].countGray_ * i);
      else {
          brillo_red_=brillo_red_+(histograma_[i].countRed_ * i);
          brillo_green_=brillo_green_ + (histograma_[i].countGreen_ * i);
          brillo_blue_=brillo_blue_ + (histograma_[i].countBlue_ * i);
        }
  }

  if (isGray_)
    {
      brillo_gray_ = brillo_gray_ / (width_* height_);
      brillo_gray_=round(brillo_gray_);
    }
  else {
      brillo_green_ = brillo_green_ / (width_* height_);
      brillo_green_=round(brillo_green_);

      brillo_blue_ = brillo_blue_ / (width_* height_);
      brillo_blue_=round(brillo_blue_);

      brillo_red_ = brillo_red_ / (width_* height_);
      brillo_red_=round(brillo_red_);

    }
}

void Image::calcular_contraste()
{
  ///ya con el brillo calculado
  double a,b;
  for (int i=0; i< 256;i++)
  {
      if (isGray_)
        {
          /// resuelvo (i-media)^2 mediante el cuadrado de una diferencia
          a = pow(i,2);
          a = a - (2*i*brillo_gray_);
          b = pow(brillo_gray_,2);
          a= a +b;  ///en a resultado del cuadrado de una diferencia
          contraste_gray_= contraste_gray_ + (histograma_[i].countGray_ * a);

        }

      else {

          /// resuelvo (i-media)^2 mediante el cuadrado de una diferencia
          a = pow(i,2);
          a = a - (2*i*brillo_red_);
          b = pow(brillo_red_,2);
          a= a +b;  ///en a resultado del cuadrado de una diferencia
          contraste_red_= contraste_red_ + (histograma_[i].countRed_ * a);

          /// resuelvo (i-media)^2 mediante el cuadrado de una diferencia
          a = pow(i,2);
          a = a - (2*i*brillo_green_);
          b = pow(brillo_green_,2);
          a= a +b;  ///en a resultado del cuadrado de una diferencia
          contraste_green_=contraste_green_ + (histograma_[i].countGreen_ * a);

          /// resuelvo (i-media)^2 mediante el cuadrado de una diferencia
          a = pow(i,2);
          a = a - (2*i*brillo_blue_);
          b = pow(brillo_blue_,2);
          a= a +b;  ///en a resultado del cuadrado de una diferencia
          contraste_blue_=contraste_blue_ + (histograma_[i].countBlue_ * a);


        }
  }

  if (isGray_)
    {

      contraste_gray_ = contraste_gray_ / (width_* height_);
      contraste_gray_ = sqrt(contraste_gray_);
      contraste_gray_=round(contraste_gray_);
      if (contraste_gray_ < 1)
        contraste_gray_ =1; ///no dejo que el contraste sea nunca cero, porque para los calculos de brillo y contraste podría fallar las divisiones.
    }
  else {
      contraste_green_ = contraste_green_ / (width_* height_);
      contraste_green_ = sqrt(contraste_green_);
      contraste_green_=round(contraste_green_);

      contraste_blue_ = contraste_blue_ / (width_* height_);
      contraste_blue_ = sqrt(contraste_blue_);
      contraste_blue_=round(contraste_blue_);

      contraste_red_ = contraste_red_ / (width_* height_);
      contraste_red_ = sqrt(contraste_red_);
      contraste_red_=round(contraste_red_);

    }


}

void Image::calcular_probabilidad_absoluto()
{
  for (int i=0; i < 256; i++)
  {
    if (isGray_)
        histograma_[i].probabilidadGray_=histograma_[i].countGray_ / (width_*height_);

    else {
        histograma_[i].probabilidadRed_=histograma_[i].countRed_ / (width_*height_);
        histograma_[i].probabilidadGreen_=histograma_[i].countGreen_ / (width_*height_);
        histograma_[i].probabilidadBlue_=histograma_[i].countBlue_ / (width_*height_);
      }
  }

}

void Image::calcular_probabilidad_acumulativo()
{

  if (isGray_)
   histograma_acumulado_[0].probabilidadGray_ = histograma_[0].probabilidadGray_; ///el primer valor del acumulado
   ///es igual al del absoluto
   ///
   else
    {
      histograma_acumulado_[0].probabilidadRed_ = histograma_[0].probabilidadRed_; ///el primer valor del acumulado
      ///es igual al del absoluto
      ///
      histograma_acumulado_[0].probabilidadGreen_ = histograma_[0].probabilidadGreen_; ///el primer valor del acumulado
      histograma_acumulado_[0].probabilidadBlue_ = histograma_[0].probabilidadBlue_; ///el primer valor del acumulado
    }

  for (int i=1; i < 256;i++)
  {
      if (isGray_)
          histograma_acumulado_[i].probabilidadGray_=histograma_acumulado_[i-1].probabilidadGray_ + histograma_[i].probabilidadGray_;
      else {
            histograma_acumulado_[i].probabilidadRed_=histograma_acumulado_[i-1].probabilidadRed_ + histograma_[i].probabilidadRed_;
            histograma_acumulado_[i].probabilidadGreen_=histograma_acumulado_[i-1].probabilidadGreen_ + histograma_[i].probabilidadGreen_;
            histograma_acumulado_[i].probabilidadBlue_=histograma_acumulado_[i-1].probabilidadBlue_ + histograma_[i].probabilidadBlue_;
        }
  }

}

void Image::calcular_entropia()
{
  ///fórmula:
  /// E= - sumatorio(0-255) p(i) * log2 P(i)
  /// donde p es la probabilidad del histograma absoluto y P probabilidad del histograma acumulado.
  double logaritmo,tmp;
  entropia_=0;

  for (int i=0; i < 256; i++)
    {
     if (isGray_)
       {

         if (histograma_[i].probabilidadGray_ > 0.0)
           {
             logaritmo = log2(histograma_[i].probabilidadGray_);
             tmp = histograma_[i].probabilidadGray_ * logaritmo;
              entropia_ = entropia_ + tmp;

           }
       }
     else
          entropia_=0; ///sinifica que no la he hecho. no se como sería para color


    }
  entropia_=entropia_ * (-1); ///tengo que cambiar el signo

}

///función Gamma
///

///
void Image::funcionGamma(double value)
{
  ///Fórmula funciona Gamma utilizada
  /// ((Vin/255)^gamma) * 255 = Vout
  ///  Se hace con redondeo y rango entre 0 -255
  ///
  if (isGray_)
    {
      QVector <int> Lut(256);
      double tmp;
      ///preparo la nueva LUT
      for (int i=0;i < 256; i++)
        {
          tmp = i/255.0;
          tmp = pow(tmp,value);
          tmp = round(tmp *255);
          if (tmp<0)
               tmp= 0;
          if (tmp>255)
               tmp=255;

           Lut[i]=(int)tmp;
        }


      for (int i=0; i < height_; i++)
         for (int j=0; j < width_; j++)
            if (format_ == QImage::Format_Indexed8)
                        image_->setPixel(j,i,Lut[qRed(image_->pixel(j,i))]); ///solo un byte, ya la imagen se adecua con su LUT de grises
             else
              {
                int tmp2 =Lut[qRed(image_->pixel(j,i))];
               image_->setPixel(j,i,qRgb(tmp2,tmp2,tmp2)); ///En rgb, pongo los tres colores al mismo valor

              }


    }
  else {

      QVector<int>  LutRed(256);
      QVector<int>  LutGreen(256);
      QVector<int>  LutBlue(256);

      double tmpRed,tmpGreen,tmpBlue;

      ///preparo la LUT

       for (int i=0;i < 256; i++)
         {
           tmpRed = i/255.0;
           tmpRed = pow(tmpRed,value);
           tmpRed = round(tmpRed *255);
           if (tmpRed<0)
                tmpRed= 0;
           if (tmpRed>255)
                tmpRed=255;


           tmpGreen = i/255.0;
           tmpGreen = pow(tmpGreen,value);
           tmpGreen = round(tmpGreen *255);
           if (tmpGreen<0)
                tmpGreen= 0;
           if (tmpGreen>255)
                tmpGreen=255;

           tmpBlue = i/255.0;
           tmpBlue = pow(tmpBlue,value);
           tmpBlue = round(tmpBlue *255);
           if (tmpBlue<0)
                tmpBlue= 0;
           if (tmpBlue>255)
                tmpBlue=255;


           LutRed[i]=(int)round(tmpRed);
           LutGreen[i]=(int)round(tmpGreen);
           LutBlue[i]=(int)round(tmpBlue);

         }

       ///ahora reasigno los puntos de la imagen en correspondencia con la nueva
       /// LUT


    for (int i=0; i < height_; i++)
       for (int j=0; j < width_; j++)
         {
           QRgb valor = image_->pixel(j,i);
           QRgb newValor = qRgb(LutRed[qRed(valor)],LutGreen[qGreen(valor)],LutBlue[qBlue(valor)]);
           image_->setPixel(j,i,newValor);
         }

    }
  updateImage();
}

void Image::brilloYContrasteGris(double brilloNuevoGris, double contrasteNuevoGris)
{
  ///uso la fórmula de la recta para obtener una nueva LUT acorde a el nuevo
  /// brillo y contraste
  /// y= Ax + B
  /// A= contraste nuevo / contraste actual
  /// B= Brillo nuevo - A * Brillo Actual
  ///
  double A,B;

  if (isGray_)
    {
      ///formula para optener el coeficiente A      
      A = contrasteNuevoGris / contraste_gray_;
      B = brilloNuevoGris - (A*brillo_gray_);

      ///preparo la LUT
      QVector<int>  LUT(256);
      double tmp;
      pixelsGrayTo0=0;
      pixelsGrayTo255=0;


       for (int i=0;i < 256; i++)
         {
           tmp = (A * i) + B;
           if (tmp < 0)
             {
             tmp = 0;
             pixelsGrayTo0++;
             }

           if (tmp > 255)
             {
             tmp = 255;
                 pixelsGrayTo255++;
             }

           LUT[i]=(int)round(tmp);

         }

       ///ahora reasigno los puntos de la imagen en correspondencia con la nueva
       /// LUT


    for (int i=0; i < height_; i++)
       for (int j=0; j < width_; j++)
          if (format_ == QImage::Format_Indexed8)
                      image_->setPixel(j,i,LUT[qRed(image_->pixel(j,i))]); ///solo un byte, ya la imagen se adecua con su LUT de grises
           else
            {
              int tmp =LUT[qRed(image_->pixel(j,i))];
             image_->setPixel(j,i,qRgb(tmp,tmp,tmp)); ///En rgb, pongo los tres colores al mismo valor

            }



    }

  updateImage();

}

void Image::brilloYContrasteColor(double brilloNuevoRed, double contrasteNuevoRed,double brilloNuevoGreen, double contrasteNuevoGreen,double brilloNuevoBlue, double contrasteNuevoBlue)
{
  ///uso la fórmula de la recta para obtener una nueva LUT acorde a el nuevo
  /// brillo y contraste
  /// y= Ax + B
  /// A= contraste nuevo / contraste actual
  /// B= Brillo nuevo - A * Brillo Actual
  ///
  double aRed,aGreen,aBlue,bRed,bGreen,bBlue;
  QVector<int>  LutRed(256);
  QVector<int>  LutGreen(256);
  QVector<int>  LutBlue(256);

  double tmpRed,tmpGreen,tmpBlue;

  if (!isGray_)
    {
      ///primero calculo el nuevo valor para el rojo
      ///formula para optener el coeficiente A
      aRed = contrasteNuevoRed / contraste_red_;
      bRed = brilloNuevoRed - (aRed*brillo_red_);

      aGreen = contrasteNuevoGreen / contraste_green_;
      bGreen = brilloNuevoGreen - (aGreen*brillo_green_);

      aBlue = contrasteNuevoBlue / contraste_blue_;
      bBlue = brilloNuevoBlue - (aBlue*brillo_blue_);

      ///preparo la LUT

      pixelsRedTo0=0;
      pixelsRedTo255=0;

      pixelsGreenTo0=0;
      pixelsGreenTo255=0;

      pixelsBlueTo0=0;
      pixelsBlueTo255=0;


       for (int i=0;i < 256; i++)
         {
           tmpRed = (aRed * i) + bRed;
           if (tmpRed < 0)
             {
             tmpRed = 0;
             pixelsRedTo0++;
             }

           if (tmpRed > 255)
             {
             tmpRed = 255;
                 pixelsRedTo255++;
             }

           tmpGreen = (aGreen * i) + bGreen;
           if (tmpGreen < 0)
             {
             tmpGreen = 0;
             pixelsGreenTo0++;
             }

           if (tmpGreen > 255)
             {
             tmpGreen = 255;
                 pixelsGreenTo255++;
             }

           tmpBlue = (aBlue * i) + bBlue;
           if (tmpBlue < 0)
             {
             tmpBlue = 0;
             pixelsBlueTo0++;
             }

           if (tmpBlue > 255)
             {
             tmpBlue = 255;
                 pixelsBlueTo255++;
             }


           LutRed[i]=(int)round(tmpRed);
           LutGreen[i]=(int)round(tmpGreen);
           LutBlue[i]=(int)round(tmpBlue);

         }

       ///ahora reasigno los puntos de la imagen en correspondencia con la nueva
       /// LUT


    for (int i=0; i < height_; i++)
       for (int j=0; j < width_; j++)
         {
           QRgb valor = image_->pixel(j,i);
           QRgb newValor = qRgb(LutRed[qRed(valor)],LutGreen[qGreen(valor)],LutBlue[qBlue(valor)]);
           image_->setPixel(j,i,newValor);
         }



    }

  updateImage();

}
bool Image::lutGray8bitsPrepare()
{

  lutGray8bits_.clear();
  lutGray8bits_.resize(256);

 for (int i=0; i < 255;i++)
    lutGray8bits_[i] = qRgb(i,i,i);

return  true;
}

///
/// \brief Image::toGray
/// \param source
/// \param target
/// \param ntsc
/// \return
///Debuelve un QImage con la imagen en formato 256 colores,8 bits y escala de grises
/// El receptor será el encargado crear su delete
/// Convierte la imagen a escala de grises formato 8 bits
void Image::toGray(bool ntsc,bool ochobits)
{
  ///Se puede convertir de color RGB a gris RGB o gris ocho bits. TAmbién de gris RGB a gris ocho bits o bien
  /// de gris ocho bits a gris RGB.
  double coeficienteRed,coeficienteGreen,coeficienteBlue;
  QImage * target;
  ///establezco coeficientes dependiendo ntsc o pal
  if (ntsc)
    {
      coeficienteRed = 0.299;
      coeficienteGreen = 0.587;
      coeficienteBlue = 0.114;

    }
  else {

      coeficienteRed = 0.222;
      coeficienteGreen = 0.707;
      coeficienteBlue = 0.071;
    }

  if (ochobits)
    {
      target =new QImage(width_,height_, QImage::Format_Indexed8);
      ///Asigno la LUT de grises a la imagen nueva
      target->setColorTable(lutGray8bits_);
    }
  else
      target = new QImage(width_,height_,QImage::Format_RGB32);
      ///

      ///
    int tmpGray;

          for (int i=0; i < height_;i++)
            for (int j=0; j < width_;j++)
              {
                if ((format_ == QImage::Format_Indexed8) && (isGray_)) ///si es ocho bits gris
                       tmpGray = qRed(image_->pixel(j,i)); ///con coger solo el primer byte es suficiente

                else if (format_ != QImage::Format_Indexed8)
                       tmpGray = (qRed(image_->pixel(j,i)) * coeficienteRed) + (qBlue(image_->pixel(j,i))*coeficienteBlue) + (qGreen(image_->pixel(j,i))*coeficienteGreen);


                if (ochobits) ///si es ocho bits gris
                      target->setPixel(j,i,tmpGray);
                else
                    target->setPixel(j,i,qRgb(tmpGray,tmpGray,tmpGray)); ///En rgb, pongo los tres colores al mismo valor

              }
          setImage(target);

}
///Función Ecualizacón. Caso específico de especificación de histograma
///
///
void Image::toEcualizer()
{
  ///Fórmula
  /// m=2^8
  /// vout= max[0,round((m/size)*Histograma acumulado(Vin) -1
  ///
 if (isGray_)
    {
      QVector <int> Lut(256);
      double tmp;
      ///preparo la nueva LUT
      for (int i=0;i < 256; i++)
        {
          tmp = histograma_acumulado_[i].countGray_  / (width_*height_);
          tmp = round(tmp *256);
          tmp = tmp -1;

          if (tmp<0)
               tmp= 0;
          if (tmp>255)
               tmp=255;

           Lut[i]=(int)tmp;
        }


      for (int i=0; i < height_; i++)
         for (int j=0; j < width_; j++)
            if (format_ == QImage::Format_Indexed8)
                        image_->setPixel(j,i,Lut[qRed(image_->pixel(j,i))]); ///solo un byte, ya la imagen se adecua con su LUT de grises
             else
              {
                int tmp2 =Lut[qRed(image_->pixel(j,i))];
               image_->setPixel(j,i,qRgb(tmp2,tmp2,tmp2)); ///En rgb, pongo los tres colores al mismo valor

              }


    }

 else {
     QVector<int>  LutRed(256);
     QVector<int>  LutGreen(256);
     QVector<int>  LutBlue(256);

     double tmpRed,tmpGreen,tmpBlue;

     ///preparo la LUT
      for (int i=0;i < 256; i++)
        {
          tmpRed = histograma_acumulado_[i].countRed_  / (width_*height_);
          tmpRed = round(tmpRed *256);
          tmpRed = tmpRed -1;

          if (tmpRed<0)
               tmpRed= 0;
          if (tmpRed>255)
               tmpRed=255;


          tmpGreen = histograma_acumulado_[i].countGreen_  / (width_*height_);
          tmpGreen = round(tmpGreen *256);
          tmpGreen = tmpGreen -1;

          if (tmpGreen<0)
               tmpGreen= 0;
          if (tmpGreen>255)
               tmpGreen=255;



          tmpBlue = histograma_acumulado_[i].countBlue_  / (width_*height_);
          tmpBlue = round(tmpBlue *256);
          tmpBlue = tmpBlue -1;

          if (tmpBlue<0)
               tmpBlue= 0;
          if (tmpBlue>255)
               tmpBlue=255;

          LutRed[i]=(int)tmpRed;
          LutGreen[i]=(int)tmpGreen;
          LutBlue[i]=(int)tmpBlue;
        }

      for (int i=0; i < height_; i++)
         for (int j=0; j < width_; j++)
               image_->setPixel(j,i,qRgb(LutRed[qRed(image_->pixel(j,i))],LutGreen[qGreen(image_->pixel(j,i))],LutBlue[qBlue(image_->pixel(j,i))])); ///En rgb, pongo los tres colores

   }

 updateImage();
}
///
/// Especificación de histograma.
/// \brief Image::toHistogramaEspecificado
/// \param targetHistograma
///
void Image::toHistogramaEspecificado(Image *targetHistograma)
{
  ///Fórmula
  /// vout= histogramaAcumulado_imagen_destino^-1[HistogramaAcumulado_imagen_origen(vin)]
  ///Aquí trabajo con los histogramas normalizados para no depender y tener que controlar los tamaños
  /// e la imagen.
 if (isGray_)
    {
      QVector <int> Lut(256);
      double tmp,a,b;
      int j=0;
      ///preparo la nueva LUT
      for (int i=0;i < 256; i++)
        {
          tmp = histograma_acumulado_[i].probabilidadGray_;          
          ///
          ///busco su correspondiente en el histograma destino.
          ///
          j=0;
          while (tmp > targetHistograma->histograma_acumulado_[j].probabilidadGray_)
              j++;

           a = tmp - targetHistograma->histograma_acumulado_[j-1].probabilidadGray_; ///resto al valor el resultado de probabiliad del pixel justo anterior.
           b = targetHistograma->histograma_acumulado_[j].probabilidadGray_ - tmp ;///resto al valor del pixel superior, el valor encontrado

           ///me quedo con la distancia menor, o sea, la probabilidad que  se acerca más al pixel, ya sea, el anterior o el posterior

           if (a <= b )
             Lut[i] = j-1; ///me quedo con el pixel con probabilidad justo anterior
           if (a > b)
             Lut[i] = j; ///lo convierto al pixel con probabilidad un poco superior.         
        }


      for (int i=0; i < height_; i++)
         for (int j=0; j < width_; j++)
            if (format_ == QImage::Format_Indexed8)
                        image_->setPixel(j,i,Lut[qRed(image_->pixel(j,i))]); ///solo un byte, ya la imagen se adecua con su LUT de grises
             else
              {
                int tmp2 =Lut[qRed(image_->pixel(j,i))];
               image_->setPixel(j,i,qRgb(tmp2,tmp2,tmp2)); ///En rgb, pongo los tres colores al mismo valor

              }

    }

 else {
    QVector<int>  LutRed(256);
     QVector<int>  LutGreen(256);
     QVector<int>  LutBlue(256);

     double tmpRed,tmpGreen,tmpBlue,a,b;
     int j=0;
     ///preparo la LUT
      for (int i=0;i < 256; i++)
        {
          tmpRed = histograma_acumulado_[i].probabilidadRed_;
          ///
          ///busco su correspondiente en el histograma destino.
          ///
          j=0;
          while (tmpRed > targetHistograma->histograma_acumulado_[j].probabilidadRed_)
              j++;

           a = tmpRed - targetHistograma->histograma_acumulado_[j-1].probabilidadRed_; ///resto al valor el resultado de probabiliad del pixel justo anterior.
           b = targetHistograma->histograma_acumulado_[j].probabilidadRed_ - tmpRed ;///resto al valor del pixel superior, el valor encontrado

           ///me quedo con la distancia menor, o sea, la probabilidad que  se acerca más al pixel, ya sea, el anterior o el posterior

           if (a <= b )
             LutRed[i] = j-1; ///me quedo con el pixel con probabilidad justo anterior
           if (a > b)
             LutRed[i] = j; ///lo convierto al pixel con probabilidad un poco superior.


           tmpGreen = histograma_acumulado_[i].probabilidadGreen_;
           ///
           ///busco su correspondiente en el histograma destino.
           ///
           j=0;
           while (tmpGreen > targetHistograma->histograma_acumulado_[j].probabilidadGreen_)
               j++;

            a = tmpGreen - targetHistograma->histograma_acumulado_[j-1].probabilidadGreen_; ///resto al valor el resultado de probabiliad del pixel justo anterior.
            b = targetHistograma->histograma_acumulado_[j].probabilidadGreen_ - tmpGreen ;///resto al valor del pixel superior, el valor encontrado

            ///me quedo con la distancia menor, o sea, la probabilidad que  se acerca más al pixel, ya sea, el anterior o el posterior

            if (a <= b )
              LutGreen[i] = j-1; ///me quedo con el pixel con probabilidad justo anterior
            if (a > b)
              LutGreen[i] = j; ///lo convierto al pixel con probabilidad un poco superior.

            tmpBlue = histograma_acumulado_[i].probabilidadBlue_;
            ///
            ///busco su correspondiente en el histograma destino.
            ///
            j=0;
            while (tmpBlue > targetHistograma->histograma_acumulado_[j].probabilidadBlue_)
                j++;

             a = tmpBlue - targetHistograma->histograma_acumulado_[j-1].probabilidadBlue_; ///resto al valor el resultado de probabiliad del pixel justo anterior.
             b = targetHistograma->histograma_acumulado_[j].probabilidadBlue_ - tmpBlue ;///resto al valor del pixel superior, el valor encontrado

             ///me quedo con la distancia menor, o sea, la probabilidad que  se acerca más al pixel, ya sea, el anterior o el posterior

             if (a <= b )
               LutBlue[i] = j-1; ///me quedo con el pixel con probabilidad justo anterior
             if (a > b)
               LutBlue[i] = j; ///lo convierto al pixel con probabilidad un poco superior.


        }

      for (int i=0; i < height_; i++)
         for (int j=0; j < width_; j++)
               image_->setPixel(j,i,qRgb(LutRed[qRed(image_->pixel(j,i))],LutGreen[qGreen(image_->pixel(j,i))],LutBlue[qBlue(image_->pixel(j,i))])); ///En rgb, pongo los tres colores

   }

 updateImage();
}
///Pinto de color rojo los pixeles  de la imagen que difieren en base a un umbral especificado de otra imagen
/// \brief Image::toMapChange
/// \param imagen
///
bool Image::toMapChange(Image *imagen)
{
  QImage * borradorOriginal  = getImage();  ///hago una copia de la imagen original
  QImage * borradorDiferencia = nullptr;

  if (toDifference(imagen))  ///si se pudo realizar la diferencia
       borradorDiferencia = getImage();  ///hago una copia de la imagen ya restada. Imagen diferencia
  else
    {
      delete borradorOriginal;
      return false;
    }

  QImage * target = new QImage(width_,height_,QImage::Format_RGB32); ///para poder indicar el mapa de cambios, si o si, cambio este objeto a imagen a color
  ///puesto que si fuera gris 8 bits, no prodría.

      QDialog *dialog = new QDialog(this);
      QSpinBox * spin = new QSpinBox(dialog);
      QLabel *  label = new QLabel(dialog);
      QVBoxLayout * layout = new QVBoxLayout(dialog);

      dialog->setWindowTitle("Valor Umbral");
      label->setText("Indique el valor umbral a considerar para el mapa de cambios");
      layout->addWidget(label);
      layout->addWidget(spin);
      dialog->setLayout(layout);
      spin->setMinimum(0);
      spin->setMaximum(255);
      spin->setValue(255);


      QChartView * histograma = toHistograma(false);
       ///muestro el histograma absoluto de la imagen diferencia. Para que el usuario pueda decidir mejor el  umbrarl a especificar
      histograma->setMinimumHeight(250);
      histograma->setMinimumWidth(250);
      layout->addWidget(histograma);

      setImage(target); ///stablecer la imagen a color con los cambios posibles, puesto que la diferencia me modificó el objecto. Ya la imagen diferencia la tengo guardada en borradorDiferencia
      indicarCambios(255,borradorOriginal, borradorDiferencia); ///primero muestro la imagen sin cambios, o sea, con umbral máximo.




      dialog->show();
      histograma->show();

      connect(spin,QOverload<int>::of(&QSpinBox::valueChanged),[=](int d){

          ///
          indicarCambios(spin->value(),borradorOriginal,borradorDiferencia); ///función privada que pinta en rojo los pixeles en base al umbral seleccionado

      });


      connect(dialog,(&QDialog::finished),[=](int result){

        delete borradorOriginal;
        delete borradorDiferencia;
        delete histograma;

      });



}
///
/// \brief Image::indicarCambios
/// \param value
///
void Image::indicarCambios(int value, QImage * original,QImage * diferencia)
{

  for (int i=0; i < height_; i++)
      for (int j=0; j < width_; j++)
        {
          if (original->allGray())  ///durante la operación de diferencia, ya se comprobó que la imagen diferencia también fuera del mismo tipo.
                 if (qRed(diferencia->pixel(j,i)) >= value)
                      image_->setPixel(j,i,qRgb(255,0,0)); ///pongo a rojo, si es diferente Aqui la imagen destino realmente es una RGB  para poder pintar el rojo
                 else
                      image_->setPixel(j,i,qRgb(qRed(original->pixel(j,i)),qRed(original->pixel(j,i)),qRed(original->pixel(j,i))));
          else {
              ///imagen a color
              ///
            }

        }
updateImage();
}



///Calcula la diferencia de esta imagen con otra. Si se pudo realizar  devuelve true, de lo contrario false
/// \brief Image::toImageDifference
/// \param imagen
///
bool Image::toDifference(Image *imagen)
{
  int borrador;
  if (((width_*height_) == (imagen->width_*height_)) && (isGray_ == imagen->isGray_) && (format_ == imagen->format_)) ///si son del mismo tamaño, tipo de formato y si son gris o no. puedo operar
    for (int i=0; i < height_; i++)
      for (int j=0; j < width_; j++)
        {
          if (isGray_)

            if (format_ == QImage::Format_Indexed8)
               {
                borrador = qAbs(qRed(image_->pixel(j,i)) - qRed(imagen->image_->pixel(j,i))); ///resto valor de pixel y me quedo con valor absoluto.
                 image_->setPixel(j,i,borrador);
               }

            else
              {
                borrador = qAbs(qRed(image_->pixel(j,i)) - qRed(imagen->image_->pixel(j,i))); ///resto valor de pixel y me quedo con valor absoluto.
                image_->setPixel(j,i,qRgb(borrador,borrador,borrador)); ///En rgb, pongo los tres colores al mismo valor

              }
          else {
              ///imagen a color
              ///
            }
       }
  else
     {
      QMessageBox::warning(nullptr,QString::fromUtf8("Atención: Tamaños o Tipos de imagen diferentes"),QString::fromUtf8("No se puede realizar la diferencia de imágenes diferentes.\nSeleccione otra imagen"));
      return false;
    }
updateImage();
return true;
}

///Devuelvo una copia de la imagen en formato QImage. El receptor se encargará
/// de su destrucción
QImage *Image::getImage()
{
  QImage * tmp =new QImage(*image_);
  return tmp;
}
///
/// \brief Image::setImage
/// \param imagen
///Esta función toma posesión de la imagen y simplemente sustituye un puntero por otro
/// y libera la memoria. Muy rápido
void Image::setImage(QImage *imagen)
{
  delete image_; ///borro imagen anterior
  ///asigno a imagen nueva. Tomo posesión de la imagen, ya se liberará al destruirse el objeto.
  image_  = imagen;

  updateImage();
}
///
/// \brief Image::setImage
/// \param imagen
///Esta función copia una imagen en este objeto. Es lenta pero mantiene simepre la imagen
/// pasada como argumento intacta. Es lenta y no toma posesión de la imagen pasada.
void Image::setImage(QImage &imagen)
{

  *image_  = imagen;

  updateImage();
}


QChartView *Image::toHistograma(bool acumulativo)
{  
  QChart * chart = new QChart();

  if (acumulativo)
    chart->setTitle("Histograma Acumulativo");
  else
   chart->setTitle("Histograma Absoluto");

  QValueAxis * axisX =new QValueAxis();
  QValueAxis * axisY =new QValueAxis();

  axisX->setRange(0,255);
 /// axisX->applyNiceNumbers();
  axisX->setTickCount(7);
  axisY->setTickCount(10);
  axisY->setTitleText("Cantidad de Pixels");
  chart->addAxis(axisX,Qt::AlignBottom);
  chart->addAxis(axisY, Qt::AlignLeft);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  if (acumulativo)
      axisY->setRange(0,width_*height_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar , en caso del acumulativo, el tamaño total de la imagen

  if (isGray_)
    {      
      QLineSeries *linesGray = new QLineSeries();
      linesGray->setName("Tono de Gris");
      linesGray->setColor(Qt::black);

      if (!acumulativo)
          axisY->setRange(0,histograma_[toneGrayWidthMorePixels_].countGray_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar

        for (int i=0; i < 256; i++)
          if (acumulativo)
            linesGray->append(i,histograma_acumulado_[i].countGray_);
          else
            linesGray->append(i,histograma_[i].countGray_);

     chart->addSeries(linesGray);
     axisX->setTitleText(QString("Brillo : %1 | Contraste %2").arg(brillo_gray_).arg(contraste_gray_));
    }
  else
        {


      if (!acumulativo)
      ///Aquí busco la escala basándome en el tono con mayor número de pixeles, ya que muestro las tres
      /// gráficas RGB simultáneamente.
          if (toneRedWidthMorePixels_>=toneGreenWidthMorePixels_)
              if (toneRedWidthMorePixels_>=toneBlueWidthMorePixels_)
                  axisY->setRange(0,histograma_[toneRedWidthMorePixels_].countRed_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar

              else if (toneGreenWidthMorePixels_>=toneBlueWidthMorePixels_)
                     axisY->setRange(0,histograma_[toneGreenWidthMorePixels_].countGreen_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar

              else
                axisY->setRange(0,histograma_[toneBlueWidthMorePixels_].countBlue_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar

            else if (toneGreenWidthMorePixels_>=toneBlueWidthMorePixels_)
                   axisY->setRange(0,histograma_[toneGreenWidthMorePixels_].countGreen_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar

            else
              axisY->setRange(0,histograma_[toneBlueWidthMorePixels_].countBlue_); ///ajusto el rango Y del histograma al máximo valor que realmente puede alcanzar


          QLineSeries *linesRed = new QLineSeries();
          QLineSeries *linesGreen = new QLineSeries();
          QLineSeries *linesBlue = new QLineSeries();
          linesRed->setName("Tono de Rojo");
          linesRed->setColor(Qt::red);
          linesGreen->setName("Tono de Verde");
          linesGreen->setColor(Qt::green);
          linesBlue->setColor(Qt::blue);
          linesBlue->setName("Tono de Azul");

          for (int i=0; i < 256; i++)
            {
              if (acumulativo)
                {
                linesRed->append(i,histograma_acumulado_[i].countRed_);
                linesGreen->append(i,histograma_acumulado_[i].countGreen_);
                linesBlue->append(i,histograma_acumulado_[i].countBlue_);
                }


              else {
                    linesRed->append(i,histograma_[i].countRed_);
                    linesGreen->append(i,histograma_[i].countGreen_);
                    linesBlue->append(i,histograma_[i].countBlue_);
                }
            }

          chart->addSeries(linesRed);
          chart->addSeries(linesGreen);
          chart->addSeries(linesBlue);
          axisX->setTitleText(QString("Rojo: Brillo %1 y Contraste %2 | Verde: Brillo %3 y Contraste %4 | Azul: Brillo %5 y Contraste %6").arg(brillo_red_).arg(contraste_red_).arg(brillo_green_).arg(contraste_green_).arg(brillo_blue_).arg(contraste_blue_));

       }


  axisY->applyNiceNumbers();

  QChartView * chartview = new QChartView(chart);
  chartview->setRenderHint(QPainter::Antialiasing);

  return chartview;

}

void Image::setButtonTitleBar()
{
  QWidget * barNew = new QWidget(this);
  QLabel *label = new QLabel(barNew);
  QHBoxLayout * layout = new QHBoxLayout(barNew);
  QPushButton * pushButtonMax = new QPushButton(barNew);
  QPushButton * pushButtonMin = new QPushButton(barNew);
  QPushButton * pushButtonClose = new QPushButton(barNew);


  barNew->setLayout(layout);
  layout->addWidget(label);
  layout->addWidget(pushButtonMin);
  layout->addWidget(pushButtonMax);
  layout->addWidget(pushButtonClose);
  label->setText(title_);
  label->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
  label->setAlignment(Qt::AlignLeft);


///preparo iconos
///
  QIcon icon = pushButtonMax->style()->standardIcon(QStyle::SP_TitleBarMaxButton, 0,pushButtonMax);
  pushButtonMax->setIcon( icon );
  pushButtonMax->setIconSize(QSize(10,10));
  pushButtonMax->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
  pushButtonMax->setToolTip("Maximizar");

  icon = pushButtonMin->style()->standardIcon(QStyle::SP_TitleBarMinButton, 0,pushButtonMin);
  pushButtonMin->setIcon(icon);
  pushButtonMin->setIconSize(QSize(10,10));
  pushButtonMin->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
  pushButtonMin->setToolTip("Ocultar. Volver a mostrar desde Ventanas");

  icon = pushButtonClose->style()->standardIcon(QStyle::SP_TitleBarCloseButton, 0,pushButtonClose);
  pushButtonClose->setIcon(icon);
  pushButtonClose->setIconSize(QSize(10,10));
  pushButtonClose->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
  pushButtonMax->setToolTip("Cerrar");

  setTitleBarWidget(barNew);

  ///ahora preparo los conectores lambda para reaccionar
  ///

  connect(pushButtonMax,(&QPushButton::clicked),[=](bool checked){

      if (!isFloating())
         setFloating(true); ///la tengo que poner flotante para poder maximizarla.

        setGeometry(x(),y(),width_+8,height_+50);


  });
  connect(pushButtonMin,(&QPushButton::clicked),[=](bool checked){

     close();
  });

  connect(pushButtonClose,(&QPushButton::clicked),[=](bool checked){

      parent_->deleteImage(title_,true);
      deleteLater();


  });


}
Image::Punto::Punto():
  countGreen_(0),
  countRed_(0),
  countBlue_(0),
  countGray_(0),
  probabilidadBlue_(0),
  probabilidadGray_(0),
  probabilidadGreen_(0),
  probabilidadRed_(0)
{

}

Image::Punto::~Punto()
{

}

