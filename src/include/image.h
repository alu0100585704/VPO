#ifndef IMAGE_H
#define IMAGE_H

#include <qdockwidget.h>
#include <qlabel.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmainwindow.h>
#include <QUrl>
#include <QVector>
#include <QDebug>
#include <QMap>

class MainWindow;

class Image : public QDockWidget
{
    Q_OBJECT
public:
    explicit Image(QString image, QWidget *parent = nullptr);
    ~Image();

virtual void  focusInEvent(QFocusEvent * event);

   //QDockWidget * dock_;
   QLabel * label_;
   QImage * image_;
   QPixmap * pixmapImage_;
   bool gray_;
   QVector<int> histograma_;
   QVector<int> histograma_acumulado_;
   QMap<int,int> lut_;
   QString nameFile_;
};

#endif // IMAGE_H
