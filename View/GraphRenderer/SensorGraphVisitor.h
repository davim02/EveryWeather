#ifndef SENSOR_GRAPH_VISITOR_H
#define SENSOR_GRAPH_VISITOR_H

#include <QtCharts>
#include "../model/SensorVisitorInterface.h"


class SensorGraphVisitor: public SensorVisitorInterface {
  private:
    QWidget* widget;

  public:
    QWidget* getWidget();
    virtual void visitTemperature(Temperature& temperature);
    virtual void visitHumidity(Humidity& humidity);
    virtual void visitRainfall(Rainfall& rainfall);
    virtual void VisitUV(UV& uv);
};

#endif