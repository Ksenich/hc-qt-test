#include <QWidget>

class MainWidget: public QWidget{
public:
    MainWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
private:
public slots:
    void setBorderless(bool);
}