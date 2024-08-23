#include "UVGraph.h"
#include "../../model/Simulation/UVSim.h"

#include <QLineSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

UVGraph::UVGraph(const UV& uv) : uv(uv) {
    UVSim uv_sim(uv);

    const std::vector<unsigned int>& uv_values = uv_sim.getData();

    auto series = new QLineSeries;

    for(int i=0; i<12; i++) {
        series->append(i, uv_values[i]);
    }

    addSeries(series);
    setTitle("average UV indexes across the months");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
    addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 12);
    axisY->setTitleText("UV index");
    axisY->setTickCount(13);
    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    legend()->hide();
}
