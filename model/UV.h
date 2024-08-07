#ifndef UV_H
#define UV_H

#include "Sensor.h"

class UV: public Sensor {
    private:
        std::vector<unsigned int> indexes;

    public:
        UV(
            const std::string city,
            const std::string country
        );

        std::vector<unsigned int> getData() const;
        
        virtual void accept(SensorVisitorInterface& visitor);
        virtual void accept(SensorVisitorConstInterface& visitor) const;
};


#endif
