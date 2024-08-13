#ifndef SENSOR_GRAPH_WIDGET_H
#define SENSOR_GRAPH_WIDGET_H

#include <QWidget>
#include <QChartView>
#include <QPushButton>
#include "../../model/Sensor.h"
#include "../../View/SensorRenderer/SensorInfoWidget.h"

class SensorGraphWidget: public QWidget {
    Q_OBJECT

  private:
    const Sensor* sensor;
    QChartView* chart_view;
    SensorInfoWidget* sensor_info;
    QPushButton* button;
    void setGraph();

  public:
    SensorGraphWidget(QWidget* parent = 0);

  public slots:
    void simulateSensor();
    void setSensor(const Sensor* sensor);

};

#endif
