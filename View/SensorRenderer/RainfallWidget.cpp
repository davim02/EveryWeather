#include "RainfallWidget.h"
#include <QVBoxLayout>

RainfallWidget::RainfallWidget(QWidget* parent): SensorWidget(parent)
{
    QPixmap image(":assets/rainfall.png");
    icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(80));
    label = new QLabel("Rainfall");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(icon);
    layout->addWidget(label);
    setLayout(layout);
}

RainfallWidget::~RainfallWidget() {

}

