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
  imageForKeepOriginal_=imagen_->getImage();  ///esta se usará para mantener la relación siempre con la imagen original.
                  ///ya que si siempre modificamos la misma, se va degradando hasta desaparecer practicamente.
  ui->checkBoxKeepOriginal->setChecked(true);

if (imagen_->isGray_)
  {
    brillo_gray_ = imagen_->brillo_gray_;
    contraste_gray_ = imagen_->contraste_gray_;
    ui->labelBrilloOriginal->setText(QString("Brillo Gris Original: %1").arg(brillo_gray_));
    ui->labelContrasteOriginal->setText(QString("Contraste Gris Original: %1").arg(contraste_gray_));
    ui->lineEditBrilloGris->setText(QString::number(brillo_gray_));
    ui->lineEditContrasteGris->setText(QString::number(contraste_gray_));

    ui->lineEditBrilloBlue->setDisabled(true);
    ui->lineEditBrilloGreen->setDisabled(true);
    ui->lineEditBrilloRed->setDisabled(true);
    ui->lineEditContrasteBlue->setDisabled(true);
    ui->lineEditContrasteGreen->setDisabled(true);
    ui->lineEditContrasteRed->setDisabled(true);
    ui->sliderBrilloBlue->setDisabled(true);
    ui->sliderBrilloGreen->setDisabled(true);
    ui->sliderBrilloRed->setDisabled(true);
    ui->sliderContrasteBlue->setDisabled(true);
    ui->sliderContrasteGreen->setDisabled(true);
    ui->sliderContrasteRed->setDisabled(true);
    ui->progressBarBlueTo0->setDisabled(true);
    ui->progressBarBlueTo255->setDisabled(true);
    ui->progressBarGreenTo0->setDisabled(true);
    ui->progressBarGreenTo255->setDisabled(true);
    ui->progressBarRedTo0->setDisabled(true);
    ui->progressBarRedTo255->setDisabled(true);

  }

else {

    brillo_red_ = imagen_->brillo_red_;
    contraste_red_ = imagen_->contraste_red_;

    brillo_blue_=imagen_->brillo_blue_;
    contraste_blue_=imagen_->contraste_blue_;

    brillo_green_=imagen_->brillo_green_;
    contraste_green_=imagen_->contraste_green_;

    ui->labelBrilloOriginal->setText(QString("Brillo Original R: %1 G: %2 B: %3 ").arg(brillo_red_).arg(brillo_green_).arg(brillo_blue_));
    ui->labelContrasteOriginal->setText(QString("Contraste  Original R: %1 G: %2 B: %3 ").arg(contraste_red_).arg(contraste_green_).arg(contraste_blue_));

    ui->lineEditBrilloRed->setText(QString::number(brillo_red_));
    ui->lineEditContrasteRed->setText(QString::number(contraste_red_));

    ui->lineEditBrilloGreen->setText(QString::number(brillo_green_));
    ui->lineEditContrasteGreen->setText(QString::number(contraste_green_));

    ui->lineEditBrilloBlue->setText(QString::number(brillo_blue_));
    ui->lineEditContrasteBlue->setText(QString::number(contraste_blue_));

    ui->lineEditBrilloGris->setDisabled(true);
    ui->lineEditContrasteGris->setDisabled(true);
    ui->sliderBrilloGris->setDisabled(true);
    ui->sliderContrasteGris->setDisabled(true);
    ui->progressBarGrayTo0->setDisabled(true);
    ui->progressBarGrayTo255->setDisabled(true);
  }
  on_pushButtonApply_clicked();
}

void BrilloYContraste::on_lineEditBrilloGris_textChanged(const QString &arg1)
{

  if (realTime_)
        on_pushButtonApply_clicked();

  on_sliderBrilloGris_valueChanged(arg1.toInt());

}

void BrilloYContraste::on_lineEditBrilloRed_textChanged(const QString &arg1)
{
  if (realTime_)
        on_pushButtonApply_clicked();

  on_sliderBrilloRed_valueChanged(arg1.toInt());

}

void BrilloYContraste::on_lineEditBrilloGreen_textChanged(const QString &arg1)
{
  if (realTime_)
        on_pushButtonApply_clicked();

  on_sliderBrilloGreen_valueChanged(arg1.toInt());

}

void BrilloYContraste::on_lineEditBrilloBlue_textChanged(const QString &arg1)
{
  if (realTime_)
        on_pushButtonApply_clicked();

  on_sliderBrilloBlue_valueChanged(arg1.toInt());

}


void BrilloYContraste::on_lineEditContrasteGris_textChanged(const QString &arg1)
{  
  if (realTime_)
    on_pushButtonApply_clicked();

  on_sliderContrasteGris_valueChanged(arg1.toInt());
}

void BrilloYContraste::on_lineEditContrasteRed_textChanged(const QString &arg1)
{
  if (realTime_)
    on_pushButtonApply_clicked();

  on_sliderContrasteRed_valueChanged(arg1.toInt());

}

