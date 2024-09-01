#include "RainfallSim.h"
#include <cstdlib>

RainfallSim::RainfallSim(const Rainfall& rainfall) : rainfall(rainfall) {
    quantities = std::vector<double>();
    simulate();
}

void RainfallSim::simulate() {
    quantities.clear();
    if (rainfall.isInches()) {
        for (int i = 0; i < 12; i++) {
            quantities.push_back((rand() % 5000) / 254.0);
        }
    } else {
        for (int i = 0; i < 12; i++) {
            quantities.push_back((rand() % 5000) / 10.0);
        }
    }  
    
}

const std::vector<double>& RainfallSim::getData() const {
    return quantities;
}
