#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include <QWidget>
#include "header.h"
#include "resizableframe.h"

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
    int width() const;
    int height() const;
    HeaderWidget *getHeader();
    ResizableFrame *getFrame();
private:
    Ui::FramelessWindow *ui;
    int invFW() const;
    int invFH() const;
private slots:
    void maximise();
    void restore();

};

#endif // FRAMELESSWINDOW_H
