#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include <QWidget>

namespace Ui {
class FramelessWindow;
}

class FramelessWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FramelessWindow(QWidget *parent = 0);
    ~FramelessWindow();
    void setBody(QWidget* w);
    QSize visibleGeometry();
    virtual void resize(int w, int h);
private:
    Ui::FramelessWindow *ui;
    int invFW();
    int invFH();
};

#endif // FRAMELESSWINDOW_H
