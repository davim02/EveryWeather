#ifndef TEMPERATURESIM_H
#define TEMPERATURESIM_H

#include <vector>

class TemperatureSim {

private:
    std::vector<int> temp_min;
    std::vector<int> temp_max;

public:
    TemperatureSim();
    const std::vector<int>& getMinTemp() const;
    const std::vector<int>& getMaxTemp() const;
    void simulateTemperature();

};

#endif // TEMPERATURESIM_H