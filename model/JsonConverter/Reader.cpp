#include "Reader.h"
#include "../Humidity.h"
#include "../Temperature.h"
#include "../Rainfall.h"
#include "../UV.h"

#include <stdexcept>
#include <QJsonArray>


Sensor* Reader::readHumidity(const QJsonObject& json_obj) const {
    return new Humidity(
        json_obj.value("id").toInt(), 
        json_obj.value("city").toString().toStdString(), 
        json_obj.value("country").toString().toStdString()
    );
}

Sensor* Reader::readTemperature(const QJsonObject& json_obj) const {
    return new Temperature(
        json_obj.value("id").toInt(), 
        json_obj.value("city").toString().toStdString(), 
        json_obj.value("country").toString().toStdString(),
        json_obj.value("isFahrenheit").toBool()
    );
}

Sensor* Reader::readRainfall(const QJsonObject& json_obj) const {
    return new Rainfall(
        json_obj.value("id").toInt(), 
        json_obj.value("city").toString().toStdString(), 
        json_obj.value("country").toString().toStdString(),
        json_obj.value("isInches").toBool()
    );
}

Sensor* Reader::readUV(const QJsonObject& json_obj) const {
    return new UV(
        json_obj.value("id").toInt(), 
        json_obj.value("city").toString().toStdString(), 
        json_obj.value("country").toString().toStdString()
    );
}

const std::map<unsigned int, Sensor*>& Reader::getCache() const {
    return cache;
}

Reader& Reader::clear() {
    cache.clear();
    return *this;
}

Sensor* Reader::read(const QJsonObject& json_obj) {
    QJsonValue type = json_obj.value("type");
    if (type.isUndefined()) {
        throw std::invalid_argument("Sensor type is missing");
    }
    const unsigned int id = json_obj.value("id").toInt();
    if (cache.count(id) > 0) {  // if sensor is already in cache
        return cache[id];
    
    } else if (type.toString().compare("humidity") == 0) {
        cache[id] = readHumidity(json_obj);
    
    } else if (type.toString().compare("temperature") == 0) {
        cache[id] = readTemperature(json_obj);
    
    } else if (type.toString().compare("rainfall") == 0) {
        cache[id] = readRainfall(json_obj);
    
    } else if (type.toString().compare("uv") == 0) {
        cache[id] = readUV(json_obj);
    
    } else {
        throw std::invalid_argument("Unknown sensor type");
    }
    return cache[id];
}
