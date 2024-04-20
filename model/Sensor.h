#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include "SensorVisitorInterface.h"

class Sensor {
    private:
        std::string city;
        std::string country;
    public:
        Sensor(
            const std::string city,
            const std::string country
        );

        virtual ~Sensor();

        const std::string& getCity() const;
        const std::string& getCountry() const;
        void setCity(const std::string city);
        void setCountry(const std::string country);
        virtual void simulate() = 0;
        virtual void accept(SensorVisitorInterface& visitor) = 0;
        
};

#endif
