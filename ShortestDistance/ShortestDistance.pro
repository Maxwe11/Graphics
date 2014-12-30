QT += core gui opengl

HEADERS += \
    primitives.h \
    model.h \
    mainwindow.h \
    glwidget.h \
    bezier.h

SOURCES += \
    primitives.cpp \
    model.cpp \
    mainwindow.cpp \
    main.cpp \
    glwidget.cpp

FORMS += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

CONFIG += exceptions
