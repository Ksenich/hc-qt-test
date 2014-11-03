#include <QApplication>

#include "header.h"
#include "framelesswindow.h"
#include "centralwidget.h"
int main(int argc, char** argv){
    QApplication app(argc, argv);
    //MainWindow mw;
    CentralWidget mw;
    //header mw;
    mw.show();
    app.exec();
    return 0;
}
