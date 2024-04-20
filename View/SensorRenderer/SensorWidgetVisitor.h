#ifndef SENSOR_WIDGET_VISITOR_H
#define SENSOR_WIDGET_VISITOR_H

#include <QWidget>
#include "../../model/SensorVisitorInterface.h"


class SensorWidgetVisitor: public SensorVisitorInterface {
  private:
    QWidget* widget;

  public:
    QWidget* getWidget();
    virtual void visitTemperature(Temperature& temperature);
    virtual void visitHumidity(Humidity& humidity);
    virtual void visitRainfall(Rainfall& rainfall);
    virtual void visitUV(UV& uv);
};

#endif