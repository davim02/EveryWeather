#include "Rainfall.h"

Rainfall::Rainfall(
    const std::string city,
    const std::string country
): Sensor(city, country) {

    simulate();
}

const std::vector<double>& Rainfall::getData() const {
    return millimeters;
}

void Rainfall::simulate() {
    millimeters.clear();
    for (int i = 0; i < 12; i++) {
        millimeters.push_back((rand() % 100) / 10.0);
    }
}

void Rainfall::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void Rainfall::accept(SensorVisitorConstInterface& visitor) const {
    visitor.visit(*this);
}
