#ifndef HUMIDITYEDITOR_H
#define HUMIDITYEDITOR_H

#include "SensorEditor.h"

class HumidityEditor : public SensorEditor {
    public:
        HumidityEditor(QWidget *parent = nullptr);
        virtual ~HumidityEditor();
        Sensor* create(
            const unsigned int id,
            const QString& city,
            const QString& country
        ) const override;

        void setValues(const Humidity& humidity);
};

#endif // HUMIDITYEDITOR_H
