#ifndef UVGRAPH_H
#define UVGRAPH_H

#include "../../model/UV.h"
#include <QChart>

class UVGraph : public QChart {

private:
    const UV& uv;

public:
    UVGraph(const UV& uv);
};

#endif // UVGRAPH_H
