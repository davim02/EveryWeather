
#include <QHBoxLayout>
#include <QString>
#include "SensorWidgetVisitor.h"
#include "SensorWidget.h"

SensorWidget::SensorWidget(const Sensor& sensor, QWidget* parent): QPushButton(parent), sensor(sensor) {
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    SensorWidgetVisitor visitor;
    sensor.accept(visitor);
    layout->addWidget(visitor.getWidget());
    
    city_label = new QLabel("City: " + QString::fromStdString(sensor.getCity()));
    country_label = new QLabel("Country: " + QString::fromStdString(sensor.getCountry()));
    id_label = new QLabel("ID: " + QString::number(sensor.getId()));
    layout->addWidget(city_label);
    layout->addWidget(country_label);
    layout->addWidget(id_label);

    setMinimumSize(250, 120);
}



