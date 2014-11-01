#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <Qt>
#include <QDebug>
#include <QEasingCurve>
#include <QFontDatabase>
#include <QSizePolicy>

#include "SwitcherWidget.h"

QColor SwitcherWidget::offColor(230, 222, 211);
QColor SwitcherWidget::onColor(146, 220, 92);

SwitcherWidget::SwitcherWidget(QWidget * parent):
        QWidget(parent/*, Qt::FramelessWindowHint*/)
{
	QString fontName(QLatin1String("font/AlternateGotNo3D.ttf"));
    int id = QFontDatabase::addApplicationFont(fontName);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    monospace = QFont(family);
    backgroundBrush.setStyle(Qt::SolidPattern);
    tumblerBrush.setStyle(Qt::SolidPattern);
    tumblerBrush.setColor(QColor(255,255,255));
    tumblerMargin = 30;
    px = 0;
    isOn = false;
    c = offColor;
}

void SwitcherWidget::drawBackground(QPainter& paint)
{
    backgroundBrush.setColor(c);
    paint.setBrush(backgroundBrush);
    paint.setPen(QPen(QColor(0,0,0,0)));
    const int switchHCWidth = greenStuff.height()/2;
    paint.drawRect(switchHCWidth,0,greenStuff.width()-switchHCWidth*2, greenStuff.height());
    paint.drawPie(0, 0, greenStuff.height(), greenStuff.height(), 90 * 16, 180 * 16);
    paint.drawPie(greenStuff.width()-greenStuff.height(), 0, greenStuff.height(), greenStuff.height(), -90 * 16, 180 * 16);
    monospace.setPointSize(40);
    paint.setFont(monospace);
    paint.setPen(QPen(QColor(255,255,255), 10));
    int tlx = isOn?tumblerMargin:greenStuff.height() - tumblerMargin;
    //int thx = isOn?greenStuff.width() - greenStuff.height():greenStuff.width();
    paint.drawText(tlx, 0, tumblerMargin + greenStuff.width() - greenStuff.height(), greenStuff.height(), Qt::AlignHCenter | Qt::AlignCenter, isOn?"ON":"OFF");
}

void SwitcherWidget::drawTumbler(QPainter& paint)
{
    paint.setPen(QPen(QColor(0,0,0,0)));
    whiteStuff.setRect(px + tumblerMargin,tumblerMargin, greenStuff.height() - tumblerMargin*2, greenStuff.height() - tumblerMargin*2);
    paint.setBrush(tumblerBrush);
    paint.drawEllipse(whiteStuff);
}

void SwitcherWidget::paintEvent(QPaintEvent * event){
    greenStuff.setRect(0,0,width(),height());
//    greenStuff.setWidth(width());
//    greenStuff.setHeight(height());

    QPainter paint(this);

    //paint.translate(greenStuff.x(), greenStuff.y());
    drawBackground(paint);
    drawTumbler(paint);
    event->accept();
}

void SwitcherWidget::flip(){
    ani.clear();
    QPropertyAnimation* slideAnimation = new QPropertyAnimation(this,"positionX",&ani);
    QPropertyAnimation* fadeAnimation= new QPropertyAnimation(this,"color", &ani);
    slideAnimation->setEasingCurve(QEasingCurve(QEasingCurve::Linear));
    fadeAnimation->setEasingCurve(QEasingCurve(QEasingCurve::Linear));
    slideAnimation->setDuration(1000);
    fadeAnimation->setDuration(1000);
    if(!isOn){
        fadeAnimation->setStartValue(offColor);
        fadeAnimation->setEndValue(onColor);
        slideAnimation->setStartValue(0);
        slideAnimation->setEndValue(greenStuff.width() - greenStuff.height());
    }else{
        fadeAnimation->setStartValue(onColor);
        fadeAnimation->setEndValue(offColor);
        slideAnimation->setStartValue(greenStuff.width() - greenStuff.height());
        slideAnimation->setEndValue(0);
    }
    isOn = !isOn;
    setOn(isOn);
    ani.start();
}

void SwitcherWidget::mousePressEvent ( QMouseEvent * event ) {
	flip();
    event->accept();
}

void SwitcherWidget::setPX(int p){
    px = p;
    repaint();
}

int SwitcherWidget::getPX(){
    return px;
}

void SwitcherWidget::setColor(QColor v){
    c = v;
    repaint();
}

QColor SwitcherWidget::getColor(){
    return c;
}

void SwitcherWidget::resizeEvent(QResizeEvent *){
    if(isOn)
        setPX(greenStuff.width() - greenStuff.height());
}
