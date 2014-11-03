#include <QPalette>
#include <QColor>

#include "include\header.h"
#include "ui_header.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::header)
{
    ui->setupUi(this);
    QPalette p;
    p.setColor(QPalette::Window, QColor(252, 250, 247));
    setPalette(p);
    //setStyleSheet("background-color:black;");
}

HeaderWidget::~HeaderWidget()
{
    delete ui;
}
