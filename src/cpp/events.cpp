#include "events.h"
#include <image.h>
#include <mainwindow.h>
Events::Events(Image * parent) :
  QObject(),
  parent_(parent),
  buttonPressed_(false),
  painter_(new QPainter()),
  original_(nullptr),
  roiSelected_(false)
{


}

Events::~Events()
{
  if (original_ != nullptr)
      delete original_;

  delete painter_;
}

bool Events::eventFilter(QObject *watched, QEvent *event)
{
  if (event->type() == QMouseEvent::MouseMove) {
      QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
      qDebug() << mouseEvent->x() << "," << mouseEvent->y();
      int x,y;

      x= mouseEvent->x();
      y= mouseEvent->y();

      if (parent_->isGray_)
        if (parent_->format_ == QImage::Format_Indexed8)
          parent_->parent_->information_.setText(QString("%1 (x=%2,y=%3) | Imagen Gris 8 bits: %4 ").arg(parent_->title_).arg(x).arg(y).arg(qRed(parent_->image_->pixel(x,y))));
          else
          parent_->parent_->information_.setText(QString("%1 (x=%2,y=%3) | Imagen RGB Gris: R: %4, G: %5, B: %6 ").arg(parent_->title_).arg(x).arg(y).arg(qRed(parent_->image_->pixel(x,y))).arg(qGreen(parent_->image_->pixel(x,y))).arg(qBlue(parent_->image_->pixel(x,y))));
      else
        parent_->parent_->information_.setText(QString("%1 (x=%2,y=%3) | Imagen RGB Color R: %4, G: %5, B: %6 ").arg(parent_->title_).arg(x).arg(y).arg(qRed(parent_->image_->pixel(x,y))).arg(qGreen(parent_->image_->pixel(x,y))).arg(qBlue(parent_->image_->pixel(x,y))));

      if (buttonPressed_)
        {
          xF_ = x-xI_;
          yF_ = y-yI_; ///el rectángulo funciona en base a su ancho y alto, no a las posiciones

       if ((xF_ > 0) && (yF_ >0) )  ///no entro si tengo algún valor negativo.
         if   ((xF_ > 10) || (yF_>10) || (roiSelected_)) ///solo en caso de que haya recortado un pedazo minimo, o ya se haya comenzado el recorte
           {
            if (!roiSelected_)
                      original_ = parent_->getImage(); ///guardo la imagen original

             roiSelected_=true;
             parent_->setImage(*original_);

             if (!painter_->isActive())
               painter_->begin(parent_->image_);///como device pongo a QImage. para pintar el rectángulo

             painter_->setPen(QColor::fromRgb(255,255,255));
             painter_->drawRect(xI_,yI_,xF_,yF_);
             painter_->end();

             parent_->updateImage();


           }



        }

    return true;

    } else if (event->type() == QMouseEvent::MouseButtonPress) {
      QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
      parent_->parent_->focus_ = parent_->title_;
      parent_->parent_->statusPermanentMessage_.setText(QString("| Imagen Seleccionada : %1  ").arg(parent_->title_));

      roiSelected_ = false;
      xI_ = mouseEvent->x();
      yI_ = mouseEvent->y();
      buttonPressed_ = true; ///indico que tengo el botón presionado para si se quiere recortar imagen.

      qDebug() << xI_ << " " << yI_ <<" " << "boton presionado";
      return true;
    }
  else if (event->type() == QMouseEvent::MouseButtonRelease) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

        buttonPressed_ = false; ///indico que tengo el botón presionado para si se quiere recortar imagen.

        if (roiSelected_)
          {

              roiSelected_ = false;
              parent_->setImage(*original_);
              parent_->updateImage();
              delete original_; ///borro la copia original.
              original_ = nullptr;

              if (painter_->isActive())
                painter_->end(); ///por si acaso esta activo el painter.

              if (QMessageBox::question(parent_,QString::fromUtf8("Región de interés Seleccionada"),QString::fromUtf8("¿Desea crear una imagen nueva a partir de la región seleccionada?"),QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No, QMessageBox::StandardButton::No)  == QMessageBox::StandardButton::Yes)
                    ///creo imagen nueva solo de la regíon seleccionada
                    ///
                    parent_->parent_->roiImage(xI_,yI_,xF_,yF_,parent_);
          }



  qDebug() << xI_ << " " << yI_ << "boton liberado" << xF_ << " " << yF_;

        return true;
      }
  else {

      return QObject::eventFilter(watched, event);
    }
}
