#include "RainfallEditor.h"
#include "../../model/Rainfall.h"
#include <QFormLayout>
#include <QHBoxLayout>

RainfallEditor::RainfallEditor(QWidget* parent) : SensorEditor(parent) {
    
    QFormLayout *layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout *button_group = new QHBoxLayout();
    button_group->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mm = new QRadioButton("mm", this);
    inches = new QRadioButton("inches", this);
    button_group->addWidget(mm);
    button_group->addWidget(inches);

    layout->addRow("Measurement Unit", button_group);
}

RainfallEditor::~RainfallEditor() {}

Sensor* RainfallEditor::create(const unsigned int id, const QString& city, const QString& country) const {
    return new Rainfall(id, city.toStdString(), country.toStdString(), inches->isChecked());
}

void RainfallEditor::setValues(const Rainfall& rainfall) {
    if (rainfall.isInches()) {
        inches->setChecked(true);
    } else {
        mm->setChecked(true);
    }
}