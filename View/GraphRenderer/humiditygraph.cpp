#include "humiditygraph.h"


HumidityGraph::HumidityGraph(Humidity& humidity, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags),
    humidity(humidity)  
{


}
