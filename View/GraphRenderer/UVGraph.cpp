#include "UVGraph.h"
#include "../../model/Simulation/UVSim.h"

#include <QLineSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QLinearGradient>

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

    QLinearGradient lineGradient;
    lineGradient.setStart(QPointF(0, 0));
    lineGradient.setFinalStop(QPointF(0, 1));
    lineGradient.setColorAt(0.0, QColor(0xca2c92));
    lineGradient.setColorAt(0.11, QColor(0xff0900));
    lineGradient.setColorAt(0.30, QColor(0xff9200));
    lineGradient.setColorAt(0.47, Qt::yellow);
    lineGradient.setColorAt(0.52, Qt::yellow);
    lineGradient.setColorAt(0.73, QColor(0x00ff00));
    lineGradient.setColorAt(1.0, QColor(0x009900));
    lineGradient.setCoordinateMode(QGradient::StretchToDeviceMode);
    series->setPen(QPen(QBrush(lineGradient), 5));


    legend()->hide();
}
