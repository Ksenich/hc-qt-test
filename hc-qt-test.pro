TEMPLATE = app
CONFIG += qt
QT += widgets

DESTDIR = out

INCLUDEPATH +=  "include"

HEADERS = \
    include/header.h \
    include/centralwidget.h \
    include/framelesswindow.h \
    include/switcherwidget.h \
    include/constants.h \
    include/resizableframe.h \
    include/mainwindow.h

SOURCES = src/main.cpp \
    src/header.cpp \
    src/centralwidget.cpp \
    src/framelesswindow.cpp \
    src/switcherwidget.cpp \
    src/resizableframe.cpp \
    src/mainwindow.cpp

RESOURCES += app.qrc

FORMS += \
    forms/header.ui \
    forms/centralwidget.ui \
    forms/framelesswindow.ui
