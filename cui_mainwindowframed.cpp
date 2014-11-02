#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "cui_mainwindowframed.h"

CUI_MainWindowFramed::CUI_MainWindowFramed()
{
}

void CUI_MainWindowFramed::setupUi(QWidget *cw){
    QVBoxLayout *vl = new QVBoxLayout(cw);
    sw = new SwitcherWidget(cw);
    sw->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLabel *label = new QLabel("push it", cw);
    label->setAlignment(Qt::AlignHCenter);
    vl->addWidget(sw,1);
    vl->addWidget(label);
    cw->setLayout(vl);
}
