#include <QSizePolicy>

#include "mainwindow.h"
#include "cui_mainwindowframeless.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint)
    //ui(new Ui::MainWindow)
{
    CUI_MainWindowFrameless mwf;
    mwf.setupUi(this);
    connect(mwf.sw, SIGNAL(setOn(bool)), this, SLOT(setFrameless(bool)));
}


MainWindow::~MainWindow()
{
}

void MainWindow::setFrameless(bool b){
    if(b){
        setWindowFlags(Qt::FramelessWindowHint);
		show();
    }else{
        setWindowFlags(0);
		show();
    }
}
