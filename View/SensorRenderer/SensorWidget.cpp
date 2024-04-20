
#include <QVBoxLayout>
#include <QString>
#include "SensorWidgetVisitor.h"
#include "SensorWidget.h"

SensorWidget::SensorWidget(Sensor& sensor, QWidget* parent): QWidget(parent), sensor(sensor) {
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    
    
    QString city = QString::fromStdString(sensor.getCity());
    QString country = QString::fromStdString(sensor.getCountry());
    city_label = new QLabel("City: " + city);
    country_label = new QLabel("Country: " + country);
    layout->addWidget(city_label);
    layout->addWidget(country_label);
}
