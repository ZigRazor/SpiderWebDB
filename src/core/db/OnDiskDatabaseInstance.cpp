#include "OnDiskDatabaseInstance.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <sstream>

namespace SPIDERWEBDB
{

    OnDiskDatabaseInstance::OnDiskDatabaseInstance() : DatabaseInstance() {}

    OnDiskDatabaseInstance::OnDiskDatabaseInstance(std::string dbName): DatabaseInstance(dbName){}

    OnDiskDatabaseInstance::~OnDiskDatabaseInstance() {}

    void OnDiskDatabaseInstance::addRelations(std::shared_ptr<RelationsList> relations)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::addRelations(const RelationsList &relations)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::addRelation(std::shared_ptr<Relation> relation)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::addRelation(const Relation &relation)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::removeRelations(std::shared_ptr<RelationsList> relations)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::removeRelations(const RelationsList &relations)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::removeRelations(const std::string &relationsName)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::removeRelation(std::shared_ptr<Relation> relation)
    {
        //TODO
    }

    void OnDiskDatabaseInstance::removeRelation(const Relation &relation)
    {
        //TODO
    }

    int OnDiskDatabaseInstance::writeToFile() const
    {
        //TODO
        return 0;
    }

    int OnDiskDatabaseInstance::readFromFile()
    {
        //TODO
        return 0;
    }

    std::string OnDiskDatabaseInstance::toString() const
    {
        //TODO
        std::stringstream ss;
        return ss.str();
    }

}