TEMPLATE = app
CONFIG += qt designer
QT += widgets

DESTDIR = out

INCLUDEPATH +=  "include"

HEADERS = \
    #include/MainWidget.hpp \
    include/mainwindow.h \
    include/SwitcherWidget.h \
    windowhead.h \
    switcherif.h


SOURCES = src/main.cpp \
    #src/MainWidget.cpp \
    src/SwitcherWidget.cpp \
    src/mainwindow.cpp \
    windowhead.cpp \
    switcherif.cpp
    

FORMS += \
    mainwindow.ui \
    windowhead.ui

OTHER_FILES += font/AlternateGotNo3D.ttf
