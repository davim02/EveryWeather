#ifndef JSON_FILE_H
#define JSON_FILE_H

#include "../Sensor.h"
#include "../JsonConverter/Json.h"

#include <string>
#include <vector>

class JsonFile {
    private:
        std::string filepath;
        Json& json_converter;
        
    public:
        JsonFile(const std::string& filepath, Json& json_converter);
        static JsonFile fromPath(const std::string& filepath);
        const std::string& getFilepath() const;
        JsonFile& setFilepath(const std::string& filepath);
        const Json& getJsonConverter() const;
        JsonFile& save(const std::vector<Sensor*> sensors);
        std::vector<Sensor*> load();
};

#endif
