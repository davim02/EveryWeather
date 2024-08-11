#ifndef TEMPERATUREGRAPH_H
#define TEMPERATUREGRAPH_H

#include "../../model/Temperature.h"
#include <QChart>

class TemperatureGraph : public QChart {

private:
    const Temperature& temperature;
    const std::vector<int>& min_temp;
    const std::vector<int>& max_temp;

public:
    TemperatureGraph(const Temperature& temperature);
};

#endif // TEMPERATUREGRAPH_H
