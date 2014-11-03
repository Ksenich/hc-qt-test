#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

namespace Ui {
class header;
}

class HeaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderWidget(QWidget *parent = 0);
    ~HeaderWidget();

private:
    Ui::header *ui;
};

#endif // HEADER_H
