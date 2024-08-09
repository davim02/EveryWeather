#ifndef UV_H
#define UV_H

#include "Sensor.h"

class UV: public Sensor {

    public:
        UV(
            const unsigned int id,
            const std::string city,
            const std::string country
        );
        
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};


#endif
