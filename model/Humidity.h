#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

class Humidity: public Sensor {
    
    public:
        Humidity(
            const unsigned int id,
            const std::string city,
            const std::string country
        );
        
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};

#endif
