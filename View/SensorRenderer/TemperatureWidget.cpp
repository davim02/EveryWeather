#include "TemperatureWidget.h"
#include <QVBoxLayout>

TemperatureWidget::TemperatureWidget(SensorWidget& sensor_widget, QWidget* parent): 
    SensorWidget(sensor_widget)
{
    QPixmap image(":assets/temperature.png");
    icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(80));
    label = new QLabel("Temperature");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(icon);
    layout->addWidget(label);
    setLayout(layout);
}

TemperatureWidget::~TemperatureWidget() {

}
