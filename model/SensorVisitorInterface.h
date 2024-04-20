#ifndef SENSOR_VISITOR_INTERFACE_H
#define SENSOR_VISITOR_INTERFACE_H

      
class Temperature;
class UV;
class Rainfall;
class Humidity;

class SensorVisitorInterface {
  public:
    virtual ~SensorVisitorInterface() = default;
    virtual void visitTemperature(Temperature& temperature) = 0;
    virtual void visitUV(UV& uv) = 0;
    virtual void visitRainfall(Rainfall& rainfall) = 0;
    virtual void visitHumidity(Humidity& humidity) = 0;
};

#endif

