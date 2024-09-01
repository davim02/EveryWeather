#ifndef UVSIM_H
#define UVSIM_H

#include "../../model/UV.h"
#include <vector>

class UVSim {

private:
    const UV& uv;
    std::vector<unsigned int> indexes;

public:
    UVSim(const UV& uv);
    const std::vector<unsigned int>& getData() const;
    void simulate();
};

#endif
