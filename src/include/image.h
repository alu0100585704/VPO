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
#include <QScrollArea>
#include <QWidget>
#include <QGridLayout>
#include <QtCharts/qchartview.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qvalueaxis.h>
#include <QRgb>
#include <QColor>
#include <math.h>


QT_CHARTS_USE_NAMESPACE

class MainWindow;

class Image : public QDockWidget
{
    Q_OBJECT
public:
    explicit Image(const QString fileImage, MainWindow *parent = nullptr);
    Image(QString title, QImage * image, MainWindow *parent= nullptr);
    Image(QString title, QChartView * image, MainWindow *parent= nullptr);
  ~Image();


 class Punto
{
  public:
   Punto();
  ~Punto();


  unsigned int countRed_;
  unsigned int countGreen_;
  unsigned int countBlue_;
  unsigned int countGray_;
  float probabilidadGray_,probabilidadGreen_,probabilidadBlue_,probabilidadRed_;

};

  virtual void  focusInEvent(QFocusEvent * event);
  bool lutGray8bitsPrepare();
  bool prepare();
  void updateImage();
  void calcular_histograma();
  void calcular_histograma_acumulado();  
  void calcular_brillo();
  void calcular_contraste();
  void calcular_probabilidad_absoluto();
  void calcular_probabilidad_acumulativo();

  QImage * toGray8Bits(bool ntsc);
  QChartView * toHistograma();
  QChartView * toHistogramaAcumulativo();



   QLabel * label_;
   QChartView * barGraphics_;
   QImage * image_,imageGray8bits_;
   QPixmap * pixmapImage_;
   QScrollArea * scrollArea_;
   QWidget * dockWidgetContents_;
   QWidget * scrollAreaWidgetContents_;
   QGridLayout * gridLayoutDockWidgetContentsAndScrollArea_;
   QGridLayout * gridLayoutScrollAreaWidgetContentsAndLabel_;
   bool isGray_;
   bool isBarGraphics_;

   QVector<QRgb>  lutGray8bits_;
   QVector<Punto> histograma_;
   QVector<Punto> histograma_acumulado_;
   QString nameFile_;
   QString title_;
   int format_;
   int width_,height_;  //medida de la imagen
   MainWindow * parent_;

   float brillo_gray_;  ///media del histograma
   float contraste_gray_; ///desviaci�n t�pica del histograma

   float brillo_green_;  ///media del histograma
   float contraste_green_; ///desviaci�n t�pica del histograma

   float brillo_blue_;  ///media del histograma
   float contraste_blue_; ///desviaci�n t�pica del histograma

   float brillo_red_;  ///media del histograma
   float contraste_red_; ///desviaci�n t�pica del histograma


};

#endif // IMAGE_H

