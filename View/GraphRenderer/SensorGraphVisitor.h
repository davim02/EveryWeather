#ifndef SENSOR_GRAPH_VISITOR_H
#define SENSOR_GRAPH_VISITOR_H

#include <QChart>
#include "../../model/SensorVisitorInterface.h"


class SensorGraphVisitor: public SensorVisitorInterface {
  private:
    QChart* chart;

  public:
    QChart* getChart();
    virtual void visitTemperature(Temperature& temperature);
    virtual void visitHumidity(Humidity& humidity);
    virtual void visitRainfall(Rainfall& rainfall);
    virtual void visitUV(UV& uv);
};

#endif
