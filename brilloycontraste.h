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

private:
  Ui::BrilloYContraste *ui;
  Image * imagen_;

  float brillo_,contraste_;
};

#endif // BRILLOYCONTRASTE_H
