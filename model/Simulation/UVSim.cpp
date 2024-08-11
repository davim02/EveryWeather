#include "UVSim.h"

UVSim::UVSim(const UV& uv) : uv(uv) {
    indexes = std::vector<unsigned int>();
    simulateUV();
}

const std::vector<unsigned int>& UVSim::getData() const {
    return indexes;
}

void UVSim::simulateUV() {
    indexes.clear();
    for (int i = 0; i < 12; i++) {
        indexes.push_back(rand() % 11);
    }
}