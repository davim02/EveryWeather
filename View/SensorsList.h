#ifndef VIEW_SENSORS_LIST_H
#define VIEW_SENSORS_LIST_H

#include "../View/SensorRenderer/SensorWidget.h"
#include "../model/Sensor.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>


class SensorsList: public QWidget {
    Q_OBJECT
    private:
        std::vector<Sensor*>* sensors_list;
        QVBoxLayout* vlayout;
        QScrollArea* scroll_area;
        QLabel* no_results_label;

    public:
        explicit SensorsList(QWidget *parent = nullptr);
        void showNoResults();
    
    signals:
        void sensorSelected(const Sensor* sensor);
        void editSensor(const Sensor* sensor);
        void removeSensor(const unsigned int sensor_id);

    public slots:
        void show(std::vector<Sensor*>* results);
        void show();
        void clear();
};


#endif
