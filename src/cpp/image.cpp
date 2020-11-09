#include <image.h>

Image::Image(const QString image,QWidget * parent) :
    QDockWidget(image,parent),
    //dock_(nullptr),
    label_(nullptr),
    image_(nullptr),
    pixmapImage_(nullptr),
    histograma_(256),
    histograma_acumulado_(256),
    gray_(false)
{
    nameFile_=image;
    //dock_ = new QDockWidget(image);
    label_ = new QLabel(this);
    image_ = new QImage(image);

    if (image_->isNull())
    {
        label_->setText(QString("Formato no admitido o ilegible para el fichero %1").arg(nameFile_));
     }
    else {

        setContextMenuPolicy(Qt::DefaultContextMenu);
        setFloating(false);
        setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable  | QDockWidget::DockWidgetFloatable);

        //dock_->setAllowedAreas(Qt::DockWidgetArea::TopDockWidgetArea);

        pixmapImage_ = new QPixmap(image);


        //label_->setPixmap(pixmapImage_->fromImage(*image_).scaled(label_->width(),label_->height(),Qt::KeepAspectRatio));
        label_->setPixmap(pixmapImage_->fromImage(*image_));
     //   dock_->setMaximumSize(label_->width(),label_->height());
        gray_ = image_->isGrayscale();

      setFocusPolicy(Qt::FocusPolicy::WheelFocus);


    }

    setWidget(label_);

}

Image::~Image()
{



    qDebug() << "Destruyendo Image pixmapimage";
  if (pixmapImage_!= nullptr)
      delete pixmapImage_;

  qDebug() << "Destruyendo Image image_";

  if (image_ != nullptr)
    delete image_;

  qDebug() << "Destruyendo Image label";
   if (label_!= nullptr )
     delete label_;

    qDebug() << "Destruyendo Image Dock";

    //if (dock_ != nullptr)
     //   delete dock_;

    qDebug() << "Destructor Image";

}

void Image::focusInEvent(QFocusEvent *event)
{
    qDebug() << QString("Foco asignado a %1").arg(nameFile_);

}

