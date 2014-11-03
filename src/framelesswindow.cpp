#include <Qt>
#include <QGraphicsDropShadowEffect>

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

void FramelessWindow::setBody(QWidget *w){
    ui->body->addWidget(w);
}
