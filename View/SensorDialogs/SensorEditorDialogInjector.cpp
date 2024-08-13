#include "SensorEditorDialogInjector.h"

SensorEditorDialogInjector::SensorEditorDialogInjector(
    HumidityEditor& humidity_editor,
    RainfallEditor& rainfall_editor,
    TemperatureEditor& temperature_editor,
    UVEditor& uv_editor
) : humidity_editor(humidity_editor), 
    rainfall_editor(rainfall_editor), 
    temperature_editor(temperature_editor), 
    uv_editor(uv_editor) 
{}

void SensorEditorDialogInjector::visit(const Humidity& humidity) {
    humidity_editor.setValues(humidity);
}

void SensorEditorDialogInjector::visit(const Rainfall& rainfall) {
    rainfall_editor.setValues(rainfall);
}

void SensorEditorDialogInjector::visit(const Temperature& temperature) {
    temperature_editor.setValues(temperature);
}

void SensorEditorDialogInjector::visit(const UV& uv) {
    uv_editor.setValues(uv);
}
