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
private:
    Ui::CentralWidget *ui;
   // FramelessWindow *fw;
private slots:
    void setFrameless(bool);
};

#endif // CENTRALWIDGET_H
