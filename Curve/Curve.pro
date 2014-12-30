#-------------------------------------------------
#
# Project created by QtCreator 2011-10-24T18:37:26
#
#-------------------------------------------------

QT       += core gui \
            opengl

TARGET = Curve
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    primitives.cpp \
    cartesianleaf.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    primitives.h \
    cartesianleaf.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    equation.png













