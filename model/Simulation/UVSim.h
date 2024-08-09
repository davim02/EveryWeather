#ifndef UVSIM_H
#define UVSIM_H

#include <vector>

class UVSim {

private:
    std::vector<unsigned int> indexes;

public:
    UVSim();
    const std::vector<unsigned int>& getData() const;
    void simulateUV();
};

#endif // UVSIM_H
