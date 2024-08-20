#include "SensorEditorDialog.h"
#include "../../model/Temperature.h"
#include "../../model/Humidity.h"
#include "../../model/Rainfall.h"
#include "../../model/UV.h"
#include "HumidityEditor.h"
#include "RainfallEditor.h"
#include "TemperatureEditor.h"
#include "UVEditor.h"
#include "TypeSelector.h"
#include "SensorEditorDialogInjector.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>

SensorEditorDialog::SensorEditorDialog(
        MainWindow *mainWindow,
        Repository *repository,
        const Sensor* sensor
    ) 
        : mainWindow(mainWindow), sensor(sensor)
{
    if (sensor) {
        setWindowTitle("Edit Sensor");
    } else {
        setWindowTitle("New Sensor");
    }
    
    setFixedSize(300, 600);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel *title;
    if (sensor) {
        title = new QLabel("Change sensor's characteristics");
    } else {
        title = new QLabel("Create new sensor");
    }
    layout->addWidget(title);

    if (sensor == nullptr) {
        QLabel *id_warning = new QLabel("WARNING: If a sensor with this ID already exists, its data will be overwritten.");
        layout->addWidget(id_warning);
    }

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
    //formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    layout->addLayout(formLayout);

    id = new QSpinBox();
    id->setMinimum(1);
    id->setMaximum(1000000);
    if (sensor) {
        id->setValue(sensor->getId());
        id->setReadOnly(true);
    }
    formLayout->addRow("ID", id);
    
    city = new QLineEdit();
    if (sensor) {
        city->setText(QString::fromStdString(sensor->getCity()));
    }
    formLayout->addRow("City", city);
    
    country = new QLineEdit();
    if (sensor) {
        country->setText(QString::fromStdString(sensor->getCountry()));
    }
    formLayout->addRow("Country", country);

    type = new QComboBox();
    type->addItem("Temperature");
    type->addItem("Humidity");
    type->addItem("Rainfall");
    type->addItem("UV");
    if (sensor) {
        TypeSelector type_selector(type);
        sensor->accept(type_selector);
    }
    formLayout->addRow("Type", type);

    stackedLayout = new QStackedLayout();
    layout->addLayout(stackedLayout);

    TemperatureEditor *temperature_editor = new TemperatureEditor();
    stackedLayout->addWidget(temperature_editor);
    editors.push_back(temperature_editor);

    HumidityEditor *humidity_editor = new HumidityEditor();
    stackedLayout->addWidget(humidity_editor);
    editors.push_back(humidity_editor);

    RainfallEditor *rainfall_editor = new RainfallEditor();
    stackedLayout->addWidget(rainfall_editor);
    editors.push_back(rainfall_editor);

    UVEditor *uv_editor = new UVEditor();
    stackedLayout->addWidget(uv_editor);
    editors.push_back(uv_editor);

    if (sensor) {
        SensorEditorDialogInjector injector(
            *humidity_editor,
            *rainfall_editor,
            *temperature_editor,
            *uv_editor
        );
        sensor->accept(injector);
    }
    showTypeEditor(type->currentIndex());
    connect(type, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SensorEditorDialog::showTypeEditor);

    layout->addStretch();

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->addLayout(actions);

    QPushButton *okButton = new QPushButton("OK");
    actions->addWidget(okButton);
    connect(okButton, &QPushButton::clicked, this, &SensorEditorDialog::apply);
    
    QPushButton *cancelButton = new QPushButton("Cancel");
    actions->addWidget(cancelButton);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    
}

void SensorEditorDialog::showTypeEditor(int index) {
    stackedLayout->setCurrentIndex(index);
}

void SensorEditorDialog::apply() {
    int sensor_id = id->value();
    QString sensor_city = city->text().toLower();
    sensor_city[0] = sensor_city[0].toUpper();
    QString sensor_country = country->text();
    SensorEditor* editor = editors[stackedLayout->currentIndex()];
    Sensor* sensor = editor->create(sensor_id, sensor_city, sensor_country);
    mainWindow->getRepository()->update(sensor);
    mainWindow->reloadData();
    accept();
}