void BrilloYContraste::on_lineEditContrasteGreen_textChanged(const QString &arg1)
{
  if (realTime_)
    on_pushButtonApply_clicked();

  on_sliderContrasteGreen_valueChanged(arg1.toInt());

}

void BrilloYContraste::on_lineEditContrasteBlue_textChanged(const QString &arg1)
{
  if (realTime_)
    on_pushButtonApply_clicked();

  on_sliderContrasteBlue_valueChanged(arg1.toInt());

}


void BrilloYContraste::on_sliderBrilloGris_valueChanged(int value)
{
  ui->sliderBrilloGris->setValue(value);
  ui->lineEditBrilloGris->setText(QString::number(value));

}

void BrilloYContraste::on_sliderBrilloRed_valueChanged(int value)
{
  ui->sliderBrilloRed->setValue(value);
      ui->lineEditBrilloRed->setText(QString::number(value));
}

void BrilloYContraste::on_sliderBrilloGreen_valueChanged(int value)
{
  ui->sliderBrilloGreen->setValue(value);
      ui->lineEditBrilloGreen->setText(QString::number(value));
}


void BrilloYContraste::on_sliderBrilloBlue_valueChanged(int value)
{
  ui->sliderBrilloBlue->setValue(value);
      ui->lineEditBrilloBlue->setText(QString::number(value));
}

void BrilloYContraste::on_sliderContrasteGris_valueChanged(int value)
{
  ui->sliderContrasteGris->setValue(value);
  ui->lineEditContrasteGris->setText(QString::number(value));

}
void BrilloYContraste::on_sliderContrasteRed_valueChanged(int value)
{
  ui->sliderContrasteRed->setValue(value);
  ui->lineEditContrasteRed->setText(QString::number(value));
}
void BrilloYContraste::on_sliderContrasteGreen_valueChanged(int value)
{
  ui->sliderContrasteGreen->setValue(value);
      ui->lineEditContrasteGreen->setText(QString::number(value));
}

void BrilloYContraste::on_sliderContrasteBlue_valueChanged(int value)
{
  ui->sliderContrasteBlue->setValue(value);
      ui->lineEditContrasteBlue->setText(QString::number(value));
}


void BrilloYContraste::on_pushButtonClose_clicked()
{
    close();
}


void BrilloYContraste::on_pushButtonApply_clicked()
{

if (keepOriginal_)
  imagen_->setImage(*imageForKeepOriginal_);

if (imagen_->isGray_)
  {
    brillo_gray_ = ui->lineEditBrilloGris->text().toDouble();
    contraste_gray_= ui->lineEditContrasteGris->text().toDouble();


    imagen_->brilloYContrasteGris(brillo_gray_,contraste_gray_);

    contraste_gray_=imagen_->contraste_gray_;
    brillo_gray_=imagen_->brillo_gray_;

    ui->progressBarGrayTo0->setValue(imagen_->pixelsGrayTo0);
    ui->progressBarGrayTo255->setValue(imagen_->pixelsGrayTo255);


    ui->labelBrillo->setText(QString("Brillo Actual Gris: %1").arg(QString::number(brillo_gray_)));
    ui->labelContraste->setText(QString("Contraste Actual Gris: %1").arg(QString::number(contraste_gray_)));


  }

else {

    brillo_red_ = ui->lineEditBrilloRed->text().toDouble();
    contraste_red_= ui->lineEditContrasteRed->text().toDouble();


    brillo_green_ = ui->lineEditBrilloGreen->text().toDouble();
    contraste_green_= ui->lineEditContrasteGreen->text().toDouble();

    brillo_blue_ = ui->lineEditBrilloBlue->text().toDouble();
    contraste_blue_= ui->lineEditContrasteBlue->text().toDouble();

    imagen_->brilloYContrasteColor(brillo_red_,contraste_red_,brillo_green_,contraste_green_,brillo_blue_,contraste_blue_);

    contraste_red_=imagen_->contraste_red_;
    brillo_red_=imagen_->brillo_red_;

    contraste_green_=imagen_->contraste_green_;
    brillo_green_=imagen_->brillo_green_;

    contraste_blue_=imagen_->contraste_blue_;
    brillo_blue_=imagen_->brillo_blue_;

    ui->progressBarRedTo0->setValue(imagen_->pixelsRedTo0);
    ui->progressBarRedTo255->setValue(imagen_->pixelsRedTo255);

    ui->progressBarGreenTo0->setValue(imagen_->pixelsGreenTo0);
    ui->progressBarGreenTo255->setValue(imagen_->pixelsGreenTo255);

    ui->progressBarBlueTo0->setValue(imagen_->pixelsBlueTo0);
    ui->progressBarBlueTo255->setValue(imagen_->pixelsBlueTo255);


    ui->labelBrillo->setText(QString("Brillo Actual R: %1 G: %2 B: %3 ").arg(brillo_red_).arg(brillo_green_).arg(brillo_blue_));
    ui->labelContraste->setText(QString("Contraste Actual R: %1 G: %2 B: %3 ").arg(contraste_red_).arg(contraste_green_).arg(contraste_blue_));

  }


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
