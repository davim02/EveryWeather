#ifndef JSON_REPOSITORY_H
#define JSON_REPOSITORY_H

#include <string>
#include <map>
#include "RepositoryInterface.h"
#include "../JsonFileIO/JsonFile.h"

class JsonRepository : public RepositoryInterface {
    private:
        JsonFile data_mapper;
        std::map<unsigned int, Sensor*> repository;

    public:
        JsonRepository(JsonFile data_mapper);
        virtual ~JsonRepository();
        static JsonRepository fromPath(const std::string filepath);
        const JsonFile& getDataMapper() const;
        const std::map<unsigned int, Sensor*>& getRepository() const;
        const std::string& getFilepath() const;
        JsonRepository& setFilepath(std::string filepath);

        virtual JsonRepository& add(Sensor* sensor);
        virtual JsonRepository& remove(const unsigned int id);
        virtual JsonRepository& update(Sensor* sensor);
        virtual Sensor* get(const unsigned int id) const;
        virtual std::vector<Sensor*> getAll() const;
        std::vector<Sensor*> search(const std::string& city) const;
        std::vector<Sensor*> search(const unsigned int id) const;
        JsonRepository& store();
};


#endif
