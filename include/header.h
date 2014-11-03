#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QPoint>

namespace Ui {
class header;
}

class HeaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderWidget(QWidget *parent = 0);
    ~HeaderWidget();

    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void closeClicked();
    void minimizeClicked();
    void maximizeClicked();
    void restoreClicked();
    void dragged(int,int);

private:
    Ui::header *ui;
    bool maximized;
    QPoint m_dragPosition;
private slots:
    void onMaximizeClicked();
};

#endif // HEADER_H
