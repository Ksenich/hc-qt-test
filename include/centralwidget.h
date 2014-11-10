#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include "switcherwidget.h"
#include "framelesswindow.h"
namespace Ui {
class CentralWidget;
}

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();
    SwitcherWidget *getSwitcher();
private:
    Ui::CentralWidget *ui;

};

#endif // CENTRALWIDGET_H
