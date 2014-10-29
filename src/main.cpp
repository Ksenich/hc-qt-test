#include <QApplication>

#include "MainWidget.hpp"

inat main(int argc char** argv){
    QApplication app(argc, argv);
    MainWidget mw;
    mw.show();
    app.exec();
    return 0;
}