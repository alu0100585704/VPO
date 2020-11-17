#include "brilloycontraste.h"
#include "ui_brilloycontraste.h"

BrilloYContraste::BrilloYContraste(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::BrilloYContraste)
{
  ui->setupUi(this);
}

BrilloYContraste::~BrilloYContraste()
{
  delete ui;
}

void BrilloYContraste::setImage(Image *imagen)
{
  imagen_ = imagen;

  if (imagen_->isGray_)
    {
      brillo_ = imagen_->brillo_gray_;
      contraste_ = imagen_->contraste_gray_;

      ui->sliderBrilloGris->setValue(brillo_);
      ui->sliderContrasteGris->setValue(contraste_);
      ui->lineEditBrilloGris->setText(QString::number(brillo_));
      ui->lineEditContrasteGris->setText(QString::number(contraste_));

    }
}

void BrilloYContraste::on_lineEditBrilloGris_textChanged(const QString &arg1)
{
  brillo_= arg1.toFloat();
  imagen_->brilloYContraste(brillo_,contraste_);
  ui->pixelsLost->setText(QString("Pixels Ajustados a Rango: %1").arg(imagen_->pixels_out_of_range_));
}

void BrilloYContraste::on_lineEditContrasteGris_textChanged(const QString &arg1)
{
  contraste_= arg1.toFloat();
  imagen_->brilloYContraste(brillo_,contraste_);
  ui->pixelsLost->setText(QString("Pixels Ajustados a Rango: %1").arg(imagen_->pixels_out_of_range_));
}

void BrilloYContraste::on_sliderBrilloGris_valueChanged(int value)
{
  ui->lineEditBrilloGris->setText(QString::number(value));
}

void BrilloYContraste::on_sliderContrasteGris_valueChanged(int value)
{
ui->lineEditContrasteGris->setText(QString::number(value));
}

void BrilloYContraste::on_pushButtonClose_clicked()
{
    close();
}
