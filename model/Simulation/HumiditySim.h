#ifndef HUMIDITYSIM_H
#define HUMIDITYSIM_H

#include <vector>

class HumiditySim {

private:
    std::vector<int> percentages;

public:
    HumiditySim();
    const std::vector<int>& getData() const;
    void simulateHumidity();
};

#endif // HUMIDITYSIM_H
