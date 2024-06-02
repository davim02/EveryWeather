#ifndef SENSOR_GRAPH_H
#define SENSOR_GRAPH_H

#include <QtCharts>
#include "../model/SensorVisitorInterface.h"

class SensorGraph: public QChart {
  private:
    QChartView* chart_view;
    QLineSeries* series;
    QValueAxis* axis_x;
    QValueAxis* axis_y;
    QScatterSeries* scatter_series;

  public:
    SensorGraph();
    void updateGraph(Sensor& sensor);
    void clearGraph();
};

#endif