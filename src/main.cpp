#include <QApplication>

#include "SwitcherWidget.h"
#include "mainwindow.h"
int main(int argc, char** argv){
    QApplication app(argc, argv);
    //SwitcherWidget mw;
    MainWindow mw;
    mw.show();
    app.exec();
    return 0;
}
