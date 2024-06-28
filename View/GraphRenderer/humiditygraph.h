#ifndef HUMIDITYGRAPH_H
#define HUMIDITYGRAPH_H

#include <QChart>
#include "../../model/Humidity.h"

class HumidityGraph : public QChart
{
    Q_OBJECT

private:
    Humidity& humidity;

public:
    HumidityGraph(Humidity& humidity, QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
};

#endif // HUMIDITYGRAPH_H
