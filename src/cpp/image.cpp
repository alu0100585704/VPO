#include <image.h>

Image::Image(const QString image) :
    dock_(nullptr),
    label_(nullptr),
    image_(nullptr),
    pixmapImage_(nullptr)
{

    image_ = new QImage(image);
    if (image_->isNull())
    {
        label_->setText("Formato no admitido o ilegible");
     }
    else {

        dock_ = new QDockWidget(image);
        label_ = new QLabel();
        dock_->setWidget(label_);

        pixmapImage_ = new QPixmap(image);


        label_->setPixmap(pixmapImage_->fromImage(*image_));
    }


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
