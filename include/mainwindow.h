#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "centralwidget.h"
#include "framelesswindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

private slots:
    void setFrameless(bool);
    void moveBy(int x, int y);
    void resizeBy(QRect);

private:
    CentralWidget* cw;
    FramelessWindow* fw;
    SwitcherWidget* switcher;
    HeaderWidget* header;
};

#endif // MAINWINDOW_H
