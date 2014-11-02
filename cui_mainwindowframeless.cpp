#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "SwitcherWidget.h"
#include "cui_header.h"
#include "cui_mainwindowframeless.h"
#include "cui_mainwindowframed.h"

CUI_MainWindowFrameless::CUI_MainWindowFrameless()
{
}

void CUI_MainWindowFrameless::setupUi(QWidget* mw){
    QWidget *cw = new QWidget(mw);

    QVBoxLayout *vl = new QVBoxLayout(cw);
    QWidget * wh = new QWidget(cw);
    CUI_Header head;
    head.setupUi(wh);
    QWidget * vw = new QWidget(cw);
    CUI_MainWindowFramed mwf;
    mwf.setupUi(vw);
    sw = mwf.sw;
    vl->addWidget(wh);
    vl->addWidget(vw, 1);
    cw->setLayout(vl);

    mw->setAttribute(Qt::WA_TranslucentBackground);
    cw->setAutoFillBackground(true);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(cw);
    effect->setBlurRadius(50);
    effect->setOffset(0,0);
    cw->setGraphicsEffect(effect);

    QVBoxLayout *v2 = new QVBoxLayout(mw);
    v2->setContentsMargins(30,30,30,30);
    v2->addWidget(cw);
    mw->resize(640,480);
}
