#include "include\header.h"
#include "ui_header.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::header)
{
    ui->setupUi(this);
    //setStyleSheet("background-color:black;");
}

HeaderWidget::~HeaderWidget()
{
    delete ui;
}
