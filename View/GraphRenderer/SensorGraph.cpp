#include "SensorGraph.h"
#include "SensorGraphVisitor.h"
#include <iostream>
#include <QChart>
#include <QVBoxLayout>
#include <QPushButton>

SensorGraph::SensorGraph(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout = new QVBoxLayout(this);

    QPushButton* button = new QPushButton("Simulate sensor", this);
    layout->addWidget(button);
    
    chart_view = new QChartView(this);
    chart_view->setRenderHint(QPainter::Antialiasing);
    chart_view->setMinimumSize(600, 500);
    layout->addWidget(chart_view);

}

void SensorGraph::setGraph(const Sensor* sensor) {
    //save chart pointer
    QChart* oldChart = chart_view->chart();

    //set the new chart
    SensorGraphVisitor visitor;
    sensor->accept(visitor);
    chart_view->setChart(visitor.getChart());

    //delete the old chart
    if(oldChart) {
        std::cout << "old chart deleted" << std::endl;
        oldChart->deleteLater();
    }
}
