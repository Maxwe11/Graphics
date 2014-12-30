QT       += core gui widgets

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    widget.h \
    view.h \
    polygon.h \
    point.h

SOURCES += \
    widget.cpp \
    view.cpp \
    polygon.cpp \
    point.cpp \
    main.cpp

FORMS += \
    widget.ui
