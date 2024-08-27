#include "HumidityGraph.h"
#include "../../model/Simulation/HumiditySim.h"

#include <QLineSeries>
#include <QAreaSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

HumidityGraph::HumidityGraph(const Humidity& humidity) : humidity(humidity) {
    HumiditySim humidity_sim = HumiditySim(humidity);

    auto line_series = new QLineSeries;

    const std::vector<int>& percentages = humidity_sim.getData();

    for (int i = 0; i < 12; i++) {
        line_series->append(i, percentages[i]);
    }

    auto series = new QAreaSeries(line_series);

    addSeries(series);
    setTitle("Average humidity across the year");
    setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
    addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTitleText("Humidity");
    axisY->setLabelFormat("%i%");
    axisY->setTickCount(6);
    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QPen pen(0x63ace5);
    pen.setWidth(3);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0xadcbe3);
    gradient.setColorAt(1.0, 0xe7eff6);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);

    legend()->hide();
}
