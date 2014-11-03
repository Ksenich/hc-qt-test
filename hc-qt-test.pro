TEMPLATE = app
CONFIG += qt
QT += widgets

DESTDIR = out

INCLUDEPATH +=  "include"

HEADERS = \
    include/header.h \
    include/centralwidget.h \
    include/framelesswindow.h \
    include/switcherwidget.h

SOURCES = src/main.cpp \
    src/header.cpp \
    src/centralwidget.cpp \
    src/framelesswindow.cpp \
    src/switcherwidget.cpp

RESOURCES += app.qrc

FORMS += \
    forms/header.ui \
    forms/centralwidget.ui \
    forms/framelesswindow.ui
