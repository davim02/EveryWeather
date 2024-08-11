#include "TemperatureSim.h"
#include <cstdlib>

TemperatureSim::TemperatureSim(const Temperature& temperature) : temperature(temperature) {
    temp_min = std::vector<int>();
    temp_max = std::vector<int>();
    simulateTemperature();
}

const std::vector<int>& TemperatureSim::getMinTemp() const {
    return temp_min;
}

const std::vector<int>& TemperatureSim::getMaxTemp() const {
    return temp_max;
}

void TemperatureSim::simulateTemperature() {
    int temp;
    temp_max.clear();
    temp_min.clear();
    for (int i = 0; i < 12; i++) {
        temp = (rand() % 30);
        if (temperature.isFahrenheit()) {
            temp = (temp * 9/5) + 32;
        }
        temp_min.push_back(temp - 15);
        temp_max.push_back(temp + 15);
    }
}
