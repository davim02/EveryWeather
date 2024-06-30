#include "temperaturegraph.h"
#include <QBarSet>
#include <QBarSeries>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>


TemperatureGraph::TemperatureGraph(const Temperature& temperature, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags)
{

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

    addSeries(series);
    setTitle("Temperature records in Celcius");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    axisX->setTitleText("Month");
    addAxis(axisX, Qt::AlignBottom);
    auto axisY = new QValueAxis;
    axisY->setRange(-52, 52);
    axisY->setTitleText("Temperature [&deg;C]");
    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    this->legend()->setVisible(true);
    this->legend()->setAlignment(Qt::AlignBottom);
}
