#ifndef RAINFALLGRAPH_H
#define RAINFALLGRAPH_H

#include "../../model/Rainfall.h"
#include <QChart>

class RainfallGraph : public QChart {

private:
    const Rainfall& rainfall;
    const std::vector<double>& rainfall_quantities;
    
public:
    RainfallGraph(const Rainfall& rainfall);
};

#endif // RAINFALLGRAPH_H
