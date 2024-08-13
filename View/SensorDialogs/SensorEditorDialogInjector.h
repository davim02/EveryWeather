#ifndef SENSOREDITORDIALOGINJECTOR_H
#define SENSOREDITORDIALOGINJECTOR_H

#include "../../model/SensorVisitorConstInterface.h"
#include "HumidityEditor.h"
#include "RainfallEditor.h"
#include "TemperatureEditor.h"
#include "UVEditor.h"

class SensorEditorDialogInjector : public SensorVisitorConstInterface {

    private:
        HumidityEditor& humidity_editor;
        RainfallEditor& rainfall_editor;
        TemperatureEditor& temperature_editor;
        UVEditor& uv_editor;

    public:
        SensorEditorDialogInjector(
            HumidityEditor& humidity_editor,
            RainfallEditor& rainfall_editor,
            TemperatureEditor& temperature_editor,
            UVEditor& uv_editor
        );
        
        virtual void visit(const Humidity& humidity);
        virtual void visit(const Rainfall& rainfall);
        virtual void visit(const Temperature& temperature);
        virtual void visit(const UV& uv);
};

#endif // SENSOREDITORDIALOGINJECTOR_H
