#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

class Humidity: public Sensor {
    private:
        std::vector<int> percentages;

    public:
        Humidity(
            const std::string city,
            const std::string country
        );

        const std::vector<int>& getData() const;
        virtual void simulate();
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};

#endif
