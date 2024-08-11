#include "UVGraph.h"
#include "../../model/Simulation/UVSim.h"

#include <QLineSeries>

UVGraph::UVGraph(const UV& uv) : uv(uv) {
    UVSim uv_sim(uv);

    uv_values = uv_sim.getData();

    auto series = new QLineSeries;

    for(int i=0; i<12; i++) {
        series->append(++i, uv_values[i]);
    }

    legend()->hide();
    addSeries(series);
    createDefaultAxes();
    setTitle("UV levels");
}
