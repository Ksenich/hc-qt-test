#include "include\centralwidget.h"
#include "ui_centralwidget.h"
#include "framelesswindow.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CentralWidget)//,
    //fw(new FramelessWindow(0))
{
    ui->setupUi(this);
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
        //hide();
        fw->move(pos());
        fw->resize(size());
        fw->setBody(this);
        fw->show();
        //show();
        ui->switcher->startAnimation();
    }else{
        fw->hide();
        setParent(0);
        move(fw->pos());
        resize(fw->size());
        show();
        ui->switcher->startAnimation();
    }
}
