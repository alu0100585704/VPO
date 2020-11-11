#include <image.h>
#include <mainwindow.h>

QT_CHARTS_USE_NAMESPACE

Image::Image(const QString fileImage,MainWindow * parent) :
      QDockWidget(fileImage,parent),
  //aqui fileImage también es el titulo de la ventana
    nameFile_(fileImage),
    title_(fileImage),
    image_(new QImage(fileImage)),
    barGraphics_(nullptr),
    pixmapImage_(nullptr),
    isBarGraphics_(false),
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
  parent_(parent)
{
  scrollArea_=new QScrollArea(this);
  scrollAreaWidgetContents_=new QWidget(this);
  dockWidgetContents_=new QWidget(this);
  gridLayoutDockWidgetContentsAndScrollArea_ =new QGridLayout(dockWidgetContents_);
  gridLayoutScrollAreaWidgetContentsAndLabel_=new QGridLayout(scrollAreaWidgetContents_);


  ///Preparo Dock widget acoplado pero con posibilidad de ser flotante
  /// Lo hago dentro de un QLabel que a la vez está dentro de un QScroolArea
  /// y a la vez dentro de un DockWidget.

  setMinimumHeight(50);
  setMinimumWidth(50);
  setMaximumWidth(1024);
  setMaximumHeight(768);

  setGeometry(0,0,1024,768);
  //barGraphics_->setGeometry(0,0,500,500);


    setContextMenuPolicy(Qt::DefaultContextMenu);
    setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable  | QDockWidget::DockWidgetFloatable);
    setFloating(true);
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);


    setWidget(barGraphics_);


}

bool Image::prepare()
{

  label_=new QLabel(this);

  pixmapImage_= new QPixmap();
  scrollArea_=new QScrollArea(this);
  scrollAreaWidgetContents_=new QWidget(this);
  dockWidgetContents_=new QWidget(this);
  gridLayoutDockWidgetContentsAndScrollArea_ =new QGridLayout(dockWidgetContents_);
  gridLayoutScrollAreaWidgetContentsAndLabel_=new QGridLayout(scrollAreaWidgetContents_);


  ///Preparo Dock widget acoplado pero con posibilidad de ser flotante
  /// Lo hago dentro de un QLabel que a la vez está dentro de un QScroolArea
  /// y a la vez dentro de un DockWidget.

    setContextMenuPolicy(Qt::DefaultContextMenu);
    setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable  | QDockWidget::DockWidgetFloatable);
    setFloating(false);
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

   scrollArea_->setWidgetResizable(false);


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

}

void Image::updateImage()
{


  setMinimumHeight(50);
  setMinimumWidth(50);
  setMaximumWidth(1024);
  setMaximumHeight(768);

  width_=image_->width();
  height_=image_->height();


  if (width_ <1024)
      setMaximumWidth(width_);

  if (height_<768)
      setMaximumHeight(height_);


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

  ///preparo la Look UP Table para gris
  lutGray8bitsPrepare();

  calcular_histograma();
  calcular_histograma_acumulado();

  qDebug() << image_->format()<< "Es gris : "<< isGray_ << "valor primer pixel "<< qRed(image_->pixel(0,0)) << ", " << qGreen(image_->pixel(0,0)) << "," << qBlue(image_->pixel(0,0));


}
void Image::focusInEvent(QFocusEvent *event)
{
  parent_->focus_=nameFile_;
  qDebug() << QString("Foco asignado a %1").arg(nameFile_);
  event->accept();

}


void Image::calcular_histograma()
{

  histograma_.clear();
  histograma_.resize(256);


 for (int i=0; i < image_->height();i++)
   for (int j=0; j < image_->width();j++)
     {
        unsigned int valor = qRed(image_->pixel(j,i));

        if (isGray_)
            histograma_[valor].countGray_ = histograma_[valor].countGray_ + 1;
        else {
            ///entonces tengo que actualizar los tres colores
            histograma_[valor].countRed_ = histograma_[valor].countRed_ + 1;
            valor = qGreen(image_->pixel(j,i));
            histograma_[valor].countGreen_ = histograma_[valor].countGreen_ + 1;
            valor = qBlue(image_->pixel(j,i));
            histograma_[valor].countBlue_ = histograma_[valor].countBlue_ + 1;
          }

     }
}

