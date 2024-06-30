#include "Humidity.h"

Humidity::Humidity(
    const std::string city, 
    const std::string country
) : Sensor(city, country) {

    simulate();
}

const std::vector<int>& Humidity::getData() const {
    return percentages;
}

void Humidity::simulate() {
   percentages.clear();
    for (int i = 0; i < 12; i++) {
        percentages.push_back((rand() % 100));
    }
}

void Humidity::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void Humidity::accept(SensorVisitorConstInterface &visitor) const {
    visitor.visit(*this);
}
