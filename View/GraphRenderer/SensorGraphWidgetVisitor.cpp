#include "SensorGraphWidgetVisitor.h"
#include "../../model/Humidity.h"
#include "../../model/Rainfall.h"
#include "../../model/Temperature.h"
#include "../../model/UV.h"
#include "TemperatureGraph.h"
#include "HumidityGraph.h"
#include "RainfallGraph.h"
#include "UVGraph.h"


QChart* SensorGraphWidgetVisitor::getChart() const {
    return chart;
}

void SensorGraphWidgetVisitor::visit(const Temperature& temperature) {
    chart = new TemperatureGraph(temperature);
}

void SensorGraphWidgetVisitor::visit(const Humidity& humidity) {
    chart = new HumidityGraph(humidity);
}

void SensorGraphWidgetVisitor::visit(const Rainfall& rainfall) {
    chart = new RainfallGraph(rainfall);
}

void SensorGraphWidgetVisitor::visit(const UV& uv) {
    chart = new UVGraph(uv);
}
