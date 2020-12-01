/********************************************************************************
** Form generated from reading UI file 'brilloycontraste.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRILLOYCONTRASTE_H
#define UI_BRILLOYCONTRASTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrilloYContraste
{
public:
    QGridLayout *gridLayout;
    QSlider *sliderContrasteGreen;
    QLineEdit *lineEditBrilloGris;
    QLineEdit *lineEditContrasteRed;
    QProgressBar *progressBarGrayTo0;
    QSlider *sliderContrasteBlue;
    QLabel *pixelsLostTo255;
    QFrame *line_3;
    QLineEdit *lineEditContrasteGris;
    QLabel *labelContraste;
    QProgressBar *progressBarRedTo255;
    QLineEdit *lineEditBrilloBlue;
    QProgressBar *progressBarGreenTo255;
    QPushButton *pushButtonApply;
    QProgressBar *progressBarRedTo0;
    QSlider *sliderBrilloGreen;
    QProgressBar *progressBarBlueTo255;
    QPushButton *pushButtonClose;
    QLabel *pixelsLostTo0;
    QSlider *sliderContrasteRed;
    QFrame *line_5;
    QCheckBox *checkBoxKeepOriginal;
    QFrame *line_6;
    QProgressBar *progressBarGrayTo255;
    QFrame *line_2;
    QProgressBar *progressBarBlueTo0;
    QSlider *sliderContrasteGris;
    QLabel *labelBrillo;
    QCheckBox *checkBoxRealTime;
    QSlider *sliderBrilloGris;
    QLineEdit *lineEditContrasteGreen;
    QProgressBar *progressBarGreenTo0;
    QLineEdit *lineEditBrilloGreen;
    QLineEdit *lineEditContrasteBlue;
    QSlider *sliderBrilloRed;
    QSlider *sliderBrilloBlue;
    QLineEdit *lineEditBrilloRed;
    QFrame *line;
    QLabel *labelBrilloOriginal;
    QLabel *labelContrasteOriginal;

    void setupUi(QWidget *BrilloYContraste)
    {
        if (BrilloYContraste->objectName().isEmpty())
            BrilloYContraste->setObjectName(QString::fromUtf8("BrilloYContraste"));
        BrilloYContraste->resize(803, 359);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BrilloYContraste->sizePolicy().hasHeightForWidth());
        BrilloYContraste->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(BrilloYContraste);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sliderContrasteGreen = new QSlider(BrilloYContraste);
        sliderContrasteGreen->setObjectName(QString::fromUtf8("sliderContrasteGreen"));
        sliderContrasteGreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        sliderContrasteGreen->setMaximum(255);
        sliderContrasteGreen->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderContrasteGreen, 13, 3, 1, 1);

        lineEditBrilloGris = new QLineEdit(BrilloYContraste);
        lineEditBrilloGris->setObjectName(QString::fromUtf8("lineEditBrilloGris"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditBrilloGris->sizePolicy().hasHeightForWidth());
        lineEditBrilloGris->setSizePolicy(sizePolicy1);
        lineEditBrilloGris->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lineEditBrilloGris, 6, 1, 1, 1);

        lineEditContrasteRed = new QLineEdit(BrilloYContraste);
        lineEditContrasteRed->setObjectName(QString::fromUtf8("lineEditContrasteRed"));

        gridLayout->addWidget(lineEditContrasteRed, 8, 3, 1, 1);

        progressBarGrayTo0 = new QProgressBar(BrilloYContraste);
        progressBarGrayTo0->setObjectName(QString::fromUtf8("progressBarGrayTo0"));
        progressBarGrayTo0->setMaximum(255);
        progressBarGrayTo0->setValue(0);
        progressBarGrayTo0->setTextVisible(true);
        progressBarGrayTo0->setInvertedAppearance(false);
        progressBarGrayTo0->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(progressBarGrayTo0, 6, 5, 1, 1);

        sliderContrasteBlue = new QSlider(BrilloYContraste);
        sliderContrasteBlue->setObjectName(QString::fromUtf8("sliderContrasteBlue"));
        sliderContrasteBlue->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        sliderContrasteBlue->setMaximum(255);
        sliderContrasteBlue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderContrasteBlue, 15, 2, 1, 2);

        pixelsLostTo255 = new QLabel(BrilloYContraste);
        pixelsLostTo255->setObjectName(QString::fromUtf8("pixelsLostTo255"));

        gridLayout->addWidget(pixelsLostTo255, 1, 6, 1, 1);

        line_3 = new QFrame(BrilloYContraste);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 1, 4, 1, 1);

        lineEditContrasteGris = new QLineEdit(BrilloYContraste);
        lineEditContrasteGris->setObjectName(QString::fromUtf8("lineEditContrasteGris"));

        gridLayout->addWidget(lineEditContrasteGris, 6, 3, 1, 1);

        labelContraste = new QLabel(BrilloYContraste);
        labelContraste->setObjectName(QString::fromUtf8("labelContraste"));

        gridLayout->addWidget(labelContraste, 1, 3, 1, 1);

        progressBarRedTo255 = new QProgressBar(BrilloYContraste);
        progressBarRedTo255->setObjectName(QString::fromUtf8("progressBarRedTo255"));
        progressBarRedTo255->setMaximum(255);
        progressBarRedTo255->setValue(0);

        gridLayout->addWidget(progressBarRedTo255, 8, 6, 1, 1);

        lineEditBrilloBlue = new QLineEdit(BrilloYContraste);
        lineEditBrilloBlue->setObjectName(QString::fromUtf8("lineEditBrilloBlue"));

        gridLayout->addWidget(lineEditBrilloBlue, 14, 1, 1, 1);

        progressBarGreenTo255 = new QProgressBar(BrilloYContraste);
        progressBarGreenTo255->setObjectName(QString::fromUtf8("progressBarGreenTo255"));
        progressBarGreenTo255->setMaximum(255);
        progressBarGreenTo255->setValue(0);

        gridLayout->addWidget(progressBarGreenTo255, 11, 6, 1, 1);

        pushButtonApply = new QPushButton(BrilloYContraste);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));

        gridLayout->addWidget(pushButtonApply, 20, 1, 1, 1);

        progressBarRedTo0 = new QProgressBar(BrilloYContraste);
        progressBarRedTo0->setObjectName(QString::fromUtf8("progressBarRedTo0"));
        progressBarRedTo0->setMaximum(255);
        progressBarRedTo0->setValue(0);

        gridLayout->addWidget(progressBarRedTo0, 8, 5, 1, 1);

        sliderBrilloGreen = new QSlider(BrilloYContraste);
        sliderBrilloGreen->setObjectName(QString::fromUtf8("sliderBrilloGreen"));
        sliderBrilloGreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        sliderBrilloGreen->setMaximum(255);
        sliderBrilloGreen->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBrilloGreen, 13, 1, 1, 1);

        progressBarBlueTo255 = new QProgressBar(BrilloYContraste);
        progressBarBlueTo255->setObjectName(QString::fromUtf8("progressBarBlueTo255"));
        progressBarBlueTo255->setMaximum(255);
        progressBarBlueTo255->setValue(0);

        gridLayout->addWidget(progressBarBlueTo255, 14, 6, 1, 1);

        pushButtonClose = new QPushButton(BrilloYContraste);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 20, 3, 1, 1);

        pixelsLostTo0 = new QLabel(BrilloYContraste);
        pixelsLostTo0->setObjectName(QString::fromUtf8("pixelsLostTo0"));

        gridLayout->addWidget(pixelsLostTo0, 1, 5, 1, 1);

        sliderContrasteRed = new QSlider(BrilloYContraste);
        sliderContrasteRed->setObjectName(QString::fromUtf8("sliderContrasteRed"));
        sliderContrasteRed->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        sliderContrasteRed->setMaximum(255);
        sliderContrasteRed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderContrasteRed, 9, 3, 1, 1);

        line_5 = new QFrame(BrilloYContraste);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 2, 1, 1, 1);

        checkBoxKeepOriginal = new QCheckBox(BrilloYContraste);
        checkBoxKeepOriginal->setObjectName(QString::fromUtf8("checkBoxKeepOriginal"));

        gridLayout->addWidget(checkBoxKeepOriginal, 20, 5, 1, 1);

        line_6 = new QFrame(BrilloYContraste);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 2, 3, 1, 1);

        progressBarGrayTo255 = new QProgressBar(BrilloYContraste);
        progressBarGrayTo255->setObjectName(QString::fromUtf8("progressBarGrayTo255"));
        progressBarGrayTo255->setMaximum(255);
        progressBarGrayTo255->setValue(0);

        gridLayout->addWidget(progressBarGrayTo255, 6, 6, 1, 1);

        line_2 = new QFrame(BrilloYContraste);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 16, 3, 1, 1);

        progressBarBlueTo0 = new QProgressBar(BrilloYContraste);
        progressBarBlueTo0->setObjectName(QString::fromUtf8("progressBarBlueTo0"));
        progressBarBlueTo0->setMaximum(255);
        progressBarBlueTo0->setValue(0);

        gridLayout->addWidget(progressBarBlueTo0, 14, 5, 1, 1);

        sliderContrasteGris = new QSlider(BrilloYContraste);
        sliderContrasteGris->setObjectName(QString::fromUtf8("sliderContrasteGris"));
        sliderContrasteGris->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        sliderContrasteGris->setMinimum(1);
        sliderContrasteGris->setMaximum(127);
        sliderContrasteGris->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderContrasteGris, 7, 3, 1, 1);

        labelBrillo = new QLabel(BrilloYContraste);
        labelBrillo->setObjectName(QString::fromUtf8("labelBrillo"));

        gridLayout->addWidget(labelBrillo, 1, 1, 1, 1);

        checkBoxRealTime = new QCheckBox(BrilloYContraste);
        checkBoxRealTime->setObjectName(QString::fromUtf8("checkBoxRealTime"));

        gridLayout->addWidget(checkBoxRealTime, 20, 6, 1, 1);

        sliderBrilloGris = new QSlider(BrilloYContraste);
        sliderBrilloGris->setObjectName(QString::fromUtf8("sliderBrilloGris"));
        sliderBrilloGris->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        sliderBrilloGris->setMaximum(255);
        sliderBrilloGris->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBrilloGris, 7, 1, 1, 1);

        lineEditContrasteGreen = new QLineEdit(BrilloYContraste);
        lineEditContrasteGreen->setObjectName(QString::fromUtf8("lineEditContrasteGreen"));

        gridLayout->addWidget(lineEditContrasteGreen, 11, 3, 1, 1);

        progressBarGreenTo0 = new QProgressBar(BrilloYContraste);
        progressBarGreenTo0->setObjectName(QString::fromUtf8("progressBarGreenTo0"));
        progressBarGreenTo0->setMaximum(255);
        progressBarGreenTo0->setValue(0);

        gridLayout->addWidget(progressBarGreenTo0, 11, 5, 1, 1);

        lineEditBrilloGreen = new QLineEdit(BrilloYContraste);
        lineEditBrilloGreen->setObjectName(QString::fromUtf8("lineEditBrilloGreen"));

        gridLayout->addWidget(lineEditBrilloGreen, 11, 1, 1, 1);

        lineEditContrasteBlue = new QLineEdit(BrilloYContraste);
        lineEditContrasteBlue->setObjectName(QString::fromUtf8("lineEditContrasteBlue"));

        gridLayout->addWidget(lineEditContrasteBlue, 14, 3, 1, 1);

        sliderBrilloRed = new QSlider(BrilloYContraste);
        sliderBrilloRed->setObjectName(QString::fromUtf8("sliderBrilloRed"));
        sliderBrilloRed->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        sliderBrilloRed->setMaximum(255);
        sliderBrilloRed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBrilloRed, 9, 1, 1, 1);

        sliderBrilloBlue = new QSlider(BrilloYContraste);
        sliderBrilloBlue->setObjectName(QString::fromUtf8("sliderBrilloBlue"));
        sliderBrilloBlue->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        sliderBrilloBlue->setMaximum(255);
        sliderBrilloBlue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBrilloBlue, 15, 1, 1, 1);

        lineEditBrilloRed = new QLineEdit(BrilloYContraste);
        lineEditBrilloRed->setObjectName(QString::fromUtf8("lineEditBrilloRed"));

        gridLayout->addWidget(lineEditBrilloRed, 8, 1, 1, 1);

        line = new QFrame(BrilloYContraste);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 16, 1, 1, 1);

        labelBrilloOriginal = new QLabel(BrilloYContraste);
        labelBrilloOriginal->setObjectName(QString::fromUtf8("labelBrilloOriginal"));

        gridLayout->addWidget(labelBrilloOriginal, 0, 1, 1, 1);

        labelContrasteOriginal = new QLabel(BrilloYContraste);
        labelContrasteOriginal->setObjectName(QString::fromUtf8("labelContrasteOriginal"));

        gridLayout->addWidget(labelContrasteOriginal, 0, 3, 1, 1);


        retranslateUi(BrilloYContraste);

        QMetaObject::connectSlotsByName(BrilloYContraste);
    } // setupUi

    void retranslateUi(QWidget *BrilloYContraste)
    {
        BrilloYContraste->setWindowTitle(QApplication::translate("BrilloYContraste", "Form", nullptr));
        progressBarGrayTo0->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        pixelsLostTo255->setText(QApplication::translate("BrilloYContraste", "Pixels ajustados a 255:", nullptr));
        labelContraste->setText(QApplication::translate("BrilloYContraste", "<html><head/><body><p>Contraste Actual:</p></body></html>", nullptr));
        progressBarRedTo255->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        progressBarGreenTo255->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        pushButtonApply->setText(QApplication::translate("BrilloYContraste", "Aplicar", nullptr));
        progressBarRedTo0->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        progressBarBlueTo255->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        pushButtonClose->setText(QApplication::translate("BrilloYContraste", "Cerrar", nullptr));
        pixelsLostTo0->setText(QApplication::translate("BrilloYContraste", "<html><head/><body><p align=\"center\">Pixels Ajustados a 0:</p></body></html>", nullptr));
        checkBoxKeepOriginal->setText(QApplication::translate("BrilloYContraste", "Respecto a imagen original", nullptr));
        progressBarGrayTo255->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        progressBarBlueTo0->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        labelBrillo->setText(QApplication::translate("BrilloYContraste", "<html><head/><body><p>Brillo Actual:</p></body></html>", nullptr));
        checkBoxRealTime->setText(QApplication::translate("BrilloYContraste", "Tiempo Real", nullptr));
        progressBarGreenTo0->setFormat(QApplication::translate("BrilloYContraste", "%p%", nullptr));
        labelBrilloOriginal->setText(QApplication::translate("BrilloYContraste", "TextLabel", nullptr));
        labelContrasteOriginal->setText(QApplication::translate("BrilloYContraste", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrilloYContraste: public Ui_BrilloYContraste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRILLOYCONTRASTE_H
