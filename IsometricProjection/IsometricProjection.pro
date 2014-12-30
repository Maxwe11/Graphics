#-------------------------------------------------
#
# Project created by QtCreator 2011-12-07T16:41:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IsometricProjection
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
        glwidget.cpp \
        primitives.cpp

HEADERS  += widget.h \
    glwidget.h \
    primitives.h

FORMS    += widget.ui




