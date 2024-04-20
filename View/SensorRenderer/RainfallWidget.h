#ifndef RAINFALLWIDGET_H
#define RAINFALLWIDGET_H

#include "SensorWidget.h"
#include <QLabel>

class RainfallWidget: public SensorWidget {

    private:
        QLabel* icon;
        QLabel* label;

    public:
        RainfallWidget(QWidget* parent = 0);
        virtual ~RainfallWidget();

};

#endif
