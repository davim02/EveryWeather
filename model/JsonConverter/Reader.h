#ifndef READER_H
#define READER_H

#include "ReaderInterface.h"

#include <QJsonObject>
#include <map>

class Reader : public ReaderInterface {
    private:
        std::map<unsigned int, Sensor*> cache;
        Sensor* readHumidity(const QJsonObject& json_obj) const;
        Sensor* readTemperature(const QJsonObject& json_obj) const;
        Sensor* readRainfall(const QJsonObject& json_obj) const;
        Sensor* readUV(const QJsonObject& json_obj) const;
    
    public:
        const std::map<unsigned int, Sensor*>& getCache() const;
        Reader& clear();
        virtual Sensor* read(const QJsonObject& json_obj);
};

#endif
