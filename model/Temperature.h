#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

class Temperature: public Sensor {
    private:
        std::vector<int> temp_min;
        std::vector<int> temp_max;

        bool is_fahrenheit;

    public:
        Temperature(
            const unsigned int id,
            const std::string city,
            const std::string country
        );

        std::vector<int> getMinTemp() const;
        std::vector<int> getMaxTemp() const;
        bool isFahrenheit() const;
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};


#endif
