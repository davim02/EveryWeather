#include "RainfallGraph.h"
#include "../../model/Simulation/RainfallSim.h"

#include <QApplication>
#include <QStyleHints>
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

    /*if (QApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark) {
        setTheme(QChart::ChartThemeDark);
        setBackgroundBrush(QBrush(QColor(0x31363b)));
    }*/
    addSeries(series);
    setTitle("Average rainfall across the year");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
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

    set->setColor(QColor(0x63ace5));

    legend()->setVisible(false);
}
