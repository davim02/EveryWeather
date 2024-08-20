#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <map>
#include "RepositoryInterface.h"

class Repository : public RepositoryInterface {
    private:
        std::map<unsigned int, Sensor*> repository;

    public:
        Repository();
        virtual ~Repository();
        virtual Repository& add(Sensor* sensor);
        virtual Repository& remove(const unsigned int id);
        virtual Repository& update(Sensor* sensor);
        Repository& clear();
        virtual Sensor* get(const unsigned int id) const;
        virtual std::vector<Sensor*> getAll() const;
        std::vector<Sensor*> search(const std::string& city) const;
        std::vector<Sensor*> search(const unsigned int id) const;
        void saveToFile(const std::string& filename) const;
};


#endif
