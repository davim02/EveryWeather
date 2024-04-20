#include "UVWidget.h"
#include <QVBoxLayout>

UVWidget::UVWidget(QWidget* parent): SensorWidget(parent)
{
    QPixmap image(":assets/uv.png");
    icon = new QLabel();
    icon->setPixmap(image.scaledToHeight(80));
    label = new QLabel("UV");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(icon);
    layout->addWidget(label);
    setLayout(layout);
}

UVWidget::~UVWidget() {

}

