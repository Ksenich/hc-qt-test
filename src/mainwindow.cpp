#include <QSizePolicy>
#include <QFrame>
#include <QGraphicsDropShadowEffect>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SwitcherWidget.h"
#include "windowhead.h"

void setupFramelessUi(QWidget* cw){
	cw->setAttribute(Qt::WA_TranslucentBackground);
	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(cw);
    effect->setBlurRadius(5);
	cw->setGraphicsEffect(effect);
	QVBoxLayout *vl = new QVBoxLayout(cw);
	WindowHead * wh = new WindowHead(cw);
	//sw->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	MainWindow * mw = new MainWindow(cw);
	vl->addWidget(wh);
	vl->addWidget(mw, 1);
	cw->setLayout(vl);
//	mw->setCentralWidget(cw);
	cw->resize(640,480);
}

void setupUi(QWidget *mw){
	mw->setAttribute(Qt::WA_TranslucentBackground);
	QWidget *cw = new QWidget(mw);	
	cw->setAutoFillBackground(true);
	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(cw);
    effect->setBlurRadius(50);
	effect->setOffset(0,0);
	mw->setGraphicsEffect(effect);

	QVBoxLayout *vl = new QVBoxLayout(cw);
	SwitcherWidget * sw = new SwitcherWidget(cw);
	sw->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	QLabel *label = new QLabel("push it", cw);
	label->setAlignment(Qt::AlignHCenter);
	vl->addWidget(sw,1);
	vl->addWidget(label);
	cw->setLayout(vl);
	
	QVBoxLayout *v2 = new QVBoxLayout(mw);
	v2->setContentsMargins(30,30,30,30);
	v2->addWidget(cw);

	mw->setLayout(v2);
	mw->resize(640,480);
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint)
    //ui(new Ui::MainWindow)
{
	setupUi(this);

	//connect(ui->widget, SIGNAL(setOn(bool)), this, SLOT(setFrameless(bool)));
}


MainWindow::~MainWindow()
{
}

void MainWindow::setFrameless(bool b){
    if(b){
        setWindowFlags(Qt::FramelessWindowHint);
    }else{
        setWindowFlags(0);
    }
}
