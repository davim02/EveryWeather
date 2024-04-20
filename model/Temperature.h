#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

class Temperature: public Sensor {
    private:
        std::vector<int> temperature;

    public:
        Temperature(
            const std::string city,
            const std::string country
        );

        std::vector<int> getData() const;
        virtual void simulate();
        virtual void accept(SensorVisitorInterface& visitor);
};


#endif