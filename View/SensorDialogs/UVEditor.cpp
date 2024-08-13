#include "UVEditor.h"
#include "../../model/UV.h"
#include <QFormLayout>

UVEditor::UVEditor(QWidget* parent) : SensorEditor(parent) {
    // FOR FUTURE IMPLEMENTATION
}

UVEditor::~UVEditor() {}

Sensor* UVEditor::create(const unsigned int id, const QString& city, const QString& country) const {
    return new UV(id, city.toStdString(), country.toStdString());
}

void UVEditor::setValues(const UV& uv) {
    // FOR FUTURE IMPLEMENTATION
}