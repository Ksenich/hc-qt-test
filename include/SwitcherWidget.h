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
    void drawBackground(QPainter&);
    void drawTumbler(QPainter&);

signals:
    void setOn(bool);

protected:
    virtual void paintEvent(QPaintEvent * event);
	virtual void mousePressEvent ( QMouseEvent * event ); 
    virtual void resizeEvent(QResizeEvent *);
private:
    bool isOn;
    
    //Viewdetails------------------------
    int tumblerMargin, px;
    QBrush backgroundBrush, tumblerBrush;
    static QColor onColor, offColor;
    QRect greenStuff;
    QRect whiteStuff;
    void setPX(int);
    int getPX();
    void setColor(QColor);
    QColor getColor();
    QColor c;
    QParallelAnimationGroup ani;
    QFont monospace;
};
