#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T17:31:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = face_det
TEMPLATE = app

INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/tesseract
INCLUDEPATH += /usr/include/leptonica

LIBS += -L/usr/local/lib \
  -lopencv_calib3d \
  -lopencv_contrib \
  -lopencv_core \
  -lopencv_features2d \
  -lopencv_flann \
  -lopencv_gpu \
  -lopencv_highgui \
  -lopencv_imgproc \
  -lopencv_legacy \
  -lopencv_ml \
  -lopencv_nonfree \
  -lopencv_objdetect \
  -lopencv_ocl \
  -lopencv_photo \
  -lopencv_stitching \
  -lopencv_superres \
  -lopencv_video \
  -lopencv_videostab \
  -lrt \
  -lpthread \
  -lm \
  -ldl \
  -ltesseract \
  -llept \
  -lpthread

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
