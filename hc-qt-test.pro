TEMPLATE = app
CONFIG += qt
QT += widgets

DESTDIR = out

INCLUDEPATH +=  "include"

HEADERS = \
    include/mainwindow.h \
    include/SwitcherWidget.h \
    cui_mainwindowframeless.h \
    cui_mainwindowframed.h \
    cui_header.h

SOURCES = src/main.cpp \
    src/SwitcherWidget.cpp \
    src/mainwindow.cpp \
    cui_mainwindowframeless.cpp \
    cui_mainwindowframed.cpp \
    cui_header.cpp

RESOURCES += app.qrc
