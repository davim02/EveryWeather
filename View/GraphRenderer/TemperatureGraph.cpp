#include "TemperatureGraph.h"
#include "../../model/Simulation/TemperatureSim.h"

#include <QLineseries>
#include <QBarCategoryAxis>
#include <QValueAxis>



TemperatureGraph::TemperatureGraph(const Temperature& temperature) : temperature(temperature) {
    TemperatureSim temperature_sim = TemperatureSim(temperature);

    QLineSeries* low = new QLineSeries();
    low->setName("Min");
    //low->setLabelColor(QColor(0, 0, 255));
    low->setColor(QColor(0, 0, 255));
    QLineSeries* high = new QLineSeries();
    high->setName("Max");
    //high->setLabelColor(QColor(255, 0, 0));
    high->setColor(QColor(255, 0, 0));

    const std::vector<int>& min_temp = temperature_sim.getMinTemp();
    const std::vector<int>& max_temp = temperature_sim.getMaxTemp();

    for(int i=0; i<12; i++){
        low->append(i, min_temp[i]);
        high->append(i, max_temp[i]);
    }

    addSeries(low);
    addSeries(high);

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
