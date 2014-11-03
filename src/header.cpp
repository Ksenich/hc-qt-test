#include <QPalette>
#include <QColor>

#include "include\header.h"
#include "ui_header.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::header)
{
    ui->setupUi(this);
}

HeaderWidget::~HeaderWidget()
{
    delete ui;
}
