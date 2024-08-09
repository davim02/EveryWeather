#include "Humidity.h"

Humidity::Humidity(
    const unsigned int id,
    const std::string city, 
    const std::string country
) : Sensor(id, city, country) {

}


void Humidity::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void Humidity::accept(SensorVisitorConstInterface &visitor) const {
    visitor.visit(*this);
}
