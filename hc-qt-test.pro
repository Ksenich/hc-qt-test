TEMPLATE = app
CONFIG += qt 
QT += widgets

DESTDIR = out

INCLUDEPATH = include

HEADERS = SwitcherWidget.hpp


SOURCES = src/main.cpp \
    src/MainWidget.cpp \
    SwitcherWidget.cpp
    