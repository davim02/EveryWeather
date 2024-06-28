#ifndef TEMPERATUREGRAPH_H
#define TEMPERATUREGRAPH_H

#include <QChart>
#include "../../model/Temperature.h"

class TemperatureGraph : public QChart
{
    Q_OBJECT

private:
    Temperature& temperature;

public:
    TemperatureGraph(Temperature& temperature, QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
};

#endif // TEMPERATUREGRAPH_H
