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

void SensorWidgetVisitor::visit(const Temperature& temperature) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QPixmap image(":assets/temperature.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(45));
    layout->addWidget(icon);
    layout->setAlignment(icon, Qt::AlignLeft | Qt::AlignTop);

    QLabel* type_label = new QLabel("Temperature");
    layout->addWidget(type_label);
    layout->setAlignment(type_label, Qt::AlignHCenter);
}

void SensorWidgetVisitor::visit(const Humidity& humidity) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QPixmap image(":assets/humidity.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(45));
    layout->addWidget(icon);
    layout->setAlignment(icon, Qt::AlignLeft | Qt::AlignTop);

    QLabel* type_label = new QLabel("Humidity");
    layout->addWidget(type_label);
    layout->setAlignment(type_label, Qt::AlignHCenter);
}

void SensorWidgetVisitor::visit(const Rainfall& rainfall) {
    widget = new QWidget();
    
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QPixmap image(":assets/rainfall.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(45));
    layout->addWidget(icon);
    layout->setAlignment(icon, Qt::AlignLeft | Qt::AlignTop);

    QLabel* type_label = new QLabel("Rainfall");
    layout->addWidget(type_label);
    layout->setAlignment(type_label, Qt::AlignHCenter);
}

void SensorWidgetVisitor::visit(const UV& uv) {
    widget = new QWidget();

    QVBoxLayout* layout = new QVBoxLayout(widget);

    QPixmap image(":assets/uv.png");
    QLabel* icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(45));
    layout->addWidget(icon);
    layout->setAlignment(icon, Qt::AlignLeft | Qt::AlignTop);

    QLabel* type_label = new QLabel("UV");
    layout->addWidget(type_label);
    layout->setAlignment(type_label, Qt::AlignHCenter);
}
