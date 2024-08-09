#ifndef SENSOR_GRAPH_WIDGET_H
#define SENSOR_GRAPH_WIDGET_H

#include <QWidget>
#include <QChartView>
#include "../../model/Sensor.h"

class SensorGraphWidget: public QWidget {
    Q_OBJECT

  private:
    QChartView* chart_view;
    Sensor* sensor;

  public:
    SensorGraphWidget(QWidget* parent = 0);

  public slots:
    void simulateSensor();
    void setGraph(const Sensor* sensor);

};

#endif
