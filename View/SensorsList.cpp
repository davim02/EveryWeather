#include "SensorsList.h"
#include "../View/SensorRenderer/SensorWidgetVisitor.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <functional>

SensorsList::SensorsList(Repository* repository, QWidget *parent)
    : QWidget(parent), repository(repository)
{
    QWidget* container = new QWidget(this);
    vlayout = new QVBoxLayout(container);
    vlayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QScrollArea* scroll_area = new QScrollArea(this);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);

    show();
}

void SensorsList::show() {

    std::vector<Sensor*> results = repository->getAll();
    
    for (std::vector<Sensor*>::const_iterator it = results.begin();
         it != results.end();
         it++
        )
    {
        SensorWidget* sensor_widget = new SensorWidget(**it);
        vlayout->addWidget(sensor_widget);
        connect(sensor_widget, &SensorWidget::clicked, std::bind(&SensorsList::sensorSelected, this, *it));
        //connect(sensor_widget, &SensorWidget::clicked, [=](){ emit sensorSelected(*it); });
    }

}

