#include <QWidget>
#include <QPaintEvent>
#include <QBrush>

class SwitcherWidget : public QWidget{
    Q_OBJECT
    Q_PROPERTY(int position READ getTumblerPositionX WRITE setTumblerPositionX)
public:
    SwitcherWidget(QWidget * parent = 0);
    void flip();
protected:
    virtual void paintEvent(QPaintEvent * event);
private:
    bool isOn;
    
    //Viewdetails------------------------
    QBrush backgroundBrush, tumblerBrush;
    QColor onColor, offColor;
    int switchWidth, switchHeight;
    int switchPositionX, switchPositionY;
    int tumblerWidth, tumblerHeigth;
    int tumblerPositionY;
    int tumblerPositionX;
    static const int startPosition, endPosition;
    
    int getTumblerPositionX();
    void setTumblerPositionX(int p);
};
