#include "Temperature.h"

Temperature::Temperature(
    const std::string city,
    const std::string country
    ): Sensor(city, country) {

        simulate();
}

std::vector<int> Temperature::getData() const {
    return temperature;
}

void Temperature::simulate() {
    temperature.clear();
    for (int i = 0; i < 12; i++) {
        temperature.push_back((rand() % 50) - 15);
    }
}

void Temperature::accept(SensorVisitorInterface& visitor) {
    visitor.visitTemperature(*this);
}
