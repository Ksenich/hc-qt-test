#include <QApplication>
#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    cw(new CentralWidget),
    fw(new FramelessWindow),
    switcher(cw->getSwitcher()),
    header(fw->getHeader())
{
    setAttribute(Qt::WA_TranslucentBackground);
    resize(cw->size());
    setCentralWidget(cw);
    connect(switcher, SIGNAL(switched(bool)), this, SLOT(setFrameless(bool)));
    connect(fw->getFrame(),  SIGNAL(resized(QRect)), this, SLOT(resizeBy(QRect)));

    connect(header, SIGNAL(closeClicked()), QApplication::instance(), SLOT(quit()));
    connect(header, SIGNAL(minimizeClicked()), this, SLOT(showMinimized()));
    connect(header, SIGNAL(maximizeClicked()), this, SLOT(showMaximized()));
    connect(header, SIGNAL(restoreClicked()),  this, SLOT(showNormal()));
    connect(header, SIGNAL(dragged(int,int)),  this, SLOT(moveBy(int,int)));
}

void MainWindow::setFrameless(bool f){
    if(f){
        setWindowFlags(Qt::FramelessWindowHint);
        cw->setParent(fw);
        fw->setBody(cw);
        resize(fw->size());
        setCentralWidget(fw);
        show();
        switcher->startAnimation();
    }else{
        setWindowFlags(0);
        cw->setParent(this);
        fw->setParent(0);
        resize(cw->size());
        setCentralWidget(cw);
        show();
        switcher->startAnimation();
    }
}

void MainWindow::resizeBy(QRect delta)
{
    moveBy(delta.x(), delta.y());
    resize(width() + delta.width(), height() + delta.height());
}

void MainWindow::moveBy(int x, int y)
{
    move(pos().x() + x, pos().y() + y);
}

