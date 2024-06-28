#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

class Temperature: public Sensor {
    private:
        std::vector<int> temp_min;
        std::vector<int> temp_max;

    public:
        Temperature(
            const std::string city,
            const std::string country
        );

        std::vector<int> getMinTemp() const;
        std::vector<int> getMaxTemp() const;
        virtual void simulate();
        virtual void accept(SensorVisitorInterface& visitor);
};


#endif