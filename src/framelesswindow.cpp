#include <Qt>
#include <QGraphicsDropShadowEffect>
#include <QDebug>

#include "framelesswindow.h"
#include "ui_framelesswindow.h"
#include "centralwidget.h"
#include "switcherwidget.h"

FramelessWindow::FramelessWindow(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint),
    ui(new Ui::FramelessWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->holder->setAutoFillBackground(true);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(50);
    effect->setOffset(0,0);
    connect(ui->header, SIGNAL(closeClicked()), QApplication::instance(), SLOT(quit()));
    connect(ui->header, SIGNAL(minimizeClicked()), this, SLOT(showMinimized()));
    connect(ui->header, SIGNAL(maximizeClicked()), this, SLOT(showMaximized()));
    connect(ui->header, SIGNAL(maximizeClicked()), this, SLOT(maximise()));
    connect(ui->header, SIGNAL(restoreClicked()), this, SLOT(showNormal()));
    connect(ui->header, SIGNAL(restoreClicked()), this, SLOT(restore()));
    connect(ui->header, SIGNAL(dragged(int,int)), this, SLOT(moveBy(int,int)));
    //ui->holder->setGraphicsEffect(effect);
}

FramelessWindow::~FramelessWindow()
{
    delete ui;
}

void FramelessWindow::setBody(QWidget *qw){

    int h = ui->header->height() + qw->height() +12;
    int w = qw->width() +12;
    resize(w,h);
    ui->body->addWidget(qw);
}

QSize FramelessWindow::visibleGeometry()
{
    return ui->holder->size();
}

void FramelessWindow::resize(int w, int h)
{
    QWidget::resize(w + invFW()*2, h + invFH()*2);
}

int FramelessWindow::invFW()
{
    return 11;
}

int FramelessWindow::invFH()
{
    return 11;
}

void FramelessWindow::maximise()
{
    layout()->setMargin(0);
}

void FramelessWindow::restore()
{
    layout()->setMargin(9);
}

void FramelessWindow::moveBy(int x, int y)
{
    move(pos().x() + x, pos().y() + y);
}
