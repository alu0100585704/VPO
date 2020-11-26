#include "events.h"
#include <image.h>
#include <mainwindow.h>
Events::Events(Image * parent) :
  QObject(),
  parent_(parent)
{

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

    return true;

    } else if (event->type() == QMouseEvent::MouseButtonPress) {
      QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
      parent_->parent_->focus_ = parent_->title_;
      parent_->parent_->statusPermanentMessage_.setText(QString("| Imagen Seleccionada : %1  ").arg(parent_->title_));
      return true;
    }
  else {

      return QObject::eventFilter(watched, event);
  }
}
