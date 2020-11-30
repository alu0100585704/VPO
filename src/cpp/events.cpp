﻿#include "events.h"
#include <image.h>
#include <mainwindow.h>
Events::Events(Image * parent) :
  QObject(),
  parent_(parent),
  buttonPressed_(false),
  painter_(new QPainter()),
  original_(nullptr)
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
          xF_ = x;
          yF_ = y;

         if   ((abs(xF_-xI_) > 10) || (abs(yF_-yI_)>10)) ///solo en caso de que haya recortado un pedazo minimo
           {

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

      xI_ = mouseEvent->x();
      yI_ = mouseEvent->y();
      buttonPressed_ = true; ///indico que tengo el botón presionado para si se quiere recortar imagen.
      original_ = parent_->getImage(); ///guardo la imagen original

      qDebug() << xI_ << " " << yI_ <<" " << "boton presionado";
      return true;
    }
  else if (event->type() == QMouseEvent::MouseButtonRelease) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

        xF_ =  mouseEvent->x();
        yF_ = mouseEvent->y();
        buttonPressed_ = false; ///indico que tengo el botón presionado para si se quiere recortar imagen.

        parent_->setImage(*original_);
        parent_->updateImage();



  qDebug() << xI_ << " " << yI_ << "boton liberado" << xF_ << " " << yF_;
        if (painter_->isActive())
          painter_->end();

        ///creo imagen nueva solo de la regíon seleccionada
        Image * roiImage;
        roiImage = new Image(QString("ROI de: %1").arg(parent_->title_),&parent_->image_->copy(xI_,yI_,xF_,yF_) ,parent_->parent_); ///padre es mainwindow
        parent_->parent_->images_.insert(QString("ROI de: %1").arg(parent_->title_),roiImage);

        return true;
      }
  else {

      return QObject::eventFilter(watched, event);
    }
}
