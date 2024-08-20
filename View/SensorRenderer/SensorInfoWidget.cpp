#include "SensorInfoWidget.h"
#include "SensorInfoWidgetVisitor.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

SensorInfoWidget::SensorInfoWidget(const Sensor& sensor, QWidget *parent)
    : QWidget{parent}, sensor{sensor}
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QVBoxLayout* first_column = new QVBoxLayout();
    id_label = new QLabel("ID: " + QString::number(sensor.getId()));
    city_label = new QLabel("City: " + QString::fromStdString(sensor.getCity()));
    country_label = new QLabel("Country: " + QString::fromStdString(sensor.getCountry()));
    first_column->addWidget(id_label);
    first_column->addWidget(city_label);
    first_column->addWidget(country_label);
    layout->addLayout(first_column);

    SensorInfoWidgetVisitor visitor;
    sensor.accept(visitor);
    layout->addWidget(visitor.getWidget());

    setMinimumSize(250, 90);
    setMaximumHeight(90);
}
