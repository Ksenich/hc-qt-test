#include <QFontDatabase>
#include <QFont>
#include <QString>
#include <QPalette>
#include <QColor>

#include "include\centralwidget.h"
#include "ui_centralwidget.h"
#include "framelesswindow.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
    QString fontName(QLatin1String(":/font/AlternateGotNo3D.ttf"));
    int id = QFontDatabase::addApplicationFont(fontName);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontUsed = QFont(family);
    fontUsed.setPointSize(14);
    ui->label->setFont(fontUsed);
}

CentralWidget::~CentralWidget()
{
    delete ui;
}

SwitcherWidget *CentralWidget::getSwitcher()
{
    return ui->switcher;
}

