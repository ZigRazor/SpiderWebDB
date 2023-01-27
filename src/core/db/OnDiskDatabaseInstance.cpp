#include "OnDiskDatabaseInstance.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <sstream>

namespace SPIDERWEBDB
{

    OnDiskDatabaseInstance::OnDiskDatabaseInstance() : DatabaseInstance() {}

    OnDiskDatabaseInstance::OnDiskDatabaseInstance(const std::string& dbName) : DatabaseInstance(dbName) {
        //Create DB Directory if not exist
        struct stat sb;
        if (stat(dbName.c_str(), &sb) != 0)
        {
            mkdir(dbName.c_str(), 0777);
        }
    }

    OnDiskDatabaseInstance::~OnDiskDatabaseInstance() {}

    void OnDiskDatabaseInstance::addRelations(std::shared_ptr<RelationsList> relations)
    {
        writeRelationsToFile(*relations);
    }

    void OnDiskDatabaseInstance::addRelations(const RelationsList &relations)
    {
        writeRelationsToFile(relations);
    }

    void OnDiskDatabaseInstance::addRelation(std::shared_ptr<Relation> relation)
    {
        writeRelationToFile(*relation);
    }

    void OnDiskDatabaseInstance::addRelation(const Relation &relation)
    {
        writeRelationToFile(relation);
    }

    void OnDiskDatabaseInstance::removeRelations(std::shared_ptr<RelationsList> relations)
    {
        // TODO
    }

    void OnDiskDatabaseInstance::removeRelations(const RelationsList &relations)
    {
        // TODO
    }

    void OnDiskDatabaseInstance::removeRelations(const std::string &relationsName)
    {
        // TODO
    }

    void OnDiskDatabaseInstance::removeRelation(std::shared_ptr<Relation> relation)
    {
        // TODO
    }

    void OnDiskDatabaseInstance::removeRelation(const Relation &relation)
    {
        // TODO
    }

    int OnDiskDatabaseInstance::writeToFile() const
    {
        // TODO
        return 0;
    }

    int OnDiskDatabaseInstance::readFromFile()
    {
        // TODO
        return 0;
    }

    std::string OnDiskDatabaseInstance::toString() const
    {
        // TODO
        std::stringstream ss;
        return ss.str();
    }

    int OnDiskDatabaseInstance::writeRelationToFile(const Relation& relation) const
    {
        std::ofstream relationsFile;
        std::string relationsName = "relations_" + std::string(relation.getName());
        for (const auto &entry : std::filesystem::directory_iterator(getName()))
        {

            if (entry.path().filename().string() == relationsName)
            {
                relationsFile.open(entry.path().string(), std::ios_base::app);
            }
        }
        if (!relationsFile.is_open())
        {
            relationsFile.open(std::string(getName()) + "/" + relationsName + ".csv");
        }

        auto nodes = relation.getNodes();
        relationsFile << *nodes.first << "," << *nodes.second << std::endl;

        relationsFile.close();
        return 0;
    }

    int OnDiskDatabaseInstance::writeRelationsToFile(const RelationsList& relations) const
    {
        std::ofstream relationsFile;
        std::string relationsName = "relations_" + std::string(relations.getRelationsName());
        for (const auto &entry : std::filesystem::directory_iterator(getName()))
        {

            if (entry.path().filename().string() == relationsName)
            {
                relationsFile.open(entry.path().string(), std::ios_base::app);
            }
        }
        if (!relationsFile.is_open())
        {
            relationsFile.open(std::string(getName()) + "/" + relationsName + ".csv");
        }
        for (auto relation : relations.getRelations())
        {
            auto nodes = relation->getNodes();
            relationsFile << *nodes.first << "," << *nodes.second << std::endl;
        }
        relationsFile.close();

        return 0;
    }

}