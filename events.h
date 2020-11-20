#ifndef EVENTS_H
#define EVENTS_H

#include <QObject>
//#include <image.h>
#include <QMouseEvent>
#include <QDebug>
#include <QtCharts/qchartview.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qvalueaxis.h>

QT_CHARTS_USE_NAMESPACE

class Image;

class Events : public QObject
{
  Q_OBJECT

public:

  Events(Image *parent);

  Image * parent_;
protected:
  bool eventFilter(QObject *watched, QEvent *event) override;

};

#endif // EVENTS_H
