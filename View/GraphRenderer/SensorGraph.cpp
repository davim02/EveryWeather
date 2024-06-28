#include "SensorGraph.h"
#include "SensorGraphVisitor.h"

SensorGraph::SensorGraph(QWidget* parent): QWidget(parent) {
    
    chart_view = new QChartView(this);
    
    chart_view->setRenderHint(QPainter::Antialiasing);
    chart_view->setMinimumSize(400, 300);
    chart_view->setMaximumSize(400, 300);
}

void SensorGraph::setGraphSensor(Sensor& sensor) {
    SensorGraphVisitor visitor;
    sensor.accept(visitor);
    chart_view->setChart(visitor.getChart());
}
