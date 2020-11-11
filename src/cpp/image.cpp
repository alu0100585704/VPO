#include <image.h>
#include <mainwindow.h>
#include <QRgb>
#include <QColor>

Image::Image(const QString fileImage,MainWindow * parent) :
      QDockWidget(fileImage,parent),
  //aqui fileImage también es el titulo de la ventana
    nameFile_(fileImage),
    title_(fileImage),
    image_(new QImage(fileImage)),
    parent_(parent)
{
prepare();

}

Image::Image(QString title,QImage *image,MainWindow * parent):
      QDockWidget(title,parent),
      image_(image),
      title_(title),
      parent_(parent)
{

prepare();
}

bool Image::prepare()
{

  pixmapImage_ = nullptr;

  histograma_.resize(256);
  histograma_acumulado_.resize(256);

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

   /* QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());

    setSizePolicy(sizePolicy);*/

    scrollArea_->setWidgetResizable(false);

    if (image_->isNull())      
          label_->setText(QString("Formato no admitido o ilegible para el fichero %1").arg(nameFile_));

      else
          updateImage();

    width_=image_->width();
    height_=image_->height();

    setMinimumHeight(40);
    setMinimumWidth(40);
    setMaximumWidth(1024);
    setMaximumHeight(768);

      if (width_<1024)
          setMaximumWidth(width_+5);
      if (height_<768)
          setMaximumHeight(height_+25);


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

    qDebug() << "Destructor Image";

}

void Image::updateImage()
{
  *pixmapImage_ = pixmapImage_->fromImage(*image_);
  label_->setPixmap(*pixmapImage_);
  label_->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  label_->setGeometry(0,0,width_,height_);

  format_=image_->format();
  isGray_ = image_->isGrayscale();

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
  Punto punto;
 for (int i=0; i < image_->height();i++) //
   for (int j=0; i < image_->width();j++)
     {
       QRgb valor= image_->pixel(j,i);


     }
}

void Image::toGray8Bits(Image *source, Image *target, bool ntsc)
{
  if (ntsc)
    {
      //formato ntsc
      for (int i=0; i < source->height_;i++) //
        for (int j=0; j < source->width_;j++)
          {
            int gray = (qRed(source->image_->pixel(j,i)) * 0.299) + (qBlue(source->image_->pixel(j,i))*0.114) + (qGreen(source->image_->pixel(j,i))*0.587);
            target->image_->setPixel(j,i,gray);

          }

    }
  else {
///formato pal
      for (int i=0; i < source->height_;i++) //
        for (int j=0; j < source->width_;j++)
          {
            int gray = (qRed(source->image_->pixel(j,i)) * 0.222) + (qBlue(source->image_->pixel(j,i))*0.071) + (qGreen(source->image_->pixel(j,i))*0.707);
            target->image_->setPixel(j,i,gray);

          }

    }
  updateImage();
}


Image::Punto::Punto():
  green_(0),
  red_(0),
  blue_(0),
  grey_(0)
{

}

Image::Punto::~Punto()
{

}
