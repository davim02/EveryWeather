#ifndef SENSOREDITOR_H
#define SENSOREDITOR_H

#include "../../model/Sensor.h"
#include <QWidget>
#include <QString>

class SensorEditor : public QWidget {
    Q_OBJECT

    public:
        SensorEditor(QWidget *parent = nullptr);
        virtual ~SensorEditor();
        virtual Sensor* create(
            const unsigned int id,
            const QString& city,
            const QString& country
        ) const = 0;

};

#endif // SENSOREDITOR_H
