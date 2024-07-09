#include "temperaturegraph.h"
#include <QBarSet>
#include <QBarSeries>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>


TemperatureGraph::TemperatureGraph(const Temperature& temperature, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags)
{


}
