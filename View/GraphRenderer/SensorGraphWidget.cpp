#include "SensorGraphWidget.h"
#include "SensorGraphWidgetVisitor.h"
#include <iostream>
#include <QChart>
#include <QVBoxLayout>

SensorGraphWidget::SensorGraphWidget(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setDirection(QBoxLayout::BottomToTop);

    chart_view = new QChartView(this);
    chart_view->setRenderHint(QPainter::Antialiasing);
    chart_view->setMinimumSize(600, 500);
    layout->addWidget(chart_view);
    
    button = new QPushButton("Simulate sensor", this);
    button->setEnabled(false);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &SensorGraphWidget::simulateSensor);

}

void SensorGraphWidget::setSensor(const Sensor* sensor) {
    this->sensor = sensor;
    sensor_info = new SensorInfoWidget(*sensor);
    sensor_info->setMinimumSize(600, 100);
    layout->addWidget(sensor_info);
    button->setEnabled(true);
}

void SensorGraphWidget::setGraph() {
    //save chart pointer
    QChart* oldChart = chart_view->chart();

    //set the new chart
    SensorGraphWidgetVisitor visitor;
    sensor->accept(visitor);
    chart_view->setChart(visitor.getChart());

    //delete the old chart
    if(oldChart) {
        std::cout << "old chart deleted" << std::endl;
        oldChart->deleteLater();
    }
}

void SensorGraphWidget::simulateSensor() {
    setGraph();
}
