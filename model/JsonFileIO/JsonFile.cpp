#include "JsonFile.h"
#include "../JsonConverter/Reader.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

JsonFile::JsonFile(const std::string& filepath, Json& json_converter) 
    : filepath(filepath), json_converter(json_converter) 
{}

JsonFile JsonFile::fromPath(const std::string& filepath) {
    Reader reader;
    Json json(reader);
    return JsonFile(filepath, json);
}

const std::string& JsonFile::getFilepath() const {
    return filepath;
}

JsonFile& JsonFile::setFilepath(const std::string& filepath) {
    this->filepath = filepath;
    return *this;
}

const Json& JsonFile::getJsonConverter() const {
    return json_converter;
}

JsonFile& JsonFile::save(const std::vector<Sensor*> sensors) {
    QJsonArray json_array;
    for (Sensor* sensor : sensors) {
        json_array.push_back(json_converter.fromJsonObj(*sensor));
    }

    QFile json_file(QString::fromStdString(filepath));
    if (!json_file.open(QIODevice::WriteOnly)) {
        std::cerr << "Error: could not open file " << filepath << " for writing" << std::endl;
        return *this;
    }

    QJsonDocument json_doc(json_array);
    json_file.write(json_doc.toJson());
    json_file.close();

    return *this;
}

std::vector<Sensor*> JsonFile::load() {
    QFile json_file(QString::fromStdString(filepath));
    if (!json_file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error: could not open file " << filepath << " for reading" << std::endl;
        return std::vector<Sensor*>();
    }

    QJsonDocument json_doc = QJsonDocument::fromJson(json_file.readAll());
    json_file.close();

    std::vector<Sensor*> sensors;
    QJsonArray json_array = json_doc.array();
    for (const QJsonValue& json_val : json_array) {
        sensors.push_back(json_converter.toJsonObj(json_val.toObject()));
    }

    return sensors;
}
