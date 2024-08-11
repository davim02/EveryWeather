#ifndef SENSOR_GRAPH_WIDGET_VISITOR_H
#define SENSOR_GRAPH_WIDGET_VISITOR_H

#include "SensorGraphWidget.h"
#include "../../model/SensorVisitorConstInterface.h"


class SensorGraphWidgetVisitor: public SensorVisitorConstInterface {
  private:
    QChart* chart;

  public:
    QChart* getChart() const;
    virtual void visit(const Temperature& temperature);
    virtual void visit(const Humidity& humidity);
    virtual void visit(const Rainfall& rainfall);
    virtual void visit(const UV& uv);
};

#endif
