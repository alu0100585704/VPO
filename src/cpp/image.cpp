#include <image.h>

Image::Image(const QString image) :
    dock_(nullptr),
    label_(nullptr),
    image_(nullptr),
    pixmapImage_(nullptr)
{

    dock_ = new QDockWidget(image);
    label_ = new QLabel();
    image_ = new QImage(image);

    if (image_->isNull())
    {
        label_->setText("Formato no admitido o ilegible");
     }
    else {

        dock_->setContextMenuPolicy(Qt::DefaultContextMenu);
        dock_->setFloating(false);
        dock_->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dock_->setAllowedAreas(Qt::DockWidgetArea::TopDockWidgetArea);

        pixmapImage_ = new QPixmap(image);


        //label_->setPixmap(pixmapImage_->fromImage(*image_).scaled(label_->width(),label_->height(),Qt::KeepAspectRatio));
        label_->setPixmap(pixmapImage_->fromImage(*image_));
        dock_->setMaximumSize(label_->width(),label_->height());



    }

dock_->setWidget(label_);
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

    if (dock_ != nullptr)
        delete dock_;

    qDebug() << "Destructor Image";

}
