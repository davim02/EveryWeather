#include "uvgraph.h"
#include <QLineSeries>

UVGraph::UVGraph(UV& uv, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags),
    uv(uv)
{

    auto series = new QLineSeries;

    auto data = uv.getData();

    for(int i=0; i<12; i++) {
        series->append(++i, data[i]);
    }

    this->legend()->hide();
    addSeries(series);
    createDefaultAxes();
    setTitle("UV levels");
}
