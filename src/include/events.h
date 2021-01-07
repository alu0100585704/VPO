#ifndef EVENTS_H
#define EVENTS_H

#include <QObject>

#include <QMouseEvent>
#include <QDebug>
#include <QtCharts/qchartview.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qvalueaxis.h>
#include <qpainter.h>
#include <qmessagebox.h>

QT_CHARTS_USE_NAMESPACE

class Image;

class Events : public QObject
{
  Q_OBJECT

public:

  Events(Image *parent);
    ~Events();

  Image * parent_;
protected:
  bool eventFilter(QObject *watched, QEvent *event) override;
  int xI_,yI_,xF_,yF_;
  bool buttonPressed_, roiSelected_;
  QPainter * painter_;
  QImage * original_;  ///para cuando se pinta un rectángulo de selección, no se modifique la imagen original
};

#endif // EVENTS_H
