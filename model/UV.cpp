#include "UV.h"

UV::UV(
    const std::string city,
    const std::string country
): Sensor(city, country) {

    simulate();
}

std::vector<unsigned int> UV::getData() const {
    return indexes;
}

void UV::simulate() {
    indexes.push_back(1);
    indexes.push_back(2);
    indexes.push_back(3);
    indexes.push_back(4);
    indexes.push_back(5);
    indexes.push_back(6);
    indexes.push_back(7);
    indexes.push_back(8);
    indexes.push_back(9);
    indexes.push_back(10);
}

void UV::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void UV::accept(SensorVisitorConstInterface &visitor) const {
    visitor.visit(*this);
}
