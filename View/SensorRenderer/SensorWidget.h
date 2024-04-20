#ifndef VIEW_SENSOR_RENDERER_SENSOR_WIDGET_H
#define VIEW_SENSOR_RENDERER_SENSOR_WIDGET_H

#include <QPushButton>
#include <QLabel>
#include "../../model/Sensor.h"

class SensorWidget: public QPushButton {
    Q_OBJECT
  private:
    Sensor& sensor;
    QLabel* city_label;
    QLabel* country_label;
    QLabel* type_label;
    QLabel* icon;

  public:
    SensorWidget(Sensor& sensor, QWidget* parent = 0);
    virtual void show() = 0;
};

#endif