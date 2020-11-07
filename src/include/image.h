#ifndef IMAGE_H
#define IMAGE_H

#include <qdockwidget.h>
#include <qlabel.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmainwindow.h>
#include <QUrl>
#include <QDebug>

class Image : public QMainWindow
{
public:
    Image(QString image);
    ~Image();


   QDockWidget * dock_;
   QLabel * label_;
   QImage * image_;
   QPixmap * pixmapImage_;

};

#endif // IMAGE_H
