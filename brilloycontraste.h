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

private:
  Ui::BrilloYContraste *ui;
  Image * imagen_;
  QImage * imageForKeepOriginal_;

  float brillo_,contraste_;
  bool keepOriginal_; ///todo los cambios los realiza en relación al brillo y contraste original.
  bool realTime_; ///realiza los cambios directamente, sin necesidad de presionar aplicar
};

#endif // BRILLOYCONTRASTE_H
