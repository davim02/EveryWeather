#ifndef TEMPERATUREWIDGET_H
#define TEMPERATUREWIDGET_H

#include "SensorWidget.h"
#include <QLabel>

class TemperatureWidget: public SensorWidget {

    private:
        QLabel* icon;
        QLabel* label;

    public:
        TemperatureWidget(SensorWidget& sensor_widget, QWidget* parent = 0);
        virtual ~TemperatureWidget();

};

#endif

