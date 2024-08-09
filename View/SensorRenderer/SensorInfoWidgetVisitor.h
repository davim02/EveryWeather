#ifndef SENSORINFOWIDGETVISITOR_H
#define SENSORINFOWIDGETVISITOR_H

#include <QWidget>
#include "../../model/SensorVisitorConstInterface.h"

class SensorInfoWidgetVisitor : public SensorVisitorConstInterface {

private:
    QWidget* widget;

public:
    QWidget* getWidget();
    virtual void visit(const Temperature& temperature);
    virtual void visit(const UV& uv);
    virtual void visit(const Rainfall& rainfall);
    virtual void visit(const Humidity& humidity);
};

#endif // SENSORINFOWIDGETVISITOR_H
