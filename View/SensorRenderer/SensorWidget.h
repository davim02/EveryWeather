#ifndef VIEW_SENSOR_RENDERER_SENSOR_WIDGET_H
#define VIEW_SENSOR_RENDERER_SENSOR_WIDGET_H

#include <QPushButton>
#include <QLabel>
#include "../../model/Sensor.h"
#include "SensorWidgetVisitor.h"

class SensorWidget: public QPushButton, public SensorWidgetVisitor {
    Q_OBJECT
  private:
    Sensor& sensor;
    QLabel* city_label;
    QLabel* country_label;

  public:
    SensorWidget(Sensor& sensor, QWidget* parent = 0);
};

#endif
