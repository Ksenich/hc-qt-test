#include "resizableframe.h"

#include <QDebug>

ResizableFrame::ResizableFrame(QWidget *parent) :
    QFrame(parent)
{
    setMouseTracking(true);
}

ResizableFrame::~ResizableFrame()
{
}

void ResizableFrame::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
    }
}

void ResizableFrame::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton)) {

        if (event->x() <= 3 && event->y() <= 3) {
            startPos = topleft;
            setCursor(Qt::SizeFDiagCursor);
        } else if (event->x() <= 3 && event->y() >= height() - 3) {
            startPos = bottomleft;
            setCursor(Qt::SizeBDiagCursor);
        } else if (event->x() >= width() - 3 && event->y() <= 3) {
            startPos = topright;
            setCursor(Qt::SizeBDiagCursor);
        } else if (event->x() >= width() - 3 && event->y() >= height() - 3) {
            startPos = bottomright;
            setCursor(Qt::SizeFDiagCursor);
        } else if (event->x() <= 3) {
            startPos = left;
            setCursor(Qt::SizeHorCursor);
        } else if (event->x() >= width() - 3) {
            startPos = right;
            setCursor(Qt::SizeHorCursor);
        } else if (event->y() <= 3) {
            startPos = top;
            setCursor(Qt::SizeVerCursor);
        } else if (event->y() >= height() - 3) {
            startPos = bottom;
            setCursor(Qt::SizeVerCursor);
        }else{
            setCursor(Qt::ArrowCursor);
        }
        return;
    }

    switch (startPos) {
    case topleft:
        resized(QRect(- (dragStartPosition.x() - event->x()),
                      - (dragStartPosition.y() - event->y()),
                        dragStartPosition.x() - event->x(),
                        0));
        break;

    case bottomleft:
        resized(QRect( - (dragStartPosition.x() - event->x()),
                    0,
                    dragStartPosition.x() - event->x(),
                    -(dragStartPosition.y() - event->y())));
        break;

    case topright:
        resized(QRect(0,
                    - (dragStartPosition.y() - event->y()),
                    -(dragStartPosition.x() - event->x()),
                    0));
        break;

    case bottomright:
        resized(QRect(0,
                    0,
                    -(dragStartPosition.x() - event->x()),
                    -(dragStartPosition.y() - event->y())));
        break;

    case left:
        resized(QRect( - (dragStartPosition.x() - event->x()),
                    0,
                    dragStartPosition.x() - event->x(),
                    0));
        break;

    case right:
        resized(QRect(0,
                    0,
                    -(dragStartPosition.x() - event->x()),
                    0));
        break;

    case top:
        resized(QRect(0,
                     - (dragStartPosition.y() - event->y()),
                    0,
                    0));
        break;

    case bottom:
        resized(QRect(0,
                    0,
                    0,
                    -(dragStartPosition.y() - event->y())));
        break;

    default:
        break;
    }
    dragStartPosition = event->pos();
}

void ResizableFrame::mouseReleaseEvent(QMouseEvent *)
{
    setCursor(Qt::ArrowCursor);
}
