#-------------------------------------------------
#
# Project created by QtCreator 2011-12-07T16:41:42
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SurfaceRender
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    glwidget.cpp \
    primitives.cpp \
    dialog.cpp \
    point.cpp \
    bezier.cpp

HEADERS  += widget.h \
    glwidget.h \
    primitives.h \
    dialog.h \
    point.h \
    bezier.h

FORMS += widget.ui \
    dialog.ui

QMAKE_CXXFLAGS += -std=c++11




