#ifndef RAINFALLGRAPH_H
#define RAINFALLGRAPH_H

#include <QChart>
#include "../../model/Rainfall.h"

class RainfallGraph : public QChart
{
    Q_OBJECT

private:
    Rainfall& rainfall;

public:
    RainfallGraph(Rainfall& rainfall, QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
};

#endif // RAINFALLGRAPH_H
