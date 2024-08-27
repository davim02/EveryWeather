#include "SensorsList.h"
#include "../View/SensorRenderer/SensorWidgetVisitor.h"
#include <QGridLayout>
#include <QLayoutItem>
#include <functional>
#include <iostream>

SensorsList::SensorsList(QWidget *parent)
    : QWidget(parent)
{
    setFixedWidth(300);

    QGridLayout* layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    no_results_label = new QLabel("No results found");
    no_results_label->hide();
    layout->addWidget(no_results_label, 0, 0, 1, 1);

    QWidget* container = new QWidget();
    vlayout = new QVBoxLayout(container);
    vlayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    vlayout->setContentsMargins(1, 1, 1, 1);

    scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);

    layout->addWidget(scroll_area, 0, 0, 1, 1);
}

void SensorsList::clear() {
    QLayoutItem* child;
    while ((child = vlayout->takeAt(0)) != nullptr) {

        delete child->widget();
        delete child;
    }
}

void SensorsList::show() {
    clear();
    if (no_results_label->isVisible()) {
        no_results_label->hide();
        scroll_area->show();
    }

    for (std::vector<Sensor*>::const_iterator it = sensors_list->begin();
         it != sensors_list->end();
         it++
        )
    {
        SensorWidget* sensor_widget = new SensorWidget(**it);
        vlayout->addWidget(sensor_widget);
        connect(sensor_widget, &SensorWidget::clicked, std::bind(&SensorsList::sensorSelected, this, *it));
        connect(sensor_widget, &SensorWidget::edit, this, &SensorsList::editSensor);
        connect(sensor_widget, &SensorWidget::remove, this, &SensorsList::removeSensor);
    }
}

void SensorsList::show(std::vector<Sensor*>* results) {
    sensors_list = results;
    show();
}

void SensorsList::showNoResults() {
    std::cout << "no results found" << std::endl;
    scroll_area->hide();
    no_results_label->show();
}
