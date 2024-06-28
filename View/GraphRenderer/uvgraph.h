#ifndef UVGRAPH_H
#define UVGRAPH_H

#include <QChart>
#include "../../model/UV.h"

class UVGraph : public QChart
{
    Q_OBJECT

private:
    UV& uv;

public:
    UVGraph(UV& uv, QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
};

#endif // UVGRAPH_H
