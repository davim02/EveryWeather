#include "JsonVisitor.h"
#include <QJsonArray>

QJsonObject JsonVisitor::getJsonObj() const {
    return json_obj;
}

void JsonVisitor::visit(const Humidity& humidity) {
    QJsonObject humidity_obj;
    humidity_obj.insert("type", QJsonValue::fromVariant("humidity"));
    humidity_obj.insert("id", QJsonValue::fromVariant(humidity.getId()));
    humidity_obj.insert("city", QJsonValue::fromVariant(humidity.getCity().c_str()));
    humidity_obj.insert("country", QJsonValue::fromVariant(humidity.getCountry().c_str()));
    json_obj = humidity_obj;
}

void JsonVisitor::visit(const Temperature& temperature) {
    QJsonObject temperature_obj;
    temperature_obj.insert("type", QJsonValue::fromVariant("temperature"));
    temperature_obj.insert("id", QJsonValue::fromVariant(temperature.getId()));
    temperature_obj.insert("city", QJsonValue::fromVariant(temperature.getCity().c_str()));
    temperature_obj.insert("country", QJsonValue::fromVariant(temperature.getCountry().c_str()));
    temperature_obj.insert("isFahrenheit", QJsonValue::fromVariant(temperature.isFahrenheit()));
    json_obj = temperature_obj;
}

void JsonVisitor::visit(const Rainfall& rainfall) {
    QJsonObject rainfall_obj;
    rainfall_obj.insert("type", QJsonValue::fromVariant("rainfall"));
    rainfall_obj.insert("id", QJsonValue::fromVariant(rainfall.getId()));
    rainfall_obj.insert("city", QJsonValue::fromVariant(rainfall.getCity().c_str()));
    rainfall_obj.insert("country", QJsonValue::fromVariant(rainfall.getCountry().c_str()));
    rainfall_obj.insert("isInches", QJsonValue::fromVariant(rainfall.isInches()));  
    json_obj = rainfall_obj;
}

void JsonVisitor::visit(const UV& uv) {
    QJsonObject uv_obj;
    uv_obj.insert("type", QJsonValue::fromVariant("uv"));
    uv_obj.insert("id", QJsonValue::fromVariant(uv.getId()));
    uv_obj.insert("city", QJsonValue::fromVariant(uv.getCity().c_str()));
    uv_obj.insert("country", QJsonValue::fromVariant(uv.getCountry().c_str()));
    json_obj = uv_obj;
}