#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <Qt>
#include <QDebug>
#include <QEasingCurve>
#include <QFontDatabase>
#include <QSizePolicy>

#include "switcherwidget.h"

QColor SwitcherWidget::offColor(230, 222, 211);
QColor SwitcherWidget::onColor(146, 220, 92);

SwitcherWidget::SwitcherWidget(QWidget * parent):
        QWidget(parent/*, Qt::FramelessWindowHint*/)
{
    QString fontName(QLatin1String(":/font/AlternateGotNo3D.ttf"));
    int id = QFontDatabase::addApplicationFont(fontName);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    monospace = QFont(family);
    baseBrush.setStyle(Qt::SolidPattern);
    knobBrush.setStyle(Qt::SolidPattern);
    knobBrush.setColor(QColor(255,255,255));
    tumblerMargin = 30;
    px = 0;
    isOn = false;
    baseColor = offColor;
}

void SwitcherWidget::drawBase(QPainter& paint)
{
    baseBrush.setColor(baseColor);
    paint.setBrush(baseBrush);
    paint.setPen(QPen(QColor(0,0,0,0)));
    const int switchHCWidth = base.height()/2;
    paint.drawRect(switchHCWidth,0,base.width()-switchHCWidth*2, base.height());
    paint.drawPie(0, 0, base.height(), base.height(), 90 * 16, 180 * 16);
    paint.drawPie(base.width()-base.height(), 0, base.height(), base.height(), -90 * 16, 180 * 16);
    monospace.setPointSize(40);
    paint.setFont(monospace);
    paint.setPen(QPen(QColor(255,255,255), 10));
    //knob low x
    int klx = isOn?tumblerMargin:base.height() - tumblerMargin;
    //knob high x
    int khx = tumblerMargin + base.width() - base.height();
    paint.drawText(klx, 0, khx, base.height(), Qt::AlignHCenter | Qt::AlignCenter, isOn?"ON":"OFF");
}

void SwitcherWidget::drawKnob(QPainter& paint)
{
    paint.setPen(QPen(QColor(0,0,0,0)));
    knob.setRect(px + tumblerMargin,tumblerMargin, base.height() - tumblerMargin*2, base.height() - tumblerMargin*2);
    paint.setBrush(knobBrush);
    paint.drawEllipse(knob);
}

void SwitcherWidget::paintEvent(QPaintEvent * event){
    base.setRect(0,0,width(),height());
    QPainter paint(this);
    drawBase(paint);
    drawKnob(paint);
    event->accept();
}

void SwitcherWidget::flip(){
    isOn = !isOn;
    switched(isOn);
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
    baseColor = v;
    repaint();
}

QColor SwitcherWidget::getColor(){
    return baseColor;
}

void SwitcherWidget::resizeEvent(QResizeEvent *){
    if(isOn)
        setPX(base.width() - base.height());
}

void SwitcherWidget::startAnimation(){
    ani.clear();
    QPropertyAnimation* slideAnimation = new QPropertyAnimation(this,"positionX",&ani);
    QPropertyAnimation* fadeAnimation= new QPropertyAnimation(this,"color", &ani);
    slideAnimation->setEasingCurve(QEasingCurve(QEasingCurve::Linear));
    fadeAnimation->setEasingCurve(QEasingCurve(QEasingCurve::Linear));
    slideAnimation->setDuration(100);
    fadeAnimation->setDuration(100);
    if(isOn){
        fadeAnimation->setStartValue(offColor);
        fadeAnimation->setEndValue(onColor);
        slideAnimation->setStartValue(0);
        slideAnimation->setEndValue(base.width() - base.height());
    }else{
        fadeAnimation->setStartValue(onColor);
        fadeAnimation->setEndValue(offColor);
        slideAnimation->setStartValue(base.width() - base.height());
        slideAnimation->setEndValue(0);
    }
}
