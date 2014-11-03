#include <QDebug>
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
    ui(new Ui::CentralWidget)//,
    //fw(new FramelessWindow(0))
{
    ui->setupUi(this);
    QString fontName(QLatin1String(":/font/AlternateGotNo3D.ttf"));
    int id = QFontDatabase::addApplicationFont(fontName);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontUsed = QFont(family);
    fontUsed.setPointSize(14);
    ui->label->setFont(fontUsed);
    connect(ui->switcher, SIGNAL(switched(bool)), this, SLOT(setFrameless(bool)));
}

CentralWidget::~CentralWidget()
{
    delete ui;
}
void CentralWidget::setFrameless(bool f){
    static FramelessWindow* fw = new FramelessWindow;
    if(f){
        fw->move(pos());
        fw->setBody(this);
        fw->show();
        ui->switcher->startAnimation();
    }else{
        fw->hide();
        setParent(0);
        move(fw->pos());
        show();
        ui->switcher->startAnimation();
    }
}
