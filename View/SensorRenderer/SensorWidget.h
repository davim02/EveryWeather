#ifndef VIEW_SENSOR_RENDERER_SENSOR_WIDGET_H
#define VIEW_SENSOR_RENDERER_SENSOR_WIDGET_H

#include <QPushButton>
#include <QLabel>
#include <QEvent>
#include "../../model/Sensor.h"

class SensorWidget: public QPushButton {
    Q_OBJECT

  private:
    const Sensor& sensor;
    QLabel* city_label;
    QLabel* country_label;
    QPushButton* edit_button;
    QPushButton* delete_button;
  
  protected:
    virtual bool event(QEvent* e);

  public:
    SensorWidget(const Sensor& sensor, QWidget* parent = 0);

  signals:
    void edit(const Sensor* sensor);
    void remove(const unsigned int sensor_id);
};

#endif
