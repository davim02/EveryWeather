#include "TemperatureGraph.h"
#include "../../model/Simulation/TemperatureSim.h"

#include <QApplication>
#include <QStyleHints>
#include <QLineSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>


TemperatureGraph::TemperatureGraph(const Temperature& temperature) : temperature(temperature) {
    TemperatureSim temperature_sim = TemperatureSim(temperature);

    QLineSeries* low = new QLineSeries();
    low->setName("Min");
    QPen pen_low = low->pen();
    pen_low.setWidth(3);
    pen_low.setColor(QColor(0x63ace5));
    low->setPen(pen_low);

    QLineSeries* high = new QLineSeries();
    high->setName("Max");
    QPen pen_high = high->pen();
    pen_high.setWidth(3);
    pen_high.setColor(QColor(0xff0000));
    high->setPen(pen_high);

    const std::vector<int>& min_temp = temperature_sim.getMinTemp();
    const std::vector<int>& max_temp = temperature_sim.getMaxTemp();

    for(int i=0; i<12; i++){
        low->append(i, min_temp[i]);
        high->append(i, max_temp[i]);
    }

    if (QApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark) {
        setTheme(QChart::ChartThemeDark);
        setBackgroundBrush(QBrush(QColor(0x31363b)));
    }

    addSeries(high);
    addSeries(low);
    setTitle("Average temperatures over the year");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    addAxis(axisX, Qt::AlignBottom);
    low->attachAxis(axisX);
    high->attachAxis(axisX);

    auto axisY = new QValueAxis;
    if (temperature.isFahrenheit()) {
        axisY->setRange(20, 100);
        axisY->setTitleText("Temperature [&deg;F]");
    } else {
        axisY->setRange(-10, 40);
        axisY->setTitleText("Temperature [&deg;C]");
    }
    addAxis(axisY, Qt::AlignLeft);
    low->attachAxis(axisY);
    high->attachAxis(axisY);

    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignRight);
    
}
