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
    brilloycontraste.cpp \
    events.cpp

HEADERS += \
        src/include/mainwindow.h \
    src/include/asmopencv.h \
    src/include/image.h \
    brilloycontraste.h \
    events.h

FORMS += \
        src/forms/mainwindow.ui \
    brilloycontraste.ui


RESOURCES += \
    src/qrc/recursos.qrc

INCLUDEPATH += $$PWD/src/include
DEPENDPATH += $$PWD/src/include

win32: INCLUDEPATH += $$PWD/libs/include
win32: DEPENDPATH += $$PWD/libs/include

#win32: LIBS += -L$$PWD/libs/mingwx64/opencv412/dll.a/ -llibopencv_core.dll

win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_core412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_highgui412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_imgcodecs412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_imgproc412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_features2d412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_calib3d412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_videoio412.dll


unix:!macx: INCLUDEPATH += $$PWD/libs/include
unix:!macx: DEPENDPATH += $$PWD/libs/include

unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_core.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_highgui.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_imgcodecs.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_imgproc.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_features2d.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_calib3d.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_videoio.so.4.1

DISTFILES += \
    ../../Users/Juan Siverio.ULL/Downloads/open-file.png

