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
    ui->frame->setAutoFillBackground(true);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(5);
    effect->setOffset(0,0);
    connect(ui->header, SIGNAL(restoreClicked()), this, SLOT(restore()));
    connect(ui->header, SIGNAL(maximizeClicked()), this, SLOT(maximise()));
    ui->frame->setGraphicsEffect(effect);
}

FramelessWindow::~FramelessWindow()
{
    delete ui;
}

void FramelessWindow::setBody(QWidget *qw){

    int h = ui->header->height() + qw->height() +12;
    int w = qw->width() +12;
    resize(w,h);
    ui->body->addWidget(qw);
}

QSize FramelessWindow::visibleGeometry()
{
    return ui->frame->size();
}

void FramelessWindow::resize(int w, int h)
{
    QWidget::resize(w + invFW()*2, h + invFH()*2);
}

int FramelessWindow::width() const
{
    return QWidget::width() - invFW()*2;
}

int FramelessWindow::height() const
{
    return QWidget::height() - invFH()*2;
}

HeaderWidget *FramelessWindow::getHeader()
{
    return ui->header;
}

ResizableFrame *FramelessWindow::getFrame()
{
    return ui->frame;
}

int FramelessWindow::invFW() const
{
    return 11;
}

int FramelessWindow::invFH() const
{
    return 11;
}

void FramelessWindow::maximise()
{
    layout()->setMargin(0);
}

void FramelessWindow::restore()
{
    layout()->setMargin(9);
}


