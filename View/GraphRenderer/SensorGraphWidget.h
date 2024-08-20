#ifndef SENSOR_GRAPH_WIDGET_H
#define SENSOR_GRAPH_WIDGET_H

#include <QWidget>
#include <QChartView>
#include <QPushButton>
#include <QVBoxLayout>

#include "../../model/Sensor.h"
#include "../../View/SensorRenderer/SensorInfoWidget.h"

class SensorGraphWidget: public QWidget {
    Q_OBJECT

  private:
    const Sensor* sensor;
    QVBoxLayout* layout;
    QChartView* chart_view;
    SensorInfoWidget* sensor_info;
    QPushButton* button;
    bool isChartSet;
    void deleteInfoWidget();
    void deleteChart();
    void setChart();

  public:
    SensorGraphWidget(QWidget* parent = 0);
    const Sensor* getSensor() const;

  public slots:
    void simulateSensor();
    void setSensor(const Sensor* sensor);
    void reset();

};

#endif
