#include "HumidityGraph.h"
#include "../../model/Simulation/HumiditySim.h"

#include <QApplication>
#include <QStyleHints>
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

    QPen pen;
    /*if (QApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark) {
        setTheme(QChart::ChartThemeDark);
        setBackgroundBrush(QBrush(QColor(0x31363b)));

        series->setBrush(QBrush(QGradient(QGradient::FlyHigh)));
        pen.setColor(QColor(0x6f86d6));
    } else {*/
        series->setBrush(QBrush(QGradient(QGradient::WinterNeva)));
        pen.setColor(QColor(0x63ace5));
    //}

    pen.setWidth(3);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    series->setPen(pen);

    legend()->hide();
}
