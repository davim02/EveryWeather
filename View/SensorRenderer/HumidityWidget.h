#ifndef HUMIDITYWIDGET_H
#define HUMIDITYWIDGET_H

#include "SensorWidget.h"

class HumidityWidget: public SensorWidget {

    private:
        QLabel* icon;
        QLabel* label;

    public:
        HumidityWidget(QWidget* parent = 0);
        virtual ~HumidityWidget();

};

#endif