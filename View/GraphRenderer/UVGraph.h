#ifndef UVGRAPH_H
#define UVGRAPH_H

#include "../../model/UV.h"
#include <QChart>

class UVGraph : public QChart {

private:
    const UV& uv;
    const std::vector<unsigned int>& uv_values;

public:
    UVGraph(const UV& uv);
};

#endif // UVGRAPH_H
