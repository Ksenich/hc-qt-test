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
    virtual void paintEvent(QPaintEvent * event);
	virtual void mousePressEvent ( QMouseEvent * event ); 
    virtual void resizeEvent(QResizeEvent *);
private:
    bool isOn;
    
    //Viewdetails------------------------
    int knobMargin, px;
    QBrush baseBrush, knobBrush;
    static QColor onColor, offColor;
    QRect base;
    QRect knob;
    void setPX(int);
    int getPX();
    void setColor(QColor);
    QColor getColor();
    QColor baseColor;
    QParallelAnimationGroup ani;
    QFont fontUsed;
};

#endif
