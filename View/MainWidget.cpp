#include "MainWidget.h"
#include "GraphRenderer/SensorGraph.h"
#include <QHBoxLayout>
#include "SensorsList.h"

MainWidget::MainWidget(Repository *repository, QWidget *parent): QWidget(parent), repository(repository)
{
    
    QHBoxLayout *layout = new QHBoxLayout(this);

    SensorsList *sensors_list = new SensorsList(repository, this);
    layout->addWidget(sensors_list);

    SensorGraph *sensor_graph = new SensorGraph(this);
    layout->addWidget(sensor_graph);

    connect(sensors_list, &SensorsList::sensorSelected, sensor_graph, &SensorGraph::setGraphSensor);

    setLayout(layout);

    setMinimumSize(700, 400);

    setBackgroundRole(QPalette::Light);

}
