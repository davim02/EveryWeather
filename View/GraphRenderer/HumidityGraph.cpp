#include "HumidityGraph.h"
#include "../../model/Simulation/HumiditySim.h"

#include <QLineSeries>
#include <QAreaSeries>

HumidityGraph::HumidityGraph(const Humidity& humidity) : humidity(humidity) {
    HumiditySim humidity_sim = HumiditySim();

    auto line_series = new QLineSeries;

    percentages = humidity_sim.getData();

    for (int i = 0; i < 12; i++) {
        line_series->append(i, percentages[i]);
    }

    auto series = new QAreaSeries(line_series);
    series->setName("Percentage of Humidity (%)");

    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);

    addSeries(series);
    setTitle("Humidity");
    createDefaultAxes();
}
