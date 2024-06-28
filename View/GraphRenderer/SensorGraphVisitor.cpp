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

void SensorGraphVisitor::visitTemperature(Temperature& temperature) {
    chart = new TemperatureGraph(temperature);
    
}

void SensorGraphVisitor::visitHumidity(Humidity& humidity) {
    chart = new HumidityGraph(humidity);

}

void SensorGraphVisitor::visitRainfall(Rainfall& rainfall) {
    chart = new RainfallGraph(rainfall);

}

void SensorGraphVisitor::visitUV(UV& uv) {
    chart = new UVGraph(uv);

}
