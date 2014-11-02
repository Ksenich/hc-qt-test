#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "cui_header.h"

CUI_Header::CUI_Header()
{
}

void CUI_Header::setupUi(QWidget* hw){
    QHBoxLayout * hl = new QHBoxLayout(hw);
    QLabel *il = new QLabel(hw);
    QLabel *tl = new QLabel("hello",hw);
    QPushButton *mb = new QPushButton(hw);
    QPushButton *Mb = new QPushButton(hw);
    QPushButton *cb = new QPushButton(hw);
    hl->addWidget(il);
    hl->addWidget(tl,1);
    hl->addWidget(mb);
    hl->addWidget(Mb);
    hl->addWidget(cb);
    hw->setLayout(hl);
}
