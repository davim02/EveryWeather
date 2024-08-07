#ifndef REPOSITORY_INTERFACE_H
#define REPOSITORY_INTERFACE_H

#include <vector>
#include "../Sensor.h"

class RepositoryInterface {
    public:
        virtual ~RepositoryInterface() = default;
        virtual RepositoryInterface& add(Sensor* sensor) = 0;
        virtual RepositoryInterface& remove(const unsigned int id) = 0;
        virtual RepositoryInterface& update(Sensor* sensor) = 0;
        virtual Sensor* get(const unsigned int id) const = 0;
        virtual std::vector<Sensor*> getAll() const = 0;
        
};

#endif