#ifndef SENSOR_GRAPH_H
#define SENSOR_GRAPH_H

#include <QWidget>
#include <QChartView>
#include "../../model/Sensor.h"

class SensorGraph: public QWidget {
    Q_OBJECT

  private:  
    QChartView *chart_view;

  public:
    SensorGraph(QWidget* parent = 0);

  public slots:
    void setGraphSensor(Sensor& sensor);

};

#endif
