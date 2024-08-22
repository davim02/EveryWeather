#include "Json.h"
#include "JsonVisitor.h"

Json::Json(ReaderInterface& reader) : reader(reader) {}

const ReaderInterface& Json::getReader() const {
    return reader;
}

QJsonObject Json::fromJsonObj(const Sensor& sensor) const {
    JsonVisitor visitor;
    sensor.accept(visitor);
    return visitor.getJsonObj();
}

Sensor* Json::toJsonObj(const QJsonObject& json_obj) const {
    return reader.read(json_obj);
}