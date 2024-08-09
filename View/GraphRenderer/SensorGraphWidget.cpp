#include "SensorGraphWidget.h"
#include "SensorGraphWidgetVisitor.h"
#include <iostream>
#include <QChart>
#include <QVBoxLayout>
#include <QPushButton>

SensorGraphWidget::SensorGraphWidget(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout = new QVBoxLayout(this);

    QWudget* sensor_info = new QWidget(this);   //make a visitor for this
    QHBoxLayout* sensor_info_layout = new QHBoxLayout(sensor_info);
    sensor_info_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->addWidget(sensor_info);

    QLabel* city_label = new QLabel("City: ");
    sensor_info_layout->addWidget(city_label);
    QLabel* city_value = new QLabel();
    sensor_info_layout->addWidget(city_value);

    QLabel* country_label = new QLabel("Country: ");
    sensor_info_layout->addWidget(country_label);
    QLabel* country_value = new QLabel();
    sensor_info_layout->addWidget(country_value);

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
    SensorGraphWidgetVisitor visitor;
    sensor->accept(visitor);
    chart_view->setChart(visitor.getChart());

    //delete the old chart
    if(oldChart) {
        std::cout << "old chart deleted" << std::endl;
        oldChart->deleteLater();
    }
}
