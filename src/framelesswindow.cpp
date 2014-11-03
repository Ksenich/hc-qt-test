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

    int h = ui->header->height() + qw->height();
    int w = qw->width();
    qDebug() << size() << ui->holder->size() << ui->header->size();
    resize(w,h);
    qDebug() << size() << ui->holder->size() << ui->header->size()
             << (size() - ui->holder->size());
    ui->body->addWidget(qw);
    qDebug() << size() << ui->holder->size() << ui->header->size()
             << (size() - ui->holder->size());
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
