#include "SensorInfoWidget.h"
#include "SensorInfoWidgetVisitor.h"
#include <QVBoxLayout>

SensorInfoWidget::SensorInfoWidget(const Sensor& sensor, QWidget *parent)
    : QWidget{parent}, sensor{sensor}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    id_label = new QLabel("ID: " + QString::number(sensor.getId()));
    city_label = new QLabel("City: " + QString::fromStdString(sensor.getCity()));
    country_label = new QLabel("Country: " + QString::fromStdString(sensor.getCountry()));

    layout->addWidget(id_label);
    layout->addWidget(city_label);
    layout->addWidget(country_label);

    SensorInfoWidgetVisitor visitor;
    sensor.accept(visitor);
    layout->addWidget(visitor.getWidget());

    setMinimumSize(250, 120);
}
