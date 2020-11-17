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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrilloYContraste
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEditContrasteGris;
    QLabel *label_2;
    QSlider *horizontalSlider_3;
    QLabel *label;
    QFrame *line_2;
    QLineEdit *lineEditBrilloGris;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QSlider *horizontalSlider_6;
    QFrame *line;
    QPushButton *pushButtonClose;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *sliderContrasteGris;
    QSlider *sliderBrilloGris;
    QLabel *pixelsLost;

    void setupUi(QWidget *BrilloYContraste)
    {
        if (BrilloYContraste->objectName().isEmpty())
            BrilloYContraste->setObjectName(QString::fromUtf8("BrilloYContraste"));
        BrilloYContraste->resize(367, 295);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BrilloYContraste->sizePolicy().hasHeightForWidth());
        BrilloYContraste->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(BrilloYContraste);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_4 = new QLineEdit(BrilloYContraste);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 6, 3, 1, 1);

        lineEditContrasteGris = new QLineEdit(BrilloYContraste);
        lineEditContrasteGris->setObjectName(QString::fromUtf8("lineEditContrasteGris"));

        gridLayout->addWidget(lineEditContrasteGris, 1, 3, 1, 1);

        label_2 = new QLabel(BrilloYContraste);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalSlider_3 = new QSlider(BrilloYContraste);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 10, 1, 1, 1);

        label = new QLabel(BrilloYContraste);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        line_2 = new QFrame(BrilloYContraste);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 11, 3, 1, 1);

        lineEditBrilloGris = new QLineEdit(BrilloYContraste);
        lineEditBrilloGris->setObjectName(QString::fromUtf8("lineEditBrilloGris"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditBrilloGris->sizePolicy().hasHeightForWidth());
        lineEditBrilloGris->setSizePolicy(sizePolicy1);
        lineEditBrilloGris->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lineEditBrilloGris, 1, 1, 1, 1);

        lineEdit_6 = new QLineEdit(BrilloYContraste);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 9, 3, 1, 1);

        lineEdit_2 = new QLineEdit(BrilloYContraste);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 3, 1, 1);

        lineEdit_3 = new QLineEdit(BrilloYContraste);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 1);

        lineEdit_5 = new QLineEdit(BrilloYContraste);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 9, 1, 1, 1);

        horizontalSlider_6 = new QSlider(BrilloYContraste);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_6, 4, 3, 1, 1);

        line = new QFrame(BrilloYContraste);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 11, 1, 1, 1);

        pushButtonClose = new QPushButton(BrilloYContraste);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 13, 3, 1, 1);

        horizontalSlider_2 = new QSlider(BrilloYContraste);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 8, 1, 1, 1);

        horizontalSlider = new QSlider(BrilloYContraste);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 4, 1, 1, 1);

        lineEdit = new QLineEdit(BrilloYContraste);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 3, 1, 1, 1);

        horizontalSlider_4 = new QSlider(BrilloYContraste);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_4, 10, 2, 1, 2);

        horizontalSlider_5 = new QSlider(BrilloYContraste);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_5, 8, 3, 1, 1);

        sliderContrasteGris = new QSlider(BrilloYContraste);
        sliderContrasteGris->setObjectName(QString::fromUtf8("sliderContrasteGris"));
        sliderContrasteGris->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        sliderContrasteGris->setMinimum(1);
        sliderContrasteGris->setMaximum(127);
        sliderContrasteGris->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderContrasteGris, 2, 3, 1, 1);

        sliderBrilloGris = new QSlider(BrilloYContraste);
        sliderBrilloGris->setObjectName(QString::fromUtf8("sliderBrilloGris"));
        sliderBrilloGris->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        sliderBrilloGris->setMaximum(255);
        sliderBrilloGris->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBrilloGris, 2, 1, 1, 1);

        pixelsLost = new QLabel(BrilloYContraste);
        pixelsLost->setObjectName(QString::fromUtf8("pixelsLost"));

        gridLayout->addWidget(pixelsLost, 13, 1, 1, 1);


        retranslateUi(BrilloYContraste);

        QMetaObject::connectSlotsByName(BrilloYContraste);
    } // setupUi

    void retranslateUi(QWidget *BrilloYContraste)
    {
        BrilloYContraste->setWindowTitle(QApplication::translate("BrilloYContraste", "Form", nullptr));
        label_2->setText(QApplication::translate("BrilloYContraste", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Contraste</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("BrilloYContraste", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Brillo</span></p></body></html>", nullptr));
        pushButtonClose->setText(QApplication::translate("BrilloYContraste", "Cerrar", nullptr));
        pixelsLost->setText(QApplication::translate("BrilloYContraste", "Pixel Adaptados: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrilloYContraste: public Ui_BrilloYContraste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRILLOYCONTRASTE_H
