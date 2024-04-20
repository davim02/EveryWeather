#include "SensorWidgetVisitor.h"
#include "TemperatureWidget.h"
#include "HumidityWidget.h"
#include "RainfallWidget.h"
#include "UVWidget.h"

QWidget* SensorWidgetVisitor::getWidget() {
    return widget;
}

void SensorWidgetVisitor::visitTemperature(Temperature& temperature) {
    widget = new TemperatureWidget(temperature);
}

void SensorWidgetVisitor::visitHumidity(Humidity& humidity) {
    widget = new HumidityWidget(humidity);
}

void SensorWidgetVisitor::visitRainfall(Rainfall& rainfall) {
    widget = new RainfallWidget(rainfall);
}

void SensorWidgetVisitor::visitUV(UV& uv) {
    widget = new UVWidget(uv);
}