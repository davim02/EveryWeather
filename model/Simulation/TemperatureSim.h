#ifndef TEMPERATURESIM_H
#define TEMPERATURESIM_H

#include "../../model/Temperature.h"
#include <vector>

class TemperatureSim {

private:
    const Temperature& temperature;
    std::vector<int> temp_min;
    std::vector<int> temp_max;

public:
    TemperatureSim(const Temperature& temperature);
    const std::vector<int>& getMinTemp() const;
    const std::vector<int>& getMaxTemp() const;
    void simulate();

};

#endif
