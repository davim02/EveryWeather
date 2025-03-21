#include "HumiditySim.h"
#include <cstdlib>

HumiditySim::HumiditySim(const Humidity& humidity) : humidity(humidity) {
    percentages = std::vector<int>();
    simulate();
}

const std::vector<int>& HumiditySim::getData() const {
    return percentages;
}

void HumiditySim::simulate() {
    int percentage;
    percentages.clear();
    for (int i = 0; i < 12; i++) {
        percentage = (rand() % 100);
        percentages.push_back(percentage);
    }
}
