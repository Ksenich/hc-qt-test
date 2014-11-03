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

private:
    Ui::FramelessWindow *ui;
};

#endif // FRAMELESSWINDOW_H
