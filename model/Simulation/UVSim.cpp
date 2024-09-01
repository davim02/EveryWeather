#include "UVSim.h"
#include <cstdlib>

UVSim::UVSim(const UV& uv) : uv(uv) {
    indexes = std::vector<unsigned int>();
    simulate();
}

const std::vector<unsigned int>& UVSim::getData() const {
    return indexes;
}

void UVSim::simulate() {
    indexes.clear();
    for (int i = 0; i < 12; i++) {
        indexes.push_back(rand() % 13);
    }
}
