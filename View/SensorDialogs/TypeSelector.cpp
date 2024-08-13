#include "TypeSelector.h"

TypeSelector::TypeSelector(QComboBox* combo_box) : combo_box(combo_box) {}

void TypeSelector::visit(const Humidity& humidity) {
    (void) humidity;
    combo_box->setCurrentText("Humidity");
}

void TypeSelector::visit(const Rainfall& rainfall) {
    (void) rainfall;
    combo_box->setCurrentText("Rainfall");
}

void TypeSelector::visit(const Temperature& temperature) {
    (void) temperature;
    combo_box->setCurrentText("Temperature");
}

void TypeSelector::visit(const UV& uv) {
    (void) uv;
    combo_box->setCurrentText("UV");
}

QComboBox* TypeSelector::getComboBox() {
    return combo_box;
}

TypeSelector& TypeSelector::setComboBox(QComboBox* combo_box) {
    this->combo_box = combo_box;
    return *this;
}
