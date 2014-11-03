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
    fontUsed.setPointSize(20);
//    QPalette textPalette = palette();
//    textPalette.setColor(QPalette::WindowText, QColor(204,204,204));
//    textPalette.setColor(QPalette::Window, QColor(255,255,255));
//    setPalette(textPalette);
    ui->label->setFont(fontUsed);
//    ui->label->setPalette(textPalette);
    connect(ui->switcher, SIGNAL(switched(bool)), this, SLOT(setFrameless(bool)));
}

CentralWidget::~CentralWidget()
{
    delete ui;
}
FramelessWindow * fw=0;
void CentralWidget::setFrameless(bool f){
    if(f){
        if(fw == 0){
            fw = new FramelessWindow;
        }
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
    qDebug() << size();
}
