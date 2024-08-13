#ifndef TEMPERATUREGRAPH_H
#define TEMPERATUREGRAPH_H

#include "../../model/Temperature.h"
#include <QChart>

class TemperatureGraph : public QChart {

private:
    const Temperature& temperature;

public:
    TemperatureGraph(const Temperature& temperature);
};

#endif // TEMPERATUREGRAPH_H
