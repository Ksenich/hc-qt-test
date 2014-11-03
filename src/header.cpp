#include <QPalette>
#include <QColor>
#include <QApplication>
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>

#include "include\header.h"
#include "ui_header.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::header),
    maximized(false)
{
    ui->setupUi(this);
    connect(ui->closeButton, SIGNAL(clicked()), this, SIGNAL(closeClicked()));
    connect(ui->minimiseButton, SIGNAL(clicked()), this, SIGNAL(minimizeClicked()));
    connect(ui->maximizeButton, SIGNAL(clicked()), this, SLOT(onMaximizeClicked()));
}

HeaderWidget::~HeaderWidget()
{
    delete ui;
}

void HeaderWidget::onMaximizeClicked(){
    if(maximized){
        QIcon maxIcon(QPixmap(":/images/maximize.png"));
        ui->maximizeButton->setIcon(maxIcon);
        restoreClicked();
    }else{
        QIcon restoreIcon(QPixmap(":/images/restore.png"));
        ui->maximizeButton->setIcon(restoreIcon);
        maximizeClicked();
    }
    maximized = !maximized;
}

QPoint previousPos;

void HeaderWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPoint offset(event->globalPos() - previousPos);
        qDebug() << offset;
        dragged(offset.x(), offset.y());
        previousPos = event->globalPos();
        event->accept();
    }
}
void HeaderWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        previousPos = event->globalPos();
//        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}
