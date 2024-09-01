#ifndef RAINFALLSIM_H
#define RAINFALLSIM_H

#include "../../model/Rainfall.h"
#include <vector>

class RainfallSim {

private:
    const Rainfall& rainfall;
    std::vector<double> quantities;

public:
    RainfallSim(const Rainfall& rainfall);
    const std::vector<double>& getData() const;
    void simulate();
};

#endif
