#include "TemperatureGraph.h"
#include "../../model/Simulation/TemperatureSim.h"

#include <QValueAxis>
#include <QBarSet>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>


TemperatureGraph::TemperatureGraph(const Temperature& temperature) : temperature(temperature) {
    TemperatureSim temperature_sim = TemperatureSim(temperature);

    auto low = new QBarSet("Min");
    low->setLabelColor(QColor(0, 0, 255));
    low->setColor(QColor(0, 0, 255));
    auto high = new QBarSet("Max");
    high->setLabelColor(QColor(255, 0, 0));
    high->setColor(QColor(255, 0, 0));

    const std::vector<int>& min_temp = temperature_sim.getMinTemp();
    const std::vector<int>& max_temp = temperature_sim.getMaxTemp();

    for(int i=0; i<12; i++){
        *low << min_temp[i];
        *high << max_temp[i];
    }

    auto series = new QStackedBarSeries;
    series->append(low);
    series->append(high);

    addSeries(series);
    setTitle("Average temperatures over the year");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    addAxis(axisX, Qt::AlignBottom);
    auto axisY = new QValueAxis;
    if (temperature.isFahrenheit()) {
        axisY->setRange(-60, 125);
        axisY->setTitleText("Temperature [&deg;F]");
    } else {
        axisY->setRange(-52, 52);
        axisY->setTitleText("Temperature [&deg;C]");
    }
    
    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignRight);
    
}
