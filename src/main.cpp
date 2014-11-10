#include <QApplication>
#include <QSettings>
#include <QString>
#include <QColor>

#include "header.h"
#include "framelesswindow.h"
#include "centralwidget.h"
#include "mainwindow.h"

QString orgName("Jobless corps");
QString prodName("hc-qt-test");
void setDefaultSettings(QSettings &s);

int main(int argc, char** argv){
    QApplication app(argc, argv);
    QSettings settings(orgName, prodName);
    setDefaultSettings(settings);
    MainWindow mw;
    mw.show();
    app.exec();
    return 0;
}

void setDefaultSettings(QSettings &settings){
    settings.setValue("switcher/knobMargin", 10);
    settings.setValue("switcher/animationLength", 100);
    settings.setValue("switcher/base/onColor", QColor(0,0,0));
    settings.setValue("switcher/base/offColor", QColor(0,0,0));
    settings.setValue("switcher/base/textColor", QColor(0,0,0));
    settings.setValue("switcher/knobColor", QColor(0,0,0));
    settings.setValue("fw/headHeight", 32);
    settings.setValue("header/bgColor", QColor(252, 250, 247));
    settings.setValue("widget/textColor", QColor(204,204,204));
    settings.setValue("widget/bgColor", QColor(255,255,255));
}
