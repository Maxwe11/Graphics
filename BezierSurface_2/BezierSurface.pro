#-------------------------------------------------
#
# Project created by QtCreator 2012-10-04T17:18:54
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BezierSurface
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           primitives.cpp \
           glwidget.cpp \
    model.cpp

HEADERS += mainwindow.h \
            primitives.h \
            glwidget.h \
    model.h

FORMS += mainwindow.ui
