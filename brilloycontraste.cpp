#include "brilloycontraste.h"
#include "ui_brilloycontraste.h"

BrilloYContraste::BrilloYContraste(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::BrilloYContraste),
  realTime_(false),
  keepOriginal_(true),
  imageForKeepOriginal_(nullptr)
{
  ui->setupUi(this);

}

BrilloYContraste::~BrilloYContraste()
{
  delete ui;

  if (imageForKeepOriginal_!=nullptr)
    delete imageForKeepOriginal_;
}

void BrilloYContraste::setImage(Image *imagen)
{
  imagen_ = imagen;

  if (imagen_->isGray_)
    {
      brillo_ = imagen_->brillo_gray_;
      contraste_ = imagen_->contraste_gray_;
      ui->checkBoxKeepOriginal->setText(QString("Respecto a imagen original: Brillo %1 | Contraste %2").arg(brillo_).arg(contraste_));

      ui->labelBrillo->setText(QString("Brillo Actual: %1").arg(QString::number(brillo_)));
      ui->labelContraste->setText(QString("Contraste Actual: %1").arg(QString::number(contraste_)));

      ui->sliderBrilloGris->setValue(brillo_);
      ui->sliderContrasteGris->setValue(contraste_);
      ui->lineEditBrilloGris->setText(QString::number(brillo_));
      ui->lineEditContrasteGris->setText(QString::number(contraste_));

      imageForKeepOriginal_=imagen_->getImage();  ///esta se usará para mantener la relación siempre con la imagen original.
                      ///ya que si siempre modificamos la misma, se va degradando hasta desaparecer practicamente.

    }
}

void BrilloYContraste::on_lineEditBrilloGris_textChanged(const QString &arg1)
{

  if (realTime_)
        on_pushButtonApply_clicked();

  on_sliderBrilloGris_valueChanged(arg1.toInt());

}

void BrilloYContraste::on_lineEditContrasteGris_textChanged(const QString &arg1)
{  
  if (realTime_)
    on_pushButtonApply_clicked();

  on_sliderContrasteGris_valueChanged(arg1.toInt());
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


void BrilloYContraste::on_pushButtonApply_clicked()
{

if (keepOriginal_)
  imagen_->setImage(*imageForKeepOriginal_);

  brillo_ = ui->lineEditBrilloGris->text().toFloat();
  contraste_= ui->lineEditContrasteGris->text().toFloat();


  imagen_->brilloYContraste(brillo_,contraste_);
  ui->pixelsLost->setText(QString("Pixels Ajustados a Rango: %1").arg(imagen_->pixels_out_of_range_));

  contraste_=imagen_->contraste_gray_;
  brillo_=imagen_->brillo_gray_;

  ui->labelBrillo->setText(QString("Brillo Actual: %1").arg(QString::number(brillo_)));
  ui->labelContraste->setText(QString("Contraste Actual: %1").arg(QString::number(contraste_)));



}

void BrilloYContraste::on_checkBoxRealTime_stateChanged(int arg1)
{
  if (arg1==Qt::CheckState::Checked)
    realTime_=true;
  else
    realTime_=false;
}

void BrilloYContraste::on_checkBoxKeepOriginal_stateChanged(int arg1)
{
  if (arg1==Qt::CheckState::Checked)
    keepOriginal_=true;
  else
    keepOriginal_=false;

}
