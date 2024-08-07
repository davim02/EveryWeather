#ifndef RAINFALL_H
#define RAINFALL_H

#include "Sensor.h"

class Rainfall: public Sensor {
    private:
        std::vector<double> millimeters;
        bool is_inches;
    public:
        Rainfall(
            const unsigned int id,
            const std::string city,
            const std::string country
        );

        const std::vector<double>& getData() const;
        bool isInches() const;
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};



#endif
