#include "SensorGraphVisitor.h"
#include "humiditygraph.h"
#include "temperaturegraph.h"
#include "uvgraph.h"
#include "rainfallgraph.h"
#include <QLineSeries>
#include <QValueAxis>


QChart* SensorGraphVisitor::getChart() {
    return chart;
}

void SensorGraphVisitor::visit(const Temperature& temperature) {
    chart = new TemperatureGraph(temperature);
    
}

void SensorGraphVisitor::visit(const Humidity& humidity) {
    chart = new HumidityGraph(humidity);

}

void SensorGraphVisitor::visit(const Rainfall& rainfall) {
    chart = new RainfallGraph(rainfall);

}

void SensorGraphVisitor::visit(const UV& uv) {
    chart = new UVGraph(uv);

}