void Image::calcular_histograma_acumulado()
{
  histograma_acumulado_.clear();
  histograma_acumulado_.resize(256);

  histograma_acumulado_[0] = histograma_[0]; ///el primer valor del acumulado
  ///es igual al del absoluto
  ///
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

bool Image::lutGray8bitsPrepare()
{

  lutGray8bits_.clear();
  lutGray8bits_.resize(256);

 for (int i=0; i < 255;i++)
    lutGray8bits_[i] = qRgb(i,i,i);

return  true;
}

///
/// \brief Image::toGray8Bits
/// \param source
/// \param target
/// \param ntsc
/// \return
///Debuelve un QImage con la imagen en formato 256 colores,8 bits y escala de grises
/// El receptor será el encargado crear su delete
///
QImage * Image::toGray8Bits(bool ntsc)
{

  ///
  QImage * ochobits =new QImage(width_,height_, QImage::Format_Indexed8);
  ///
  ///Asigno la LUT de grises a la imagen nueva
  ochobits->setColorTable(lutGray8bits_);

  if (ntsc)
    {
      //formato ntsc
      for (int i=0; i < height_;i++) //
        for (int j=0; j < width_;j++)
          {
            int gray = (qRed(image_->pixel(j,i)) * 0.299) + (qBlue(image_->pixel(j,i))*0.114) + (qGreen(image_->pixel(j,i))*0.587);
            ochobits->setPixel(j,i,gray);

          }

    }
  else {
///formato pal
      for (int i=0; i < height_;i++) //
        for (int j=0; j < width_;j++)
          {
            int gray = (qRed(image_->pixel(j,i)) * 0.222) + (qBlue(image_->pixel(j,i))*0.071) + (qGreen(image_->pixel(j,i))*0.707);
            ochobits->setPixel(j,i,gray);

          }

    }  
  return ochobits;
}

QChartView *Image::toHistograma()
{
  QLineSeries *linesGray = new QLineSeries();

  linesGray->setName("Tono de Gris");

  for (int i=0; i < 256; i++)
  {
    if (isGray_)
      linesGray->append(i,histograma_[i].countGray_);
  }

  QChart * chart = new QChart();
    if (isGray_)
       chart->addSeries(linesGray);

  chart->setTitle("Histograma Absoluto");

  QValueAxis * axisX =new QValueAxis();
  QValueAxis * axisY =new QValueAxis();

  axisX->setRange(0,255);
  axisX->setTickCount(7);

  axisY->setRange(0,width_*height_); ///ancho por alto es el máximo numero de pixeles que se podrán tener
  axisY->setTickCount(20);
  axisY->setTitleText("Cantidad de Pixels");
  chart->addAxis(axisX,Qt::AlignBottom);
  chart->addAxis(axisY, Qt::AlignLeft);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  QChartView * chartview = new QChartView(chart);
  chartview->setRenderHint(QPainter::Antialiasing);

  return chartview;

}

QChartView *Image::toHistogramaAcumulativo()
{
  QLineSeries *linesGray = new QLineSeries();

  linesGray->setName("Tono de Gris");

  for (int i=0; i < 256; i++)
  {
    if (isGray_)
      linesGray->append(i,histograma_acumulado_[i].countGray_);
  }

  QChart * chart = new QChart();
    if (isGray_)
       chart->addSeries(linesGray);

  chart->setTitle("Histograma Acumulativo");

  QValueAxis * axisX =new QValueAxis();
  QValueAxis * axisY =new QValueAxis();

  axisX->setRange(0,255);
  axisX->setTickCount(7);

  axisY->setRange(0,width_*height_); ///ancho por alto es el máximo numero de pixeles que se podrán tener
  axisY->setTickCount(20);
  axisY->setTitleText("Cantidad de Pixels");
  chart->addAxis(axisX,Qt::AlignBottom);
  chart->addAxis(axisY, Qt::AlignLeft);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  QChartView * chartview = new QChartView(chart);
  chartview->setRenderHint(QPainter::Antialiasing);

  return chartview;
}


Image::Punto::Punto():
  countGreen_(0),
  countRed_(0),
  countBlue_(0),
  countGray_(0)
{

}

Image::Punto::~Punto()
{

}
