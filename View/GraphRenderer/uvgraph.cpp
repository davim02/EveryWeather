#include "uvgraph.h"
#include <QLineSeries>

UVGraph::UVGraph(UV& uv, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags),
    uv(uv)
{

}
