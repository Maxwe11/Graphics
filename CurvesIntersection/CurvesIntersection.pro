QT += gui opengl widgets

CONFIG += exceptions

HEADERS += \
    primitives.h \
    mainwindow.h \
    glwidget.h \
    bezier.h \
    model.h

SOURCES += \
    primitives.cpp \
    mainwindow.cpp \
    main.cpp \
    glwidget.cpp \
    model.cpp

FORMS += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
