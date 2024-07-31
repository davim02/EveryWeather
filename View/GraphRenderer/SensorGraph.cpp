#include "SensorGraph.h"
#include "SensorGraphVisitor.h"
#include <iostream>

SensorGraph::SensorGraph(QWidget* parent): QWidget(parent) {
    
    chart_view = new QChartView(this);
    
    chart_view->setRenderHint(QPainter::Antialiasing);
    chart_view->setMinimumSize(700, 700);
    chart_view->setMaximumSize(700, 700);
}

void SensorGraph::setGraphSensor(const Sensor* sensor) {
    std::cout << "SensorGraph::setGraphSensor" << std::endl;
    //save chart pointer
    QChart* oldChart = chart_view->chart();

    //set the new chart
    SensorGraphVisitor visitor;
    sensor->accept(visitor);
    chart_view->setChart(visitor.getChart());

    //delete the old chart
    if(oldChart != nullptr) {
        oldChart->deleteLater();
    }
}
