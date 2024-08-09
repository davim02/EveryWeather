#include "UVSim.h"

UVSim::UVSim() {
    indexes = std::vector<unsigned int>();
    simulateUV();
}

const std::vector<unsigned int>& UVSim::getData() const {
    return indexes;
}

void UVSim::simulateUV() {
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