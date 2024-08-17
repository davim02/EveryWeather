#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include "SensorVisitorInterface.h"
#include "SensorVisitorConstInterface.h"

class Sensor {
    private:
        const unsigned int id;
        std::string city;
        std::string country;
    public:
        Sensor(
            const unsigned int id,
            const std::string city,
            const std::string country
        );

        virtual ~Sensor();
        unsigned int getId() const;
        const std::string& getCity() const;
        const std::string& getCountry() const;
        void setCity(const std::string city);
        void setCountry(const std::string country);
        
        virtual void accept(SensorVisitorInterface& visitor) = 0;
        virtual void accept(SensorVisitorConstInterface& visitor) const = 0;
};

#endif
