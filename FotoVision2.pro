#-------------------------------------------------
#
# Project created by QtCreator 2020-10-30T18:44:58
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FotoVision2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:QMAKE_RPATHDIR += $ORIGIN/

unix::MOC_DIR = $$PWD/tmp/moc
win32::MOC_DIR = $$PWD/tmp/moc
mac::OBJECTS_DIR = $$PWD/tmp/o

unix::OBJECTS_DIR = $$PWD/tmp/o
win32::OBJECTS_DIR = $$PWD/tmp/o
mac::OBJECTS_DIR = $$PWD/tmp/o

unix::RCC_DIR = $$PWD/tmp/resources
mac::RCC_DIR = $$PWD/tmp/resources
win32::RCC_DIR = $$PWD/tmp/resources



 CONFIG(debug, debug|release) {
     unix: TARGET = $$join(TARGET,,,d)
     win32: TARGET = $$join(TARGET,,,d)
     mac: TARGET = $$join(TARGET,,,d)
 }

CONFIG += c++11

SOURCES += \
        src/cpp/main.cpp \
        src/cpp/mainwindow.cpp \
        src/cpp/image.cpp \
        src/cpp/brilloycontraste.cpp \
        src/cpp/events.cpp

HEADERS += \
        src/include/mainwindow.h \
    src/include/asmopencv.h \
    src/include/image.h \
    src/include/brilloycontraste.h \
    src/include/events.h

FORMS += \
        src/forms/mainwindow.ui \
        src/forms/brilloycontraste.ui


RESOURCES += \
    src/qrc/recursos.qrc

INCLUDEPATH += $$PWD/src/include
DEPENDPATH += $$PWD/src/include


