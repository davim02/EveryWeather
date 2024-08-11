#ifndef SENSOR_GRAPH_WIDGET_H
#define SENSOR_GRAPH_WIDGET_H

#include <QWidget>
#include <QChartView>
#include "../../model/Sensor.h"

class SensorGraphWidget: public QWidget {
    Q_OBJECT

  private:
    Sensor* sensor;
    QChartView* chart_view;
    QWidget* sensor_info;

  public:
    SensorGraphWidget(QWidget* parent = 0);

  public slots:
    void simulateSensor();
    void setGraph(const Sensor* sensor);
    void setSensorInfo(const Sensor* sensor);

};

#endif
