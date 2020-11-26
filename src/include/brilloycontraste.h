#ifndef BRILLOYCONTRASTE_H
#define BRILLOYCONTRASTE_H

#include <QDialog>
#include <image.h>
#include <math.h>

namespace Ui {
  class BrilloYContraste;
}

class BrilloYContraste : public QDialog
{
  Q_OBJECT

public:
  explicit BrilloYContraste(QWidget *parent = nullptr);
  ~BrilloYContraste();

  void setImage(Image * imagen);

private slots:
  void on_lineEditBrilloGris_textChanged(const QString &arg1);

  void on_lineEditContrasteGris_textChanged(const QString &arg1);

  void on_sliderBrilloGris_valueChanged(int value);

  void on_sliderContrasteGris_valueChanged(int value);

  void on_pushButtonClose_clicked();


  void on_pushButtonApply_clicked();

  void on_checkBoxRealTime_stateChanged(int arg1);

  void on_checkBoxKeepOriginal_stateChanged(int arg1);

  void on_lineEditBrilloRed_textChanged(const QString &arg1);

  void on_lineEditBrilloGreen_textChanged(const QString &arg1);

  void on_lineEditBrilloBlue_textChanged(const QString &arg1);

  void on_lineEditContrasteRed_textChanged(const QString &arg1);

  void on_lineEditContrasteGreen_textChanged(const QString &arg1);

  void on_lineEditContrasteBlue_textChanged(const QString &arg1);

  void on_sliderBrilloRed_valueChanged(int value);

  void on_sliderContrasteRed_valueChanged(int value);

  void on_sliderBrilloGreen_valueChanged(int value);

  void on_sliderContrasteGreen_valueChanged(int value);

  void on_sliderBrilloBlue_valueChanged(int value);

  void on_sliderContrasteBlue_valueChanged(int value);

private:
  Ui::BrilloYContraste *ui;
  Image * imagen_;
  QImage * imageForKeepOriginal_;

  double brillo_gray_;  ///media del histograma
  double contraste_gray_; ///desviación típica del histograma

  double brillo_green_;  ///media del histograma
  double contraste_green_; ///desviación típica del histograma

  double brillo_blue_;  ///media del histograma
  double contraste_blue_; ///desviación típica del histograma

  double brillo_red_;  ///media del histograma
  double contraste_red_; ///desviación típica del histograma

  bool keepOriginal_; ///todo los cambios los realiza en relación al brillo y contraste original.
  bool realTime_; ///realiza los cambios directamente, sin necesidad de presionar aplicar
};

#endif // BRILLOYCONTRASTE_H
