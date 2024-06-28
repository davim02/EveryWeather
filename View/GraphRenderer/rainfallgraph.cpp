#include "rainfallgraph.h"
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

RainfallGraph::RainfallGraph(Rainfall& rainfall, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags),
    rainfall(rainfall)
{
    auto set = new QBarSet("Months");

    auto dataVector = rainfall.getData();

    for(int i=0; i<dataVector.size(); i++){
        *set << dataVector[i];
    }

    QBarSeries *series = new QBarSeries;
    series->append(set);

    addSeries(series);
    setTitle("Rainfall");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
    axisX->setTitleText("Month");
    addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTitleText("Rainfall (mm)");
    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    this->legend()->setVisible(true);
    this->legend()->setAlignment(Qt::AlignBottom);
}
