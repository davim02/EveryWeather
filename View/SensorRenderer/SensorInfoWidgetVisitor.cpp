#include "SensorInfoWidgetVisitor.h"
#include "model/Humidity.h"
#include "model/Rainfall.h"
#include "model/UV.h"
#include "model/Temperature.h"

#include <QLabel>
#include <QVBoxLayout>

QWidget* SensorInfoWidgetVisitor::getWidget()
{
    return widget;
}

void SensorInfoWidgetVisitor::visit(const Temperature& temperature) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QLabel* type_label = new QLabel("Type: Temperature");
    layout->addWidget(type_label);

    QLabel* unit_label;
    if (temperature.isFahrenheit()) {
        unit_label = new QLabel("Unit: Fahrenheit");
    } else {
        unit_label = new QLabel("Unit: Celsius");
    }

    layout->addWidget(unit_label);  
}

void SensorInfoWidgetVisitor::visit(const Humidity& humidity) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QLabel* type_label = new QLabel("Type: Humidity");
    layout->addWidget(type_label);
}

void SensorInfoWidgetVisitor::visit(const Rainfall& rainfall) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QLabel* type_label = new QLabel("Type: Rainfall");
    layout->addWidget(type_label);

    QLabel* unit_label;
    if (rainfall.isInches()) {
        unit_label = new QLabel("Unit: Inches");
    } else {
        unit_label = new QLabel("Unit: Millimeters");
    }

    layout->addWidget(unit_label);
}

void SensorInfoWidgetVisitor::visit(const UV& uv) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QLabel* type_label = new QLabel("Type: UV");
    layout->addWidget(type_label);
}
