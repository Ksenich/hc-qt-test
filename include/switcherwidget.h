#ifndef SWITCHER_WIDGET
#define SWITCHER_WIDGET

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QBrush>
#include <QRect>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QFont>

class SwitcherWidget : public QWidget{
    Q_OBJECT
    //couldn't make it work with doubles
    Q_PROPERTY(int positionX READ getPX WRITE setPX)
    Q_PROPERTY(QColor color READ getColor WRITE setColor)
public:
    SwitcherWidget(QWidget * parent = 0);
    void flip();
    void drawBase(QPainter&);
    void drawKnob(QPainter&);

public slots:
    void startAnimation();

signals:
    void switched(bool);

protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent ( QMouseEvent * event );
private:
    bool isOn;
    
    //Viewdetails------------------------
    void scalePainter(QPainter& p);
    int knobMargin, px;
    QBrush baseBrush, knobBrush;
    static QColor onColor, offColor;
    QRect base;
    QRect knob;
    void setPX(double);
    double getPX();
    void setColor(QColor);
    QColor getColor();
    QColor baseColor;
    QParallelAnimationGroup ani;
    QFont fontUsed;
};

#endif
