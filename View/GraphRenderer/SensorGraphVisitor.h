#ifndef SENSOR_GRAPH_VISITOR_H
#define SENSOR_GRAPH_VISITOR_H

#include <QChart>
#include "../../model/SensorVisitorConstInterface.h"


class SensorGraphVisitor: public SensorVisitorConstInterface {
  private:
    QChart* chart;

  public:
    SensorGraphVisitor();
    QChart* getChart() const;
    virtual void visit(const Temperature& temperature);
    virtual void visit(const Humidity& humidity);
    virtual void visit(const Rainfall& rainfall);
    virtual void visit(const UV& uv);
};

#endif
