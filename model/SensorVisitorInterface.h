#ifndef SENSOR_VISITOR_INTERFACE_H
#define SENSOR_VISITOR_INTERFACE_H

class Temperature;
class UV;
class Rainfall;
class Humidity;

class SensorVisitorInterface {
  public:
    virtual ~SensorVisitorInterface() = default;
    virtual void visit(Temperature& temperature) = 0;
    virtual void visit(UV& uv) = 0;
    virtual void visit(Rainfall& rainfall) = 0;
    virtual void visit(Humidity& humidity) = 0;
};

#endif

