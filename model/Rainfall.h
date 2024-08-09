#ifndef RAINFALL_H
#define RAINFALL_H

#include "Sensor.h"

class Rainfall: public Sensor {
    private:
        bool is_inches;
        
    public:
        Rainfall(
            const unsigned int id,
            const std::string city,
            const std::string country,
            bool is_inches
        );

        bool isInches() const;
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};



#endif
