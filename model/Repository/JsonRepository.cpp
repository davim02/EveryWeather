#include "JsonRepository.h"
#include "../JsonConverter/Reader.h"
#include "../JsonConverter/Json.h"
#include <stdexcept>

JsonRepository::JsonRepository(JsonFile data_mapper) 
    : data_mapper(data_mapper) 
{
    std::vector<Sensor*> sensors(data_mapper.load());
    for (Sensor* sensor : sensors) {
        repository[sensor->getId()] = sensor;
    }
}

JsonRepository::~JsonRepository() {
    for (
        std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); 
        it != repository.end(); 
        it++
    ) {
        delete it->second;
    }
}

JsonRepository JsonRepository::fromPath(const std::string filepath) {
    Reader reader;
    Json json_converter(reader);
    JsonFile data_mapper(filepath, json_converter);
    return JsonRepository(data_mapper);
}

const JsonFile& JsonRepository::getDataMapper() const {
    return data_mapper;
}

const std::map<unsigned int, Sensor*>& JsonRepository::getRepository() const {
    return repository;
}

const std::string& JsonRepository::getFilepath() const {
    return data_mapper.getFilepath();
}

JsonRepository& JsonRepository::setFilepath(std::string filepath) {
    data_mapper.setFilepath(filepath);
    return *this;
}

JsonRepository& JsonRepository::add(Sensor* sensor) {
    repository[sensor->getId()] = sensor;
    return *this;
}

JsonRepository& JsonRepository::remove(const unsigned int id) {
    std::map<unsigned int, Sensor*>::const_iterator it = repository.find(id);

    if(it != repository.end()) {
        delete it->second;
        repository.erase(it);
    }
    return *this;
}

JsonRepository& JsonRepository::update(Sensor* sensor) {
    add(sensor);

    return *this;   
}

Sensor* JsonRepository::get(const unsigned int id) const {
    std::map<unsigned int, Sensor*>::const_iterator it = repository.find(id);

    if(it == repository.end()) {
        throw std::out_of_range("No sensor with id " + std::to_string(id) + " found");
    }

    return it->second;
}

std::vector<Sensor*> JsonRepository::getAll() const {
    std::vector<Sensor*> sensors;

    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        sensors.push_back(it->second);
    }
    return sensors;
}

std::vector<Sensor*> JsonRepository::search(const std::string& city) const {
    std::vector<Sensor*> result;
    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        if ((it->second)->getCity().find(city) != std::string::npos) {
            result.push_back(it->second);
        }
    }
    return result;
}

std::vector<Sensor*> JsonRepository::search(const unsigned int id) const {
    std::vector<Sensor*> result;
    std::string id_str = std::to_string(id);
    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        if (std::to_string((it->first)).find(id_str) != std::string::npos) {
            result.push_back(it->second);
        }
    }
    return result;
}

JsonRepository& JsonRepository::store() {
    std::vector<Sensor*> sensors(getAll());
    data_mapper.save(sensors);
    return *this;
}
