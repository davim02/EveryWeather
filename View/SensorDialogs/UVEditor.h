#ifndef UVEDITOR_H
#define UVEDITOR_H

#include "SensorEditor.h"

class UVEditor : public SensorEditor {
    public:
        UVEditor(QWidget *parent = nullptr);
        virtual ~UVEditor();
        Sensor* create(
            const unsigned int id,
            const QString& city,
            const QString& country
        ) const override;

        void setValues(const UV& uv);
};

#endif // UVEDITOR_H
