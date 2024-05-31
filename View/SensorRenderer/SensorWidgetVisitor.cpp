#include "SensorWidgetVisitor.h"
#include <QLabel>
#include <QVBoxLayout>
#include "model/Humidity.h"
#include "model/Rainfall.h"
#include "model/UV.h"
#include "model/Temperature.h"

QWidget* SensorWidgetVisitor::getWidget() {
    return widget;
}

void SensorWidgetVisitor::visitTemperature(Temperature& temperature) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPixmap image(":assets/temperature.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(50));
    layout->addWidget(icon);

    QLabel* type_label = new QLabel("Temperature");
    layout->addWidget(type_label);
}

void SensorWidgetVisitor::visitHumidity(Humidity& humidity) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPixmap image(":assets/humidity.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(50));
    layout->addWidget(icon);

    QLabel* type_label = new QLabel("Humidity");
    layout->addWidget(type_label);
}

void SensorWidgetVisitor::visitRainfall(Rainfall& rainfall) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPixmap image(":assets/rainfall.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(50));
    layout->addWidget(icon);

    QLabel* type_label = new QLabel("Rainfall");
    layout->addWidget(type_label);
}

void SensorWidgetVisitor::visitUV(UV& uv) {
    widget = new QWidget();

    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPixmap image(":assets/uv.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(50));
    layout->addWidget(icon);

    QLabel* type_label = new QLabel("UV");
    layout->addWidget(type_label);

}
