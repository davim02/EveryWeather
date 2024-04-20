#include "HumidityWidget.h"
#include <QVBoxLayout>

HumidityWidget::HumidityWidget(QWidget* parent): SensorWidget(parent)
{
    QPixmap image(":assets/humidity.png");
    icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(80));
    label = new QLabel("Humidity");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(icon);
    layout->addWidget(label);
    setLayout(layout);
}

HumidityWidget::~HumidityWidget() {

}

