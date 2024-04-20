#ifndef RAINFALL_H
#define RAINFALL_H

#include "Sensor.h"

class Rainfall: public Sensor {
    private:
        std::vector<double> millimeters;

    public:
        Rainfall(
            const std::string city,
            const std::string country
        );

        const std::vector<double>& getData() const;
        virtual void simulate();
        virtual void accept(SensorVisitorInterface& visitor);
};



#endif