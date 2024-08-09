#ifndef RAINFALLSIM_H
#define RAINFALLSIM_H

#include <vector>

class RainfallSim {

private:
    std::vector<double> millimeters;

public:
    RainfallSim();
    void simulate_rand();
    const std::vector<double>& getData() const;
};

#endif // RAINFALLSIM_H
