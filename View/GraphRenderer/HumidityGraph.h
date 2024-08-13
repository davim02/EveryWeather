#ifndef HUMIDITYGRAPH_H
#define HUMIDITYGRAPH_H

#include "../../model/Humidity.h"
#include <QChart>

class HumidityGraph : public QChart {

private:
    const Humidity& humidity;

public:
    HumidityGraph(const Humidity& humidity);
};

#endif // HUMIDITYGRAPH_H
