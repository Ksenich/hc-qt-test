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
