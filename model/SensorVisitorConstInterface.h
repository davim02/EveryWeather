#ifndef SENSORVISITORCONSTINTERFACE_H
#define SENSORVISITORCONSTINTERFACE_H

class Temperature;
class UV;
class Rainfall;
class Humidity;

class SensorVisitorConstInterface {
public:
    virtual ~SensorVisitorConstInterface() = default;
    virtual void visit(const Temperature& temperature) = 0;
    virtual void visit(const UV& uv) = 0;
    virtual void visit(const Rainfall& rainfall) = 0;
    virtual void visit(const Humidity& humidity) = 0;
};

#endif // SENSORVISITORCONSTINTERFACE_H
