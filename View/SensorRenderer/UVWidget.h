#ifndef UVWIDGET_H
#define UVWIDGET_H

#include "SensorWidget.h"
#include <QLabel>

class UVWidget: public SensorWidget {

    private:
        QLabel* icon;
        QLabel* label;

    public:
        UVWidget(QWidget* parent = 0);
        virtual ~UVWidget();

};

#endif