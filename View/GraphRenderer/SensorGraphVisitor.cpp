#include "SensorGraphVisitor.h"

#include <QLineSeries>
#include <QValueAxis>
#include <QBarSet>
#include <QBarSeries>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>
#include <QAreaSeries>

#include "../../model/Humidity.h"
#include "../../model/Rainfall.h"
#include "../../model/Temperature.h"
#include "../../model/UV.h"

QChart* SensorGraphVisitor::getChart() const {
    return chart;
}

SensorGraphVisitor::SensorGraphVisitor() {}

void SensorGraphVisitor::visit(const Temperature& temperature) {
    chart = new QChart();

    auto low = new QBarSet("Min");
    auto high = new QBarSet("Max");

    auto minTempVector = temperature.getMinTemp();
    auto maxTempVector = temperature.getMaxTemp();

    for(int i=0; i<12; i++){
        *low << minTempVector[i];
        *high << maxTempVector[i];
    }


    auto series = new QStackedBarSeries;
    series->append(low);
    series->append(high);

    chart->addSeries(series);
    chart->setTitle("Temperature records in Celcius");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    axisX->setTitleText("Month");
    chart->addAxis(axisX, Qt::AlignBottom);
    auto axisY = new QValueAxis;
    axisY->setRange(-52, 52);
    axisY->setTitleText("Temperature [&deg;C]");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    
}

void SensorGraphVisitor::visit(const Humidity& humidity) {
    chart = new QChart();

    auto line_series = new QLineSeries;

    auto dataVector = humidity.getData();

    for (int i = 0; i < 12; i++) {
        line_series->append(i, dataVector[i]);
    }

    auto series = new QAreaSeries(line_series);
    series->setName("Percentage of Humidity (%)");

    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);

    chart->addSeries(series);
    chart->setTitle("Humidity");
    chart->createDefaultAxes();

}

void SensorGraphVisitor::visit(const Rainfall& rainfall) {
    chart = new QChart();

    auto set = new QBarSet("Months");

    auto dataVector = rainfall.getData();

    for(int i=0; i<dataVector.size(); i++){
        *set << dataVector[i];
    }

    QBarSeries *series = new QBarSeries;
    series->append(set);

    chart->addSeries(series);
    chart->setTitle("Rainfall");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
    axisX->setTitleText("Month");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTitleText("Rainfall (mm)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

}

void SensorGraphVisitor::visit(const UV& uv) {
    chart = new QChart();

    auto series = new QLineSeries;

    auto data = uv.getData();

    for(int i=0; i<12; i++) {
        series->append(++i, data[i]);
    }

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("UV levels");

}
