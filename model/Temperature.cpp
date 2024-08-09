#include "Temperature.h"

Temperature::Temperature(
    const unsigned int id,
    const std::string city,
    const std::string country,
    bool is_fahrenheit
    ): Sensor(id, city, country), is_fahrenheit(is_fahrenheit) {

}

bool Temperature::isFahrenheit() const {
    return is_fahrenheit;
}

void Temperature::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void Temperature::accept(SensorVisitorConstInterface &visitor) const {
    visitor.visit(*this);
}
