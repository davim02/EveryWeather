#include "SensorGraphWidget.h"
#include "SensorGraphWidgetVisitor.h"
#include <iostream>
#include <QChart>
#include <QLayoutItem>

SensorGraphWidget::SensorGraphWidget(QWidget* parent): QWidget(parent) {

    layout = new QVBoxLayout(this);
    layout->setDirection(QBoxLayout::BottomToTop);

    chart_view = new QChartView(this);
    isChartSet = false;
    chart_view->setRenderHint(QPainter::Antialiasing);
    chart_view->setMinimumSize(500, 400);
    layout->addWidget(chart_view);
    
    button = new QPushButton("Simulate sensor", this);
    button->setEnabled(false);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &SensorGraphWidget::simulateSensor);

}

const Sensor* SensorGraphWidget::getSensor() const {
    return sensor;
}

void SensorGraphWidget::deleteInfoWidget() {
    QLayoutItem *child = layout->takeAt(2);
    if (child != nullptr) {
        std::cout << "old sensor info deleted" << std::endl;
        delete child->widget();
        delete child;
        button->setEnabled(false);
    }
}

void SensorGraphWidget::setSensor(const Sensor* sensor) {
    deleteInfoWidget();
    this->sensor = sensor;
    sensor_info = new SensorInfoWidget(*sensor);
    layout->addWidget(sensor_info);
    button->setEnabled(true);
}

void SensorGraphWidget::deleteChart() {

    if(isChartSet) {
        QChart* oldChart = chart_view->chart();
        std::cout << "old chart deleted" << std::endl;
        oldChart->deleteLater();
        isChartSet = false;
    }
}

void SensorGraphWidget::setChart() {
    deleteChart();
    SensorGraphWidgetVisitor visitor;
    sensor->accept(visitor);
    chart_view->setChart(visitor.getChart());
    isChartSet = true;
}

void SensorGraphWidget::simulateSensor() {
    setChart();
}

void SensorGraphWidget::reset() {
    deleteInfoWidget();
    //deleteChart();
}
