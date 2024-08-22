#ifndef JSON_H
#define JSON_H

#include "../Sensor.h"
#include "ReaderInterface.h"

#include <QJsonObject>

class Json {

    private:
        ReaderInterface& reader;
    
    public:
        Json(ReaderInterface& reader);
        const ReaderInterface& getReader() const;
        QJsonObject fromJsonObj(const Sensor& sensor) const;
        Sensor* toJsonObj(const QJsonObject& json_obj) const;
};

#endif
