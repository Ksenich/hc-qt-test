#ifndef CUI_MAINWINDOWFRAMELESS_H
#define CUI_MAINWINDOWFRAMELESS_H
#include <QWidget>
#include "SwitcherWidget.h"

class CUI_MainWindowFrameless
{
public:
    CUI_MainWindowFrameless();
    void setupUi(QWidget* cw);
    SwitcherWidget *sw;
};

#endif // CUI_MAINWINDOWFRAMELESS_H
