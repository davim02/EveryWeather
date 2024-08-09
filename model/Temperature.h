#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

class Temperature: public Sensor {
    private:
        bool is_fahrenheit;

    public:
        Temperature(
            const unsigned int id,
            const std::string city,
            const std::string country,
            bool is_fahrenheit
        );
        
        bool isFahrenheit() const;
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};


#endif
