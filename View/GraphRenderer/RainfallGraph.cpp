#include "RainfallGraph.h"
#include "../../model/Simulation/RainfallSim.h"

#include <QValueAxis>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>

RainfallGraph::RainfallGraph(const Rainfall& rainfall) : rainfall(rainfall) {

    RainfallSim rainfall_sim(rainfall);

    const std::vector<double>& rainfall_quantities = rainfall_sim.getData();

    auto set = new QBarSet("Months");

    for(unsigned int i=0; i<rainfall_quantities.size(); i++){
        *set << rainfall_quantities[i];
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
    if (rainfall.isInches()) {
        axisY->setRange(0, 20);
        axisY->setTitleText("Average Rainfall (in)");
    } else {
        axisY->setRange(0, 500);
        axisY->setTitleText("Average Rainfall (mm)");
    }
    
    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}
