#include <QApplication>

#include "SwitcherWidget.h"
#include "mainwindow.h"
int main(int argc, char** argv){
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    app.exec();
    return 0;
}
