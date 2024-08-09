#include "RainfallSim.h"
#include <cstdlib>

RainfallSim::RainfallSim() {
    millimeters = std::vector<double>();
    simulate_rand();
}

void RainfallSim::simulate_rand() {
    millimeters.clear();
    for (int i = 0; i < 12; i++) {
        millimeters.push_back((rand() % 100) / 10.0);
    }
}

const std::vector<double>& RainfallSim::getData() const {
    return millimeters;
}
