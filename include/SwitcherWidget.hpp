#include <QWidget>
#include <QPaintEvent>

class SwitcherWidget : public QWidget{
public:
    SwitcherWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
protected:
    virtual void paintEvent(QPaintEvent * event);
private:
    bool m_isOn;
}