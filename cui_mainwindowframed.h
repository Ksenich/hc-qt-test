#ifndef CUI_MAINWINDOWFRAMED_H
#define CUI_MAINWINDOWFRAMED_H
#include <QWidget>
#include "SwitcherWidget.h"

class CUI_MainWindowFramed
{
public:
    CUI_MainWindowFramed();
    void setupUi(QWidget* cw);
    SwitcherWidget *sw;
};

#endif // CUI_MAINWINDOWFRAMED_H
