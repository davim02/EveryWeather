#include "rainfallgraph.h"


RainfallGraph::RainfallGraph(Rainfall& rainfall, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags),
    rainfall(rainfall)
{

}
