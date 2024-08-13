#include "SensorsList.h"
#include "../View/SensorRenderer/SensorWidgetVisitor.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLayoutItem>
#include <functional>

SensorsList::SensorsList(QWidget *parent)
    : QWidget(parent)
{
    QWidget* container = new QWidget(this);
    vlayout = new QVBoxLayout(container);
    vlayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QScrollArea* scroll_area = new QScrollArea(this);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);

    
}

void SensorsList::clear() {
    QLayoutItem* child;
    while ((child = layout->takeAt(0)) != nullptr) {

        delete child->widget();
        delete child;
    }
}

void SensorsList::show() {
    clear();

    for (std::vector<Sensor*>::const_iterator it = sensors_list.begin();
         it != sensors_list.end();
         it++
        )
    {
        SensorWidget* sensor_widget = new SensorWidget(**it);
        vlayout->addWidget(sensor_widget);
        connect(sensor_widget, &SensorWidget::clicked, std::bind(&SensorsList::sensorSelected, this, *it));
        //connect(sensor_widget, &SensorWidget::clicked, [=](){ emit sensorSelected(*it); });
    }
}

void SensorsList::show(std::vector<Sensor*>* results) {
    
    sensors_list = results;
    show();
}
