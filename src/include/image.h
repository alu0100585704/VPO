﻿#ifndef IMAGE_H
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
#include <qmessagebox.h>
#include <QMouseEvent>
#include <events.h>
#include <QSpacerItem>
#include <Qmap>

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


  double countRed_;
  double countGreen_;
  double countBlue_;
  double countGray_;
  double probabilidadGray_,probabilidadGreen_,probabilidadBlue_,probabilidadRed_;

};

 class Tramo
{
 public:
    Tramo();
    ~Tramo();

   double xI_,yI_;
   double xF_,yF_;

};
  void newTramos(); ///inicializa el vector de Tramos, para comenzar a agregar nuevos, o  sea, borra los viejos.
  bool appendTramo(double xI, double yI, double xF, double yF);
  int functionRect(int numeroTramo, int x);
  void funcionGamma(double value);
  void brilloYContrasteGris(double brilloNuevoGris, double contrasteNuevoGris);
  void brilloYContrasteColor(double brilloNuevoRed, double contrasteNuevoRed,double brilloNuevoGreen, double contrasteNuevoGreen,double brilloNuevoBlue, double contrasteNuevoBlue);
  void toGray(bool ntsc,bool ochobits);
  void toEcualizer();
  void toEspejoVertical();
  void toEspejoHorizontal();
  void toRotate90Left();
  void toRotate90Right();
  void toTransposed();
  void toHistogramaEspecificado(Image * targetHistograma);
  bool toMapChange(Image * imagen);
  bool toDifference(Image *imagen);
  bool toLinealTransform();
  QChartView * toHistograma(bool acumulativo);   ///true si quiero el acumulativo o false si quiero el absoluto  

  QImage *getImage();
  void setImage(QImage *imagen); ///no la copia y coge posesión del la imagen pasada como argumeto
  void setImage(QImage &imagen); ///copia la imagen.
  void updateImage();


   Events * filterEvents_;
   QVector<Tramo> tramos_;
   QLabel * label_;
   QChartView * barGraphics_;
   QImage * image_;
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
   QImage::Format format_;
   int width_,height_;  //medida de la imagen
   MainWindow * parent_;
   double entropia_;

   double brillo_gray_;  ///media del histograma
   double contraste_gray_; ///desviación típica del histograma

   double brillo_green_;  ///media del histograma
   double contraste_green_; ///desviación típica del histograma

   double brillo_blue_;  ///media del histograma
   double contraste_blue_; ///desviación típica del histograma

   double brillo_red_;  ///media del histograma
   double contraste_red_; ///desviación típica del histograma

   int pixelsGrayTo0, pixelsGrayTo255;
   int pixelsRedTo0, pixelsRedTo255;
   int pixelsGreenTo0, pixelsGreenTo255;
   int pixelsBlueTo0, pixelsBlueTo255;

   int redValueMax_,redValueMin_,greenValueMax_,greenValueMin_,blueValueMax_,blueValueMin_,grayValueMax_,grayValueMin_; ///almacena los valores máximos y mínimos de cada color Se averigua durante la creación del histograma.
   ///atributos que indican tono de color con más pixeles y tono de color con menos pixeles en cada banda.
   unsigned int toneGrayWidthMorePixels_,toneGrayWidthLessPixels_,toneRedWidthMorePixels_,toneRedWidthLessPixels_,toneGreenWidthMorePixels_,toneGreenWidthLessPixels_,toneBlueWidthMorePixels_,toneBlueWidthLessPixels_;

private:
  bool lutGray8bitsPrepare();
  bool prepare();
  void calcular_histograma();
  void calcular_histograma_acumulado();
  void calcular_brillo();
  void calcular_contraste();
  void calcular_probabilidad_absoluto();
  void calcular_probabilidad_acumulativo();
  void calcular_entropia();
  void indicarCambios(int value, QImage *original, QImage *diferencia);
  void setButtonTitleBar();

};

#endif // IMAGE_H

