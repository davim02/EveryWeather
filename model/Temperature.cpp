#include "Temperature.h"

Temperature::Temperature(
    const std::string city,
    const std::string country
    ): Sensor(city, country) {

        simulate();
}

std::vector<int> Temperature::getMinTemp() const {
    return temp_min;
}

std::vector<int> Temperature::getMaxTemp() const {
    return temp_max;
}

void Temperature::simulate() {
    int temp;
    temp_max.clear();
    temp_min.clear();
    for (int i = 0; i < 12; i++) {
        temp = (rand() % 30);
        temp_min.push_back(temp - 15);
        temp_max.push_back(temp + 15);
    }
}

void Temperature::accept(SensorVisitorInterface& visitor) {
    visitor.visitTemperature(*this);
}
