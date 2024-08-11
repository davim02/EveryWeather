#ifndef HUMIDITYSIM_H
#define HUMIDITYSIM_H

#include "../../model/Humidity.h"
#include <vector>

class HumiditySim {

private:
    const Humidity& humidity;
    std::vector<int> percentages;

public:
    HumiditySim(const Humidity& humidity);
    const std::vector<int>& getData() const;
    void simulateHumidity();
};

#endif // HUMIDITYSIM_H
