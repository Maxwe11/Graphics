#-------------------------------------------------
#
# Project created by QtCreator 2011-12-07T16:41:42
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SurfaceRender
TEMPLATE = app

FORMS += widget.ui \
        dialog.ui

SOURCES += main.cpp\
        widget.cpp \
    glwidget.cpp \
    primitives.cpp \
    dialog.cpp \
    point.cpp \
    bezier.cpp \
    graphicsobject.cpp \
    face.cpp \
    paraboliccylinder.cpp \
    surface.cpp \
    rationalsurface.cpp \
    cube.cpp

HEADERS  += widget.h \
    glwidget.h \
    primitives.h \
    dialog.h \
    point.h \
    bezier.h \
    graphicsobject.h \
    face.h \
    paraboliccylinder.h \
    surface.h \
    rationalsurface.h \
    cube.h

QMAKE_CXXFLAGS += -std=c++11 -o3




