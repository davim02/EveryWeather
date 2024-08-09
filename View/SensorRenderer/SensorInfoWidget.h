#ifndef SENSORINFOWIDGET_H
#define SENSORINFOWIDGET_H

#include "../../model/Sensor.h"

#include <QLabel>
#include <QWidget>

class SensorInfoWidget : public QWidget {
    Q_OBJECT

private:
    const Sensor& sensor;
    QLabel* id_label;
    QLabel* city_label;
    QLabel* country_label;

public:
    explicit SensorInfoWidget(const Sensor& sensor, QWidget *parent = nullptr);

signals:
};

#endif // SENSORINFOWIDGET_H
